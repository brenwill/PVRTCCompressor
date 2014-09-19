#pragma once

namespace Javelin {

template<typename T>
class ColorRgb {
public:
  T r;
  T g;
  T b;

  ColorRgb()
    : r(0)
    , g(0)
    , b(0) {
  }

  ColorRgb(T red, T green, T blue)
    : r(red)
    , g(green)
    , b(blue) {
  }

  ColorRgb(const ColorRgb<T> &x)
    : r(x.r)
    , g(x.g)
    , b(x.b) {
  }

  ColorRgb<T> operator *(T x) {
    return ColorRgb<T>(r * x, g * x, b * x);
  }

  ColorRgb<T> operator +(const ColorRgb<T> &x) {
    return ColorRgb<T>(r + x.r, g + x.g, b + x.b);
  }

  ColorRgb<T> operator -(const ColorRgb<T> &x) {
    return ColorRgb<T>(r - x.r, g - x.g, b - x.b);
  }

  unsigned int operator %(const ColorRgb<T> &x) {
    return r * x.r + g * x.g + b * x.b;
  }

  bool operator ==(const ColorRgb<T> &x) {
    return r == x.r && g == x.g && b == x.b;
  }

  bool operator !=(const ColorRgb<T> &x) {
    return r != x.r || g != x.g || b != x.b;
  }
};

template<typename T>
class ColorRgba : public ColorRgb<T> {
public:
  T a;

  ColorRgba() :
    a(0) {
  }

  ColorRgba(T red, T green, T blue, T alpha)
    : ColorRgb<T>(red, green, blue)
    , a(alpha) {
  }

  ColorRgba(const ColorRgba<T> &x)
    : ColorRgb<T>(x.r, x.g, x.b)
    , a(x.a) {
  }

  ColorRgba<T> operator *(T x) {
    return ColorRgba<T>(ColorRgb<T>::r * x, 
                        ColorRgb<T>::g * x, ColorRgb<T>::b * x, a * x);
  }

  ColorRgba<T> operator +(const ColorRgba<T> &x) {
    return ColorRgba<T>(ColorRgb<T>::r + x.r, ColorRgb<T>::g + x.g, ColorRgb<T>::b + x.b, a + x.a);
  }

  ColorRgba<T> operator -(const ColorRgba<T> &x) {
    return ColorRgba<T>(ColorRgb<T>::r - x.r, ColorRgb<T>::g - x.g, ColorRgb<T>::b - x.b, a - x.a);
  }

  unsigned int operator %(const ColorRgba<T> &x) {
    return ColorRgb<T>::r * x.r + ColorRgb<T>::g * x.g + ColorRgb<T>::b * x.b + a * x.a;
  }

  bool operator ==(const ColorRgba<T> &x) {
    return ColorRgb<T>::r == x.r && ColorRgb<T>::g == x.g && ColorRgb<T>::b == x.b && a == x.a;
  }

  bool operator !=(const ColorRgba<T> &x) {
    return ColorRgb<T>::r != x.r || ColorRgb<T>::g != x.g || ColorRgb<T>::b != x.b || a != x.a;
  }
};

}
