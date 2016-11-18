//
// Created by pedro on 17/11/16.
//

void convertingToBlue(void *pixelsColor, void *pixelsBlueColor,
                      AndroidBitmapInfo *infoColor, AndroidBitmapInfo *blueImageInfo) {
    for (int y = 0; y < infoColor->height; y++) {
        argb *line = (argb *) pixelsColor;
        argb *blueLine = (argb *) pixelsBlueColor;

        for (int x = 0; x < infoColor->width; x++) {
            blueLine[x].red = ((line[x].red + line[x].green + line[x].blue) / 3) * 0.7;
            blueLine[x].green = ((line[x].red + line[x].green + line[x].blue) / 3) * 0.7;
            blueLine[x].blue = 200;
            blueLine[x].alpha = line[x].alpha;
        }
        pixelsColor = (char *) pixelsColor + infoColor->stride;
        pixelsBlueColor = (char *) pixelsBlueColor + blueImageInfo->stride;
    }
}