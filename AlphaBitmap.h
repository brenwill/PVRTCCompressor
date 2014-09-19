#pragma once

namespace Javelin {

class AlphaBitmap {
public:
  int width;
  int height;
  unsigned char *data;

  AlphaBitmap(int w, int h)
    : width(w)
    , height(h)
    , data(new unsigned char[width * height]) {
  }

  ~AlphaBitmap() {
    delete[] data;
  }

  int GetArea() const { return width * height; }

  int GetBitmapWidth() const { return width; }

  int GetBitmapHeight() const { return height; }

  const unsigned char *GetRawData() const { return data; }

  const unsigned char *GetData() const { return data; }

  unsigned char *GetData() { return data; }
};

}
