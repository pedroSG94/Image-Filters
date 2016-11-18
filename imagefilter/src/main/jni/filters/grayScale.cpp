//
// Created by pedro on 17/11/16.
//
#include "android/bitmap.h"
#include "android/log.h"

void convertingToGray(void *pixelsColor, void *pixelsGrayColor,
                      AndroidBitmapInfo *infoColor, AndroidBitmapInfo *grayImageInfo) {
    for (int y = 0; y < infoColor->height; y++) {
        argb *line = (argb *) pixelsColor;
        argb *grayLine = (argb *) pixelsGrayColor;

        for (int x = 0; x < infoColor->width; x++) {
            grayLine[x].red = (line[x].red + line[x].green + line[x].blue) / 3;
            grayLine[x].green = (line[x].red + line[x].green + line[x].blue) / 3;
            grayLine[x].blue = (line[x].red + line[x].green + line[x].blue) / 3;
            grayLine[x].alpha = line[x].alpha;
        }
        pixelsColor = (char *) pixelsColor + infoColor->stride;
        pixelsGrayColor = (char *) pixelsGrayColor + grayImageInfo->stride;
    }
}