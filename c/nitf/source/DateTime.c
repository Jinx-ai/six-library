/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 *
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include "nitf/DateTime.h"


#ifdef WIN32
NITFPRIV(char*) _nitf_strptime(const char *buf, const char *fmt, struct tm *tm);
#endif

NITFAPI(nitf_DateTime*) nitf_DateTime_now(nitf_Error *error)
{
    return nitf_DateTime_fromMillis(nitf_Utils_getCurrentTimeMillis(), error);
}

NITFAPI(nitf_DateTime*) nitf_DateTime_fromMillis(double millis,
        nitf_Error *error)
{
    time_t timeInSeconds;
    struct tm t;
    nitf_DateTime *dt = NULL;

    timeInSeconds = (time_t)(millis / 1000);
    t = *gmtime(&timeInSeconds);

    dt = (nitf_DateTime*)NITF_MALLOC(sizeof(nitf_DateTime));
    if (!dt)
    {
        nitf_Error_init(error, NITF_STRERROR(NITF_ERRNO),
                NITF_CTXT, NITF_ERR_MEMORY);
        return NULL;
    }

    dt->timeInMillis = millis;

    /* this is the year since 1900 */
    dt->year = t.tm_year + 1900;

    /* 0-based so add 1 */
    dt->month = t.tm_mon + 1;
    dt->dayOfMonth = t.tm_mday;
    dt->dayOfWeek = t.tm_wday + 1;
    dt->dayOfYear = t.tm_yday + 1;
    dt->hour = t.tm_hour;
    dt->minute = t.tm_min;
    dt->second = t.tm_sec + (millis / 1000.0 - timeInSeconds);

    return dt;
}

NITFPRIV(time_t) nitf_DateTime_timegm(struct tm *t)
{
    time_t tl, tb;
    struct tm *tg;

    tl = mktime (t);
    if (tl == -1)
    {
        t->tm_hour--;
        tl = mktime (t);
        if (tl == -1)
        return -1; /* can't deal with output from strptime */
        tl += 3600;
    }
    tg = gmtime (&tl);
    tg->tm_isdst = 0;
    tb = mktime (tg);
    if (tb == -1)
    {
        tg->tm_hour--;
        tb = mktime (tg);
        if (tb == -1)
        return -1; /* can't deal with output from gmtime */
        tb += 3600;
    }
    return (tl - (tb - tl));
}

NITFAPI(nitf_DateTime*) nitf_DateTime_fromString(const char* string,
        const char* format, nitf_Error *error)
{
    struct tm t;

#ifdef WIN32
    if (!_nitf_strptime(string, format, &t))
#else
    if (!strptime(string, format, &t))
#endif
    {
        nitf_Error_initf(error, NITF_CTXT, NITF_ERR_INVALID_OBJECT,
                "Unknown error caused by the call to strptime with format string: [%s]",
                format);
        return NULL;
    }
    return nitf_DateTime_fromMillis((double)nitf_DateTime_timegm(&t) * 1000, error);
}

NITFAPI(void) nitf_DateTime_destruct(nitf_DateTime **dt)
{
    if (*dt)
    {
        NITF_FREE(*dt);
        *dt = NULL;
    }
}

NITFAPI(NITF_BOOL) nitf_DateTime_format(nitf_DateTime *dateTime,
        const char* format, char* outBuf, size_t maxSize, nitf_Error *error)
{
    return nitf_DateTime_formatMillis(dateTime->timeInMillis,
            format, outBuf, maxSize, error);
}

NITFAPI(NITF_BOOL) nitf_DateTime_formatMillis(double millis,
        const char* format, char* outBuf, size_t maxSize, nitf_Error *error)
{
    time_t timeInSeconds;
    struct tm t;

    timeInSeconds = (time_t)(millis / 1000);
    t = *gmtime(&timeInSeconds);

    if (strftime(outBuf, maxSize, format, &t) == 0)
    {
        nitf_Error_initf(error, NITF_CTXT, NITF_ERR_INVALID_OBJECT,
                "Unknown error caused by the call to strftime with format string: [%s]",
                format);
        return NITF_FAILURE;
    }
    return NITF_SUCCESS;
}

#ifdef WIN32
//http://social.msdn.microsoft.com/forums/en-US/vcgeneral/thread/25a654f9-b6b6-490a-8f36-c87483bb36b7

/*
 * We do not implement alternate representations. However, we always
 * check whether a given modifier is allowed for a certain conversion.
 */
#define ALT_E          0x01
#define ALT_O          0x02
//#define LEGAL_ALT(x)       { if (alt_format & ~(x)) return (0); }
#define LEGAL_ALT(x)       { ; }
#define TM_YEAR_BASE   (1900) /* changed from 1970 */

static const char *day[7] = { "Sunday", "Monday", "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday" };
static const char
        *abday[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
static const char *mon[12] = { "January", "February", "March", "April", "May",
                               "June", "July", "August", "September",
                               "October", "November", "December" };
static const char *abmon[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
static const char *am_pm[2] = { "AM", "PM" };

NITFPRIV(int) _nitf_convNum(const char **, int *, int, int);

NITFPRIV(char*) _nitf_strptime(const char *buf, const char *fmt, struct tm *tm)
{
    char c;
    const char *bp;
    size_t len = 0;
    int alt_format, i, split_year = 0;

    bp = buf;

    /* init */
    tm->tm_sec = tm->tm_min = tm->tm_hour = tm->tm_mday =
    tm->tm_mon = tm->tm_year = tm->tm_wday =
    tm->tm_yday = tm->tm_isdst = 0;

    while ((c = *fmt) != '\0')
    {
        /* Clear `alternate' modifier prior to new conversion. */
        alt_format = 0;

        /* Eat up white-space. */
        if (isspace(c))
        {
            while (isspace(*bp))
                bp++;

            fmt++;
            continue;
        }

        if ((c = *fmt++) != '%')
        goto literal;

        again: switch (c = *fmt++)
        {
            case '%': /* "%%" is converted to "%". */
            literal:
                if (c != *bp++)
                    return NULL;
                break;

            /*
             * "Alternative" modifiers. Just set the appropriate flag
             * and start over again.
             */
            case 'E': /* "%E?" alternative conversion modifier. */
            LEGAL_ALT(0);
                alt_format |= ALT_E;
                goto again;

            case 'O': /* "%O?" alternative conversion modifier. */
            LEGAL_ALT(0);
                alt_format |= ALT_O;
                goto again;

            /*
             * "Complex" conversion rules, implemented through recursion.
             */
            case 'c': /* Date and time, using the locale's format. */
            LEGAL_ALT(ALT_E);
                if (!(bp = _nitf_strptime(bp, "%x %X", tm)))
                    return NULL;
                break;

            case 'D': /* The date as "%m/%d/%y". */
            LEGAL_ALT(0);
                if (!(bp = _nitf_strptime(bp, "%m/%d/%y", tm)))
                    return NULL;
                break;

            case 'R': /* The time as "%H:%M". */
            LEGAL_ALT(0);
                if (!(bp = _nitf_strptime(bp, "%H:%M", tm)))
                    return NULL;
                break;

            case 'r': /* The time in 12-hour clock representation. */
            LEGAL_ALT(0);
                if (!(bp = _nitf_strptime(bp, "%I:%M:%S %p", tm)))
                    return NULL;
                break;

            case 'T': /* The time as "%H:%M:%S". */
            LEGAL_ALT(0);
                if (!(bp = _nitf_strptime(bp, "%H:%M:%S", tm)))
                    return NULL;
                break;

            case 'X': /* The time, using the locale's format. */
            LEGAL_ALT(ALT_E);
                if (!(bp = _nitf_strptime(bp, "%H:%M:%S", tm)))
                    return NULL;
                break;

            case 'x': /* The date, using the locale's format. */
            LEGAL_ALT(ALT_E);
                if (!(bp = _nitf_strptime(bp, "%m/%d/%y", tm)))
                    return NULL;
                break;

            /*
             * "Elementary" conversion rules.
             */
            case 'A': /* The day of week, using the locale's form. */
            case 'a':
            LEGAL_ALT(0);
                for (i = 0; i < 7; i++)
                {
                    /* Full name. */
                    len = strlen(day[i]);
                    if (nitf_Utils_strncasecmp((char *)(day[i]), (char *)bp, len) == 0)
                        break;

                    /* Abbreviated name. */
                    len = strlen(abday[i]);
                    if (nitf_Utils_strncasecmp((char *)(abday[i]), (char *)bp, len) == 0)
                        break;
                }

                /* Nothing matched. */
                if (i == 7)
                    return NULL;

                tm->tm_wday = i;
                bp += len;
                break;

            case 'B': /* The month, using the locale's form. */
            case 'b':
            case 'h':
            LEGAL_ALT(0);
                for (i = 0; i < 12; i++)
                {
                    /* Full name. */
                    len = strlen(mon[i]);
                    if (nitf_Utils_strncasecmp((char *)(mon[i]), (char *)bp, len) == 0)
                        break;

                    /* Abbreviated name. */
                    len = strlen(abmon[i]);
                    if (nitf_Utils_strncasecmp((char *)(abmon[i]),(char *) bp, len) == 0)
                        break;
                }

                /* Nothing matched. */
                if (i == 12)
                    return NULL;

                tm->tm_mon = i;
                bp += len;
                break;

            case 'C': /* The century number. */
            LEGAL_ALT(ALT_E);
                if (!(_nitf_convNum(&bp, &i, 0, 99)))
                    return NULL;

                if (split_year)
                {
                    tm->tm_year = (tm->tm_year % 100) + (i * 100);
                }
                else
                {
                    tm->tm_year = i * 100;
                    split_year = 1;
                }
                break;

            case 'd': /* The day of month. */
            case 'e':
            LEGAL_ALT(ALT_O);
                if (!(_nitf_convNum(&bp, &tm->tm_mday, 1, 31)))
                    return NULL;
                break;

            case 'k': /* The hour (24-hour clock representation). */
            LEGAL_ALT(0);
            /* FALLTHROUGH */
            case 'H':
            LEGAL_ALT(ALT_O);
                if (!(_nitf_convNum(&bp, &tm->tm_hour, 0, 23)))
                    return NULL;
                break;

            case 'l': /* The hour (12-hour clock representation). */
            LEGAL_ALT(0);
            /* FALLTHROUGH */
            case 'I':
            LEGAL_ALT(ALT_O);
                if (!(_nitf_convNum(&bp, &tm->tm_hour, 1, 12)))
                    return NULL;
                if (tm->tm_hour == 12)
                    tm->tm_hour = 0;
                break;

            case 'j': /* The day of year. */
            LEGAL_ALT(0);
                if (!(_nitf_convNum(&bp, &i, 1, 366)))
                    return NULL;
                tm->tm_yday = i - 1;
                break;

            case 'M': /* The minute. */
            LEGAL_ALT(ALT_O);
                if (!(_nitf_convNum(&bp, &tm->tm_min, 0, 59)))
                    return NULL;
                break;

            case 'm': /* The month. */
            LEGAL_ALT(ALT_O);
                if (!(_nitf_convNum(&bp, &i, 1, 12)))
                    return NULL;
                tm->tm_mon = i - 1;
                break;

            //            case 'p': /* The locale's equivalent of AM/PM. */
            //                LEGAL_ALT(0);
            //                /* AM? */
            //                if (strcasecmp(am_pm[0], bp) == 0)
            //                {
            //                    if (tm->tm_hour > 11)
            //                        return NULL;
            //
            //                    bp += strlen(am_pm[0]);
            //                    break;
            //                }
            //                /* PM? */
            //                else if (strcasecmp(am_pm[1], bp) == 0)
            //                {
            //                    if (tm->tm_hour > 11)
            //                        return NULL;
            //
            //                    tm->tm_hour += 12;
            //                    bp += strlen(am_pm[1]);
            //                    break;
            //                }
            //
            //                /* Nothing matched. */
            //                return NULL;

            case 'S': /* The seconds. */
            LEGAL_ALT(ALT_O);
                if (!(_nitf_convNum(&bp, &tm->tm_sec, 0, 61)))
                    return NULL;
                break;

            case 'U': /* The week of year, beginning on sunday. */
            case 'W': /* The week of year, beginning on monday. */
            LEGAL_ALT(ALT_O);
                /*
                 * XXX This is bogus, as we can not assume any valid
                 * information present in the tm structure at this
                 * point to calculate a real value, so just check the
                 * range for now.
                 */
                if (!(_nitf_convNum(&bp, &i, 0, 53)))
                    return NULL;
                break;

            case 'w': /* The day of week, beginning on sunday. */
            LEGAL_ALT(ALT_O);
                if (!(_nitf_convNum(&bp, &tm->tm_wday, 0, 6)))
                    return NULL;
                break;

            case 'Y': /* The year. */
            LEGAL_ALT(ALT_E);
                i = TM_YEAR_BASE;
                if (!(_nitf_convNum(&bp, &i, 0, 9999)))
                    return NULL;
                tm->tm_year = i - TM_YEAR_BASE;
                break;

            case 'y': /* The year within 100 years of the epoch. */
            LEGAL_ALT(ALT_E | ALT_O);
                if (!(_nitf_convNum(&bp, &i, 0, 99)))
                    return NULL;

                if (split_year)
                {
                    tm->tm_year = ((tm->tm_year / 100) * 100) + i;
                    break;
                }
                split_year = 1;
                if (i <= 68)
                    tm->tm_year = i + 2000 - TM_YEAR_BASE;
                else
                    tm->tm_year = i + 1900 - TM_YEAR_BASE;
                break;
            /*
             * Miscellaneous conversions.
             */
            case 'n': /* Any kind of white-space. */
            case 't':
            LEGAL_ALT(0);
                while (isspace(*bp))
                    bp++;
                break;

            default: /* Unknown/unsupported conversion. */
                return NULL;
        }

    }

    /* LINTED functional specification */
    return ((char *)bp);
}

static int _nitf_convNum(const char **buf, int *dest, int llim, int ulim)
{
    int result = 0;

    /* The limit also determines the number of valid digits. */
    int rulim = ulim;

    if (**buf < '0' || **buf > '9')
        return (0);

    do
    {
        result *= 10;
        result += *(*buf)++ - '0';
        rulim /= 10;
    }
    while ((result * 10 <= ulim) && rulim && **buf >= '0' && **buf <= '9');

    if (result < llim || result > ulim)
        return (0);

    *dest = result;
    return (1);
}
#endif