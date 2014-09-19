#pragma once

#include "ColorRgba.h"

namespace Javelin {

class RgbBitmap {
public:
  int width;
  int height;
  unsigned char *data;

  RgbBitmap(int w, int h)
    : width(w)
    , height(h)
    , data(new unsigned char[width * height * 3]) {
  }

  ~RgbBitmap() {
    delete[] data;
  }

  int GetArea() const { return width * height; }

  int GetBitmapWidth() const { return width; }

  int GetBitmapHeight() const { return height; }

  const unsigned char *GetRawData() const { return data; }

  const ColorRgb<unsigned char> *GetData() const { return reinterpret_cast<ColorRgb<unsigned char> *>(data); }

  ColorRgb<unsigned char> *GetData() { return reinterpret_cast<ColorRgb<unsigned char> *>(data); }
};

}

