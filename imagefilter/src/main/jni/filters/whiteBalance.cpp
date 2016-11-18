//
// Created by pedro on 17/11/16.
//
#include <iostream>
#include "android/log.h"
#include <math.h>

//0,065535281
//5982,762688474

void whiteBalance(void *pixelsColor, void *pixelsGrayColor,
                  AndroidBitmapInfo *infoColor, AndroidBitmapInfo *grayImageInfo) {

    double temp1 = 0;
    double temp2 = 0;
    for (int y = 0; y < infoColor->height / 3; y++) {
        argb *line = (argb *) pixelsColor;
        uint8_t *grayLine = (uint8_t *) pixelsGrayColor;
        for (int x = 0; x < infoColor->width / 3; x++) {
            double n = ((0.23881) * line[x].red + (0.25499) * line[x].green +
                        (-0.58291) * line[x].blue) /
                       ((0.11109) * line[x].red + (-0.85406) * line[x].green +
                        (0.52289) * line[x].blue);
            temp1 += 449 * (n * n * n) + 3525 * (n * n) + 6823.3 * n + 5520.33;

            double X = (-0.14282 * line[x].red) + (1.54924 * line[x].green) + (-0.95641 * line[x].blue);
            double Y = (-0.32466 * line[x].red) + (1.57837 * line[x].green) + (-0.73191 * line[x].blue);
            double Z = (-0.68202 * line[x].red) + (0.77073 * line[x].green) + (0.56332 * line[x].blue);

            double x1 = X / (X + Y + Z);
            double y1 = Y / (X + Y + Z);
            double n2 = (x1 - 0.3320) / (y1 - 0.1691);
//            temp2 += -(449 * (n2 * n2 * n2)) + (3525 * (n2 * n2)) - (6823.3 * n2) + (5520.33);
            temp2 += 36284.48953 + pow(0.00228, -n2/0.07861) + pow(pow(5.4535 * 10, -36), -n2/0.01543);
        }
    }
    temp1 = temp1 / (infoColor->height * infoColor->width / 9);
    temp2 = temp2 / (infoColor->height * infoColor->width / 9);
    __android_log_print(ANDROID_LOG_ERROR,"White balance 1", "%f %d %d", temp1, infoColor->height, infoColor->width);
    __android_log_print(ANDROID_LOG_ERROR,"White balance 2", "%f %d %d", temp2, infoColor->height, infoColor->width);
}