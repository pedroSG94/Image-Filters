//
// Created by pedro on 17/11/16.
//

void convertingToGreen(void *pixelsColor, void *pixelsGreenColor,
                      AndroidBitmapInfo *infoColor, AndroidBitmapInfo *greenImageInfo) {
    for (int y = 0; y < infoColor->height; y++) {
        argb *line = (argb *) pixelsColor;
        argb *greenLine = (argb *) pixelsGreenColor;

        for (int x = 0; x < infoColor->width; x++) {
//            greenLine[x].green = line[x].red * 0.960 - 0.050 * line[x].green + line[x].blue * 0;
//            greenLine[x].red = -1.0 * line[x].green;
//            greenLine[x].blue = 0.0;
//            greenLine[x].alpha = line[x].alpha;
//
            greenLine[x].red = ((line[x].red + line[x].green + line[x].blue) / 3) * 0.7;
            greenLine[x].green = 200;
            greenLine[x].blue = ((line[x].red + line[x].green + line[x].blue) / 3) * 0.7;
            greenLine[x].alpha = line[x].alpha;
        }
        pixelsColor = (char *) pixelsColor + infoColor->stride;
        pixelsGreenColor = (char *) pixelsGreenColor + greenImageInfo->stride;
    }
}