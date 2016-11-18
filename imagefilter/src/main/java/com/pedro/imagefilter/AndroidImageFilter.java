package com.pedro.imagefilter;

import android.graphics.Bitmap;

/**
 * Created by pedro on 16/11/16.
 */

public class AndroidImageFilter {

  static {
    System.loadLibrary("ImageFilter");
  }

  public native void grayScale(Bitmap bOrigin, Bitmap bResult);
  public native void sepia(Bitmap bOrigin, Bitmap bResult);
  public native void negative(Bitmap bOrigin, Bitmap bResult);
  public native void redScale(Bitmap bOrigin, Bitmap bResult);
  public native void blueScale(Bitmap bOrigin, Bitmap bResult);
  public native void greenScale(Bitmap bOrigin, Bitmap bResult);
  public native void whiteBalance(Bitmap bOrigin, Bitmap bResult);
}
