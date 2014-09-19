#pragma once

namespace Javelin {

template<typename T>
class Interval {
public:
  T min;
  T max;

  Interval() {
  }

  bool IsEmpty() const {
    return false;
  }

  Interval<T> &operator|=(const T &x) {
    if (x.r < min.r) {
      min.r = x.r;
    }
    if (x.r > max.r) {
      max.r = x.r;
    }

    if (x.g < min.g) {
      min.g = x.g;
    }
    if (x.g > max.g) {
      max.g = x.g;
    }

    if (x.b < min.b) {
      min.b = x.b;
    }
    if (x.b > max.b) {
      max.b = x.b;
    }

    return *this;
  }
};

}
