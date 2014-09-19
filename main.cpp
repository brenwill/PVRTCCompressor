#include <iostream>
#include <stdio.h>
#include "RgbBitmap.h"
#include "PvrTcEncoder.h"
#include "PvrTcDecoder.h"

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
  fread((void *)bitmap->data, w * h * 3, 1, fp);

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

  const int area = rgbBitmap->GetArea();
  ColorRgb<unsigned char> *rgb = rgbBitmap->GetData();

  // Write the texture prior to compression
  writeTga("rgb_before.tga", rgbBitmap);

  unsigned char *pvrtc = new unsigned char[area];

  memset(pvrtc, 0, area);
  PvrTcEncoder::EncodeRgb4Bpp(pvrtc, *rgbBitmap);
  PvrTcDecoder::DecodeRgb4Bpp(rgb, Point2<int>(rgbBitmap->width, rgbBitmap->height), pvrtc);

  // Write the texture post compression
  writeTga("rgb_after.tga", rgbBitmap);

  delete rgbBitmap;

  return 0;
}
