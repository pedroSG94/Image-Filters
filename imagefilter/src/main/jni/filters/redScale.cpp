//
// Created by pedro on 17/11/16.
//

void convertingToRed(void *pixelsColor, void *pixelsRedColor,
                      AndroidBitmapInfo *infoColor, AndroidBitmapInfo *redImageInfo) {
    for (int y = 0; y < infoColor->height; y++) {
        argb *line = (argb *) pixelsColor;
        argb *redLine = (argb *) pixelsRedColor;

        for (int x = 0; x < infoColor->width; x++) {
            redLine[x].red = 200;
            redLine[x].green = ((line[x].red + line[x].green + line[x].blue) / 3) * 0.7;
            redLine[x].blue = ((line[x].red + line[x].green + line[x].blue) / 3) * 0.7;
            redLine[x].alpha = line[x].alpha;
        }
        pixelsColor = (char *) pixelsColor + infoColor->stride;
        pixelsRedColor = (char *) pixelsRedColor + redImageInfo->stride;
    }
}