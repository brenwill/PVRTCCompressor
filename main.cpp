#include <iostream>
#include "RgbBitmap.h"
#include "PvrTcEncoder.h"
#include "PvrTcDecoder.h"

using namespace Javelin;

void writeTga(FILE *fp, ColorRgb<unsigned char> *rgb, int width, int height) {
  unsigned char *header = new unsigned char[18];
  memset(header, 0, 18);
  header[2] = 2;
  header[12] = width & 0xff;
  header[13] = (width >> 8) & 0xff;
  header[14] = height & 0xff;
  header[15] = (height >> 8) & 0xff;
  header[16] = 24;

  fwrite(header, 18, 1, fp);

  fwrite(rgb, width * height * 3, 1, fp);

  delete[] header;
}

int main(int argc, char **argv) {
  const int w = 64;
  const int h = 64;
  const int area = w * h;

  RgbBitmap rgbBitmap(w, h);
  ColorRgb<unsigned char> *rgb = rgbBitmap.GetData();

  // Generate some texture
  for (int y = 0, pi = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x, ++pi) {
      rgb[pi] = ColorRgb<unsigned char>(x % 255, y % 255, (x * y) % 255);
    }
  }

  // Write the texture prior to compression
  FILE *fp = fopen("rgb_before.tga", "wb");
  writeTga(fp, rgb, w, h);
  fclose(fp);

  unsigned char *pvrtc = new unsigned char[area];

  memset(pvrtc, 0, area);
  PvrTcEncoder::EncodeRgb4Bpp(pvrtc, rgbBitmap);
  PvrTcDecoder::DecodeRgb4Bpp(rgb, Point2<int>(w, h), pvrtc);

  // Write the texture post compression
  fp = fopen("rgb_after.tga", "wb");
  writeTga(fp, rgb, w, h);
  fclose(fp);

  return 0;
}
