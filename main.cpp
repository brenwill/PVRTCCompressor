#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS // disable fopen/fread warnings on windows
#endif

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include "RgbBitmap.h"
#include "RgbaBitmap.h"
#include "PvrTcEncoder.h"
#include "PvrTcDecoder.h"

/*
 Test program for the PvrTcEncoder, it compresses and then decompresses an
 image, ensuring the end result is something reasonable.
 */

using namespace Javelin;

RgbBitmap *readTga(const char *filename) {
    FILE *fp = fopen(filename, "rb");

    fseek(fp, 0, SEEK_END);
    int fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char header[18];
    fread(header, 18, 1, fp);

    int w = header[12] | (header[13] << 8);
    int h = header[14] | (header[15] << 8);

    RgbBitmap *bitmap = new RgbBitmap(w, h);
    fread((void *) bitmap->data, w * h * 3, 1, fp);

    fclose(fp);

    return bitmap;
}

void writeTga(const char *filename, RgbBitmap *bitmap) {
    FILE *fp = fopen(filename, "wb");

    unsigned char header[18];
    memset(header, 0, 18);
    header[2] = 2;
    header[12] = bitmap->width & 0xff;
    header[13] = (bitmap->width >> 8) & 0xff;
    header[14] = bitmap->height & 0xff;
    header[15] = (bitmap->height >> 8) & 0xff;
    header[16] = 24;

    fwrite(header, 18, 1, fp);

    fwrite(bitmap->data, bitmap->width * bitmap->height * 3, 1, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    RgbBitmap *rgbBitmap = readTga("globe.tga");

    const int size = rgbBitmap->GetArea() / 2;
    ColorRgb<unsigned char> *rgb = rgbBitmap->GetData();

    // Write the texture prior to compression
    writeTga("globe_before.tga", rgbBitmap);

    unsigned char *pvrtc = new unsigned char[size];
    memset(pvrtc, 0, size);
    PvrTcEncoder::EncodeRgb4Bpp(pvrtc, *rgbBitmap);

    PvrTcDecoder::DecodeRgb4Bpp(rgb, rgbBitmap->GetSize(), pvrtc);

    // Write the texture post compression
    writeTga("globe_after.tga", rgbBitmap);

    delete rgbBitmap;

    return 0;
}
