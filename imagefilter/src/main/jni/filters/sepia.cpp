//
// Created by pedro on 17/11/16.
//
#include "android/bitmap.h"

/*  For reference, SEPIA CODE
    R' = (R * 0.393 + G * 0.769 + B * 0.189);
    G' = (R * 0.349 + G * 0.686 + B * 0.168);
    B' = (R * 0.272 + G * 0.534 + B * 0.131);
/* 	===================================== 	*/
void convertingImageToSepia(void *pixelsColor, void *pixelsSepia, AndroidBitmapInfo *infoColor,
                            AndroidBitmapInfo *sepiaImageColor) {
    for (int y = 0; y < infoColor->height; y++) {
        argb *line = (argb *) pixelsColor;
        argb *sepiaLine = (argb *) pixelsSepia;

        for (int x = 0; x < infoColor->width; x++) {
            sepiaLine[x].red = 0.393 * line[x].red + 0.769 * line[x].green + 0.189 * line[x].blue;
            sepiaLine[x].green = 0.349 * line[x].red + 0.686 * line[x].green + 0.168 * line[x].blue;
            sepiaLine[x].blue = 0.272 * line[x].red + 0.534 * line[x].green + 0.131 * line[x].blue;
            sepiaLine[x].alpha = line[x].alpha;
        }
        pixelsColor = (char *) pixelsColor + infoColor->stride;
        pixelsSepia = (char *) pixelsSepia + sepiaImageColor->stride;
    }
}