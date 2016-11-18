//
// Created by pedro on 16/11/16.
//
#include "com_pedro_imagefilter_AndroidImageFilter.h"
#include "android/log.h"
#include "jni.h"
#include "filters/structARGB.cpp"
#include "filters/sepia.cpp"
#include "filters/grayScale.cpp"
#include "filters/negative.cpp"
#include "filters/redScale.cpp"
#include "filters/greenScale.cpp"
#include "filters/blueScale.cpp"
#include "filters/gaussian.cpp"
#include "filters/whiteBalance.cpp"

#define APP_NAME    "ImageFilter"
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR,APP_NAME,__VA_ARGS__)
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO,APP_NAME,__VA_ARGS__)

/*
 * Class:     com_pedro_imagefilter_AndroidImageFilter
 * Method:    greyScale
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;)Landroid/graphics/Bitmap;
 */
JNIEXPORT void JNICALL Java_com_pedro_imagefilter_AndroidImageFilter_grayScale
        (JNIEnv *env, jobject obj, jobject bOrigin, jobject bResult) {

    AndroidBitmapInfo infoColor;
    AndroidBitmapInfo infoGray;
    void *pixelsColor;
    void *pixelsGray;
    int ret;

    if ((ret = AndroidBitmap_getInfo(env, bOrigin, &infoColor)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if ((ret = AndroidBitmap_getInfo(env, bResult, &infoGray)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if (infoColor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        LOG_E("Bitmap format is not RGBA_8888 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bOrigin, &pixelsColor)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    if ((ret = AndroidBitmap_lockPixels(env, bResult, &pixelsGray)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    convertingToGray(pixelsColor, pixelsGray, &infoColor, &infoGray);
    LOG_I("unlocking pixels");
    AndroidBitmap_unlockPixels(env, bOrigin);
    AndroidBitmap_unlockPixels(env, bResult);
}

/*
 * Class:     com_pedro_imagefilter_AndroidImageFilter
 * Method:    sepia
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;)Landroid/graphics/Bitmap;
 */
JNIEXPORT void JNICALL Java_com_pedro_imagefilter_AndroidImageFilter_sepia
        (JNIEnv *env, jobject obj, jobject bOrigin, jobject bResult) {

    AndroidBitmapInfo infoColor;
    AndroidBitmapInfo infoSepia;
    void *pixelsColor;
    void *pixelsSepia;
    int ret;

    if ((ret = AndroidBitmap_getInfo(env, bOrigin, &infoColor)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if ((ret = AndroidBitmap_getInfo(env, bResult, &infoSepia)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if (infoColor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        LOG_E("Bitmap format is not RGBA_8888 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bOrigin, &pixelsColor)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    if ((ret = AndroidBitmap_lockPixels(env, bResult, &pixelsSepia)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    convertingImageToSepia(pixelsColor, pixelsSepia, &infoColor, &infoSepia);
    LOG_I("unlocking pixels");
    AndroidBitmap_unlockPixels(env, bOrigin);
    AndroidBitmap_unlockPixels(env, bResult);

}

JNIEXPORT void JNICALL Java_com_pedro_imagefilter_AndroidImageFilter_negative
        (JNIEnv *env, jobject obj, jobject bOrigin, jobject bResult) {

    AndroidBitmapInfo infoColor;
    void *pixelsColor;
    AndroidBitmapInfo infoNegative;
    void *pixelsNegative;
    int ret;

    if ((ret = AndroidBitmap_getInfo(env, bOrigin, &infoColor)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if ((ret = AndroidBitmap_getInfo(env, bResult, &infoNegative)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if (infoColor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        LOG_E("Bitmap format is not RGBA_8888 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bOrigin, &pixelsColor)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    if ((ret = AndroidBitmap_lockPixels(env, bResult, &pixelsNegative)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    convertingImageToNegative(pixelsColor, pixelsNegative, &infoColor, &infoNegative);
    LOG_I("unlocking pixels");
    AndroidBitmap_unlockPixels(env, bOrigin);
    AndroidBitmap_unlockPixels(env, bResult);
}

JNIEXPORT void JNICALL Java_com_pedro_imagefilter_AndroidImageFilter_redScale
        (JNIEnv *env, jobject obj, jobject bOrigin, jobject bResult) {
    AndroidBitmapInfo infoColor;
    void *pixelsColor;
    AndroidBitmapInfo infoRed;
    void *pixelsRed;
    int ret;
    int y;
    int x;

    if ((ret = AndroidBitmap_getInfo(env, bOrigin, &infoColor)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if ((ret = AndroidBitmap_getInfo(env, bResult, &infoRed)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if (infoColor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        LOG_E("Bitmap format is not RGBA_8888 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bOrigin, &pixelsColor)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    if ((ret = AndroidBitmap_lockPixels(env, bResult, &pixelsRed)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }
    convertingToRed(pixelsColor, pixelsRed, &infoColor, &infoRed);
    LOG_I("unlocking pixels");
    AndroidBitmap_unlockPixels(env, bOrigin);
    AndroidBitmap_unlockPixels(env, bResult);
}

JNIEXPORT void JNICALL Java_com_pedro_imagefilter_AndroidImageFilter_greenScale
        (JNIEnv *env, jobject obj, jobject bOrigin, jobject bResult) {
    AndroidBitmapInfo infoColor;
    void *pixelsColor;
    AndroidBitmapInfo infoGreen;
    void *pixelsGreen;
    int ret;
    int y;
    int x;

    if ((ret = AndroidBitmap_getInfo(env, bOrigin, &infoColor)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if ((ret = AndroidBitmap_getInfo(env, bResult, &infoGreen)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if (infoColor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        LOG_E("Bitmap format is not RGBA_8888 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bOrigin, &pixelsColor)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    if ((ret = AndroidBitmap_lockPixels(env, bResult, &pixelsGreen)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }
    convertingToGreen(pixelsColor, pixelsGreen, &infoColor, &infoGreen);
    LOG_I("unlocking pixels");
    AndroidBitmap_unlockPixels(env, bOrigin);
    AndroidBitmap_unlockPixels(env, bResult);
}

JNIEXPORT void JNICALL Java_com_pedro_imagefilter_AndroidImageFilter_blueScale
        (JNIEnv *env, jobject obj, jobject bOrigin, jobject bResult) {
    AndroidBitmapInfo infoColor;
    void *pixelsColor;
    AndroidBitmapInfo infoBlue;
    void *pixelsBlue;
    int ret;
    int y;
    int x;

    if ((ret = AndroidBitmap_getInfo(env, bOrigin, &infoColor)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if ((ret = AndroidBitmap_getInfo(env, bResult, &infoBlue)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if (infoColor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        LOG_E("Bitmap format is not RGBA_8888 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bOrigin, &pixelsColor)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    if ((ret = AndroidBitmap_lockPixels(env, bResult, &pixelsBlue)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }
    convertingToBlue(pixelsColor, pixelsBlue, &infoColor, &infoBlue);
    LOG_I("unlocking pixels");
    AndroidBitmap_unlockPixels(env, bOrigin);
    AndroidBitmap_unlockPixels(env, bResult);
}

JNIEXPORT void JNICALL Java_com_pedro_imagefilter_AndroidImageFilter_whiteBalance
        (JNIEnv *env, jobject obj, jobject bOrigin, jobject bResult) {
    AndroidBitmapInfo infoColor;
    void *pixelsColor;
    AndroidBitmapInfo infoBlue;
    void *pixelsBlue;
    int ret;
    int y;
    int x;

    if ((ret = AndroidBitmap_getInfo(env, bOrigin, &infoColor)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if ((ret = AndroidBitmap_getInfo(env, bResult, &infoBlue)) < 0) {
        LOG_E("AndroidBitmap_getInfo() failed !");
        return;
    }

    if (infoColor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
        LOG_E("Bitmap format is not RGBA_8888 !");
        return;
    }

    if ((ret = AndroidBitmap_lockPixels(env, bOrigin, &pixelsColor)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }

    if ((ret = AndroidBitmap_lockPixels(env, bResult, &pixelsBlue)) < 0) {
        LOG_E("AndroidBitmap_lockPixels() failed !");
    }
    whiteBalance(pixelsColor, pixelsBlue, &infoColor, &infoBlue);
    LOG_I("unlocking pixels");
//    AndroidBitmap_unlockPixels(env, bOrigin);
//    AndroidBitmap_unlockPixels(env, bResult);
}