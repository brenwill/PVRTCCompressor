#pragma once

namespace Javelin {

class BitUtility {
public:
  static bool IsPowerOf2(unsigned int x) {
    return (x & (x - 1)) == 0;
  }

  static unsigned int RotateRight(unsigned int n, unsigned int d) {
    return (n >> d) | (n << (32 - d));
  }
};

}

