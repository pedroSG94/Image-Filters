//
// Created by pedro on 18/11/16.
//
#include <stdio.h>
#include <stdlib.h>

void convertingToGaussian(void *pixelsColor, void *pixelsGaussianColor,
                          AndroidBitmapInfo *infoColor, AndroidBitmapInfo *gaussianImageInfo) {
    int size = 3;
    int sumR, sumG, sumB;
    int min = 0;
    int max = 255;
    int ancho = 50;
    double gaussianConfig[3][3] = {
            {1, 2, 1},
            {2, 4, 2},
            {1, 2, 1}
    };

    for (int y = 0; y < infoColor->height; y++) {
        argb *line = (argb *) pixelsColor;
        argb *gaussianLine = (argb *) pixelsGaussianColor;
        for (int x = 0; x < infoColor->width; x++) {
//            if (x % 100 == 0) ancho = 50;
//            if (ancho > 0) {
//                gaussianLine[x].red = 0;
//                gaussianLine[x].green = 0;
//                gaussianLine[x].blue = 0;
//                ancho--;
//            }
//            else{
//                gaussianLine[x].red = line[x].red;
//                gaussianLine[x].green = line[x].green;
//                gaussianLine[x].blue = line[x].blue;
//            }
//            gaussianLine[x].alpha = line[x].alpha;
            sumR = sumG = sumB = 0;
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    sumR += line[x].red * gaussianConfig[i][j];
                    sumG += line[x].green * gaussianConfig[i][j];
                    sumB += line[x].blue * gaussianConfig[i][j];
                }
            };
            int resultR = sumR / 2;
            if(resultR < 0) resultR = 0;
            else if(resultR > 255)  resultR = 255;
            gaussianLine[x].red = resultR;

            int resultG = sumG / 2;
            if(resultG < 0) resultG = 0;
            else if(resultR > 255)  resultG = 255;
            gaussianLine[x].green = resultG;

            int resultB = sumB / 2;
            if(resultB < 0) resultB = 0;
            else if(resultB > 255)  resultB = 255;
            gaussianLine[x].blue = resultB;
            gaussianLine[x].alpha = line[x].alpha;
        }
        pixelsColor = (char *) pixelsColor + infoColor->stride;
        pixelsGaussianColor = (char *) pixelsGaussianColor + gaussianImageInfo->stride;
    }
}

