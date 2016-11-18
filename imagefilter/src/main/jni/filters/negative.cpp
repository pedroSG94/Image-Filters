//
// Created by pedro on 17/11/16.
//
#include "android/bitmap.h"

void convertingImageToNegative(void *pixelsColor, void *pixelsNegative,
                               AndroidBitmapInfo *infoColor,
                               AndroidBitmapInfo *negativeImageColor) {
    for (int y = 0; y < infoColor->height; y++) {
        argb *line = (argb *) pixelsColor;
        argb *negativeLine = (argb *) pixelsNegative;

        for (int x = 0; x < infoColor->width; x++) {
            negativeLine[x].red = 255 - line[x].red;
            negativeLine[x].green = 255 - line[x].green;
            negativeLine[x].blue = 255 - line[x].blue;
            negativeLine[x].alpha = line[x].alpha;
        }
        pixelsColor = (char *) pixelsColor + infoColor->stride;
        pixelsNegative = (char *) pixelsNegative + negativeImageColor->stride;
    }
}