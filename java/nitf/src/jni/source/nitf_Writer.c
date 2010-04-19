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

#include <import/nitf.h>
#include "nitf_Writer.h"
#include "nitf_JNI.h"

NITF_JNI_DECLARE_OBJ(nitf_Writer)
/*
 * Class:     nitf_Writer
 * Method:    construct
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_construct
    (JNIEnv * env, jobject self)
{
    nitf_Writer *writer;
    nitf_Error error;

    writer = nitf_Writer_construct(&error);
    _SetObj(env, self, writer);
}


/*
 * Class:     nitf_Writer
 * Method:    destructMemory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_destructMemory
    (JNIEnv * env, jobject self)
{
    nitf_Writer *writer = _GetObj(env, self);
    if (writer)
        nitf_Writer_destruct(&writer);
    _SetObj(env, self, NULL);
}


/*
 * Class:     nitf_Writer
 * Method:    getImageWriters
 * Signature: ()[Lnitf/ImageWriter;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Writer_getImageWriters
    (JNIEnv * env, jobject self)
{
    nitf_Writer *writer = _GetObj(env, self);
    jint numWriters;
    jint i;
    jobject imageWriter;
    jobjectArray writers;
    jclass imageWriterClass = (*env)->FindClass(env, "nitf/ImageWriter");
    jmethodID initMethodID =
        (*env)->GetMethodID(env, imageWriterClass, "<init>", "(J)V");
    jmethodID methodID = (*env)->GetMethodID(env, imageWriterClass,
                                             "setManaged", "(Z)V");

    numWriters = writer->numImageWriters;
    writers =
        (*env)->NewObjectArray(env, numWriters, imageWriterClass, NULL);

    for (i = 0; i < numWriters; i++)
    {
        imageWriter = (*env)->NewObject(env,
                                        imageWriterClass,
                                        initMethodID,
                                        (jlong) writer->imageWriters[i]);

        /* tell Java not to manage the ImageSource memory */
        (*env)->CallVoidMethod(env, imageWriter, methodID, JNI_FALSE);

        (*env)->SetObjectArrayElement(env, writers, i, imageWriter);
    }

    return writers;
}


/*
 * Class:     nitf_Writer
 * Method:    getNumImageWriters
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nitf_Writer_getNumImageWriters
    (JNIEnv * env, jobject self)
{
    nitf_Writer *writer = _GetObj(env, self);
    return writer->numImageWriters;
}


/*
 * Class:     nitf_Writer
 * Method:    getTextWriters
 * Signature: ()[Lnitf/SegmentWriter;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Writer_getTextWriters
  (JNIEnv *env, jobject self)
{
	nitf_Writer *writer = _GetObj(env, self);
    jint numWriters;
    jint i;
    jobject segmentWriter;
    jobjectArray writers;
    jclass segmentWriterClass = (*env)->FindClass(env, "nitf/SegmentWriter");
    jmethodID initMethodID =
        (*env)->GetMethodID(env, segmentWriterClass, "<init>", "(J)V");
    jmethodID methodID = (*env)->GetMethodID(env, segmentWriterClass,
                                             "setManaged", "(Z)V");

    numWriters = writer->numTextWriters;
    writers =
        (*env)->NewObjectArray(env, numWriters, segmentWriterClass, NULL);

    for (i = 0; i < numWriters; i++)
    {
        segmentWriter = (*env)->NewObject(env,
                                          segmentWriterClass,
                                          initMethodID,
                                          (jlong) writer->textWriters[i]);

        /* tell Java not to manage the ImageSource memory */
        (*env)->CallVoidMethod(env, segmentWriter, methodID, JNI_FALSE);

        (*env)->SetObjectArrayElement(env, writers, i, segmentWriter);
    }

    return writers;
}


/*
 * Class:     nitf_Writer
 * Method:    getNumTextWriters
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nitf_Writer_getNumTextWriters
  (JNIEnv *env, jobject self)
{
    nitf_Writer *writer = _GetObj(env, self);
    return writer->numTextWriters;
}


/*
 * Class:     nitf_Writer
 * Method:    getOutput
 * Signature: ()Lnitf/IOInterface;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getOutput
    (JNIEnv * env, jobject self)
{
    nitf_Writer *writer = _GetObj(env, self);
    jclass ioClass = (*env)->FindClass(env, "nitf/NativeIOInterface");
    jmethodID methodID = (*env)->GetMethodID(env, ioClass, "<init>", "(J)V");
    return (*env)->NewObject(env, ioClass, methodID, (jlong) writer->output);
}


/*
 * Class:     nitf_Writer
 * Method:    getRecord
 * Signature: ()Lnitf/Record;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getRecord
    (JNIEnv * env, jobject self)
{
    nitf_Writer *writer = _GetObj(env, self);
    jclass recordClass = (*env)->FindClass(env, "nitf/Record");

    jmethodID methodID =
        (*env)->GetMethodID(env, recordClass, "<init>", "(J)V");
    jobject handle = (*env)->NewObject(env,
                                       recordClass,
                                       methodID,
                                       (jlong) writer->record);

    /* tell Java not to manage the ImageSource memory */
    methodID = (*env)->GetMethodID(env, recordClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, handle, methodID, JNI_FALSE);

    return handle;
}


/*
 * Class:     nitf_Writer
 * Method:    prepareIO
 * Signature: (Lnitf/Record;Lnitf/IOInterface;)Z
 */
JNIEXPORT jboolean JNICALL Java_nitf_Writer_prepareIO
    (JNIEnv * env, jobject self, jobject recordObject,
     jobject ioObject)
{
    nitf_Writer *writer = _GetObj(env, self);
    jclass recordClass = (*env)->FindClass(env, "nitf/Record");
    jclass ioClass = (*env)->GetObjectClass(env, ioObject);
    nitf_Record *record = NULL;
    nitf_IOInterface *io = NULL;
    nitf_Error error;

    jmethodID methodID =
        (*env)->GetMethodID(env, recordClass, "getAddress", "()J");
    record = (nitf_Record *) (*env)->CallLongMethod(
            env, recordObject, methodID);

    /* punt if there is no record */
    if (!record)
        return JNI_FALSE;

    methodID =
        (*env)->GetMethodID(env, ioClass, "getAddress", "()J");
    io = (nitf_IOInterface*) ((*env)->CallLongMethod(env, ioObject, methodID));

    if (!nitf_Writer_prepareIO(writer, record, io, &error))
    {
        _ThrowNITFException(env, error.message);
        return JNI_FALSE;
    }
    return JNI_TRUE;
}


/*
 * Class:     nitf_Writer
 * Method:    setImageWriteHandler
 * Signature: (ILnitf/WriteHandler;)V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_setImageWriteHandler
  (JNIEnv *env, jobject self, jint index, jobject handler)
{
    nitf_Writer *writer = _GetObj(env, self);
    jclass writeHandlerClass = (*env)->FindClass(env, "nitf/WriteHandler");
    nitf_WriteHandler *writeHandler = NULL;
    nitf_Error error;
    jmethodID methodID;

    /* TODO - there might be a better way to do this, but for now we need to
     * keep this handler around for later. Maybe adding a list to the Writer
     * class might do the trick.
     */
    handler = (*env)->NewGlobalRef(env, handler);

    methodID =
        (*env)->GetMethodID(env, writeHandlerClass, "getAddress", "()J");
    writeHandler =
        (nitf_WriteHandler *) (*env)->CallLongMethod(env, handler, methodID);

    if (!nitf_Writer_setImageWriteHandler(writer, index, writeHandler, &error))
        _ThrowNITFException(env, error.message);

    /* tell Java not to manage it */
    methodID = (*env)->GetMethodID(env, writeHandlerClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, handler, methodID, JNI_FALSE);
}

/*
 * Class:     nitf_Writer
 * Method:    setGraphicWriteHandler
 * Signature: (ILnitf/WriteHandler;)V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_setGraphicWriteHandler
  (JNIEnv *env, jobject self, jint index, jobject handler)
{
    nitf_Writer *writer = _GetObj(env, self);
    jclass writeHandlerClass = (*env)->FindClass(env, "nitf/WriteHandler");
    nitf_WriteHandler *writeHandler = NULL;
    nitf_Error error;
    jmethodID methodID;

    /* TODO - there might be a better way to do this, but for now we need to
     * keep this handler around for later. Maybe adding a list to the Writer
     * class might do the trick.
     */
    handler = (*env)->NewGlobalRef(env, handler);

    methodID =
        (*env)->GetMethodID(env, writeHandlerClass, "getAddress", "()J");
    writeHandler =
        (nitf_WriteHandler *) (*env)->CallLongMethod(env, handler, methodID);

    if (!nitf_Writer_setGraphicWriteHandler(writer, index, writeHandler, &error))
        _ThrowNITFException(env, error.message);

    /* tell Java not to manage it */
    methodID = (*env)->GetMethodID(env, writeHandlerClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, handler, methodID, JNI_FALSE);
}

/*
 * Class:     nitf_Writer
 * Method:    setTextWriteHandler
 * Signature: (ILnitf/WriteHandler;)V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_setTextWriteHandler
  (JNIEnv *env, jobject self, jint index, jobject handler)
{
    nitf_Writer *writer = _GetObj(env, self);
    jclass writeHandlerClass = (*env)->FindClass(env, "nitf/WriteHandler");
    nitf_WriteHandler *writeHandler = NULL;
    nitf_Error error;
    jmethodID methodID;

    /* TODO - there might be a better way to do this, but for now we need to
     * keep this handler around for later. Maybe adding a list to the Writer
     * class might do the trick.
     */
    handler = (*env)->NewGlobalRef(env, handler);

    methodID =
        (*env)->GetMethodID(env, writeHandlerClass, "getAddress", "()J");
    writeHandler =
        (nitf_WriteHandler *) (*env)->CallLongMethod(env, handler, methodID);

    if (!nitf_Writer_setTextWriteHandler(writer, index, writeHandler, &error))
        _ThrowNITFException(env, error.message);

    /* tell Java not to manage it */
    methodID = (*env)->GetMethodID(env, writeHandlerClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, handler, methodID, JNI_FALSE);
}

/*
 * Class:     nitf_Writer
 * Method:    setDEWriteHandler
 * Signature: (ILnitf/WriteHandler;)V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_setDEWriteHandler
  (JNIEnv *env, jobject self, jint index, jobject handler)
{
    nitf_Writer *writer = _GetObj(env, self);
    jclass writeHandlerClass = (*env)->FindClass(env, "nitf/WriteHandler");
    nitf_WriteHandler *writeHandler = NULL;
    nitf_Error error;
    jmethodID methodID;

    /* TODO - there might be a better way to do this, but for now we need to
     * keep this handler around for later. Maybe adding a list to the Writer
     * class might do the trick.
     */
    handler = (*env)->NewGlobalRef(env, handler);

    methodID =
        (*env)->GetMethodID(env, writeHandlerClass, "getAddress", "()J");
    writeHandler =
        (nitf_WriteHandler *) (*env)->CallLongMethod(env, handler, methodID);

    if (!nitf_Writer_setDEWriteHandler(writer, index, writeHandler, &error))
        _ThrowNITFException(env, error.message);

    /* tell Java not to manage it */
    methodID = (*env)->GetMethodID(env, writeHandlerClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, handler, methodID, JNI_FALSE);
}

/*
 * Class:     nitf_Writer
 * Method:    getNewImageWriter
 * Signature: (I)Lnitf/ImageWriter;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewImageWriter
    (JNIEnv * env, jobject self, jint imageNumber)
{
    nitf_Writer *writer = _GetObj(env, self);
    nitf_ImageWriter *imageWriter;
    nitf_Error error;
    jclass imageWriterClass = (*env)->FindClass(env, "nitf/ImageWriter");
    jobject imageWriterObject;

    jmethodID methodID =
        (*env)->GetMethodID(env, imageWriterClass, "<init>", "(J)V");
    imageWriter = nitf_Writer_newImageWriter(writer, imageNumber, &error);

    if (!imageWriter)
    {
        _ThrowNITFException(env, error.message);
        return NULL;
    }

    imageWriterObject = (*env)->NewObject(env,
                                          imageWriterClass,
                                          methodID, (jlong) imageWriter);

    /* tell Java not to manage the memory */
    methodID = (*env)->GetMethodID(env, imageWriterClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, imageWriterObject, methodID, JNI_FALSE);

    return imageWriterObject;
}


/*
 * Class:     nitf_Writer
 * Method:    getNewTextWriter
 * Signature: (I)Lnitf/SegmentWriter;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewTextWriter
  (JNIEnv *env, jobject self, jint segmentNumber)
{
	nitf_Writer *writer = _GetObj(env, self);
    nitf_SegmentWriter *segmentWriter;
    nitf_Error error;
    jclass segmentWriterClass = (*env)->FindClass(env, "nitf/SegmentWriter");
    jobject segmentWriterObject;

    jmethodID methodID =
        (*env)->GetMethodID(env, segmentWriterClass, "<init>", "(J)V");
    segmentWriter = nitf_Writer_newTextWriter(writer, segmentNumber, &error);

    if (!segmentWriter)
    {
        _ThrowNITFException(env, error.message);
        return NULL;
    }

    segmentWriterObject = (*env)->NewObject(env,
                                            segmentWriterClass,
                                            methodID, (jlong) segmentWriter);

    /* tell Java not to manage the memory */
    methodID = (*env)->GetMethodID(env, segmentWriterClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, segmentWriterObject, methodID, JNI_FALSE);

    return segmentWriterObject;
}

/*
 * Class:     nitf_Writer
 * Method:    getNewGraphicWriter
 * Signature: (I)Lnitf/SegmentWriter;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewGraphicWriter
  (JNIEnv *env, jobject self, jint segmentNumber)
{
	nitf_Writer *writer = _GetObj(env, self);
    nitf_SegmentWriter *segmentWriter;
    nitf_Error error;
    jclass segmentWriterClass = (*env)->FindClass(env, "nitf/SegmentWriter");
    jobject segmentWriterObject;

    jmethodID methodID =
        (*env)->GetMethodID(env, segmentWriterClass, "<init>", "(J)V");
    segmentWriter = nitf_Writer_newGraphicWriter(writer, segmentNumber, &error);

    if (!segmentWriter)
    {
        _ThrowNITFException(env, error.message);
        return NULL;
    }

    segmentWriterObject = (*env)->NewObject(env,
                                            segmentWriterClass,
                                            methodID, (jlong) segmentWriter);

    /* tell Java not to manage the memory */
    methodID = (*env)->GetMethodID(env, segmentWriterClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, segmentWriterObject, methodID, JNI_FALSE);

    return segmentWriterObject;
}


JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewDEWriter
  (JNIEnv *env, jobject self, jint segmentNumber)
{
    nitf_Writer *writer = _GetObj(env, self);
    nitf_SegmentWriter *segmentWriter;
    nitf_Error error;
    jclass segmentWriterClass = (*env)->FindClass(env, "nitf/SegmentWriter");
    jobject segmentWriterObject;

    jmethodID methodID =
        (*env)->GetMethodID(env, segmentWriterClass, "<init>", "(J)V");
    segmentWriter = nitf_Writer_newDEWriter(writer, segmentNumber, &error);

    if (!segmentWriter)
    {
        _ThrowNITFException(env, error.message);
        return NULL;
    }

    segmentWriterObject = (*env)->NewObject(env,
                                            segmentWriterClass,
                                            methodID, (jlong) segmentWriter);

    /* tell Java not to manage the memory */
    methodID = (*env)->GetMethodID(env, segmentWriterClass, "setManaged", "(Z)V");
    (*env)->CallVoidMethod(env, segmentWriterObject, methodID, JNI_FALSE);

    return segmentWriterObject;
}


/*
 * Class:     nitf_Writer
 * Method:    write
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_nitf_Writer_write
    (JNIEnv * env, jobject self)
{
    nitf_Writer *writer = _GetObj(env, self);
    nitf_Error error;

    if (!nitf_Writer_write(writer, &error))
    {
        _ThrowNITFException(env, error.message);
        return JNI_FALSE;
    }

    return JNI_TRUE;
}
