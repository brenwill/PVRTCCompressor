#pragma once

#include "ColorRgba.h"

namespace Javelin {

class RgbaBitmap {
public:
  int width;
  int height;
  unsigned char *data;

  RgbaBitmap(int w, int h)
    : width(w)
    , height(h)
    , data(new unsigned char[width * height * 4]) {
  }

  ~RgbaBitmap() {
    delete[] data;
  }

  int GetArea() const { return width * height; }

  int GetBitmapWidth() const { return width; }

  int GetBitmapHeight() const { return height; }

  const unsigned char *GetRawData() const { return data; }

  const ColorRgba<unsigned char> *GetData() const { return reinterpret_cast<ColorRgba<unsigned char> *>(data); }

  ColorRgba<unsigned char> *GetData() { return reinterpret_cast<ColorRgba<unsigned char> *>(data); }
};

}

