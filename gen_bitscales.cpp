#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
  std::cout << "#include \"BitScale.h\"" << std::endl << std::endl;
  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_5_TO_8[32] = {" << std::endl;
  for (int i = 0; i < 32; ++i) {
    std::cout << " " << ((i * 8));
    if (i != 31) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;

  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_4_TO_8[16] = {" << std::endl;
  for (int i = 0; i < 16; ++i) {
    std::cout << " " << ((i * 16));
    if (i != 15) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;

  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_3_TO_8[8] = {" << std::endl;
  for (int i = 0; i < 8; ++i) {
    std::cout << " " << ((i * 32));
    if (i != 7) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;

  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_8_TO_5_FLOOR[256] = {" << std::endl;
  for (int i = 0; i < 256; ++i) {
    std::cout << " " << std::floor(i / 8.0);
    if (i != 255) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;

  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_8_TO_4_FLOOR[256] = {" << std::endl;
  for (int i = 0; i < 256; ++i) {
    std::cout << " " << std::floor(i / 16.0);
    if (i != 255) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;

  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_8_TO_3_FLOOR[256] = {" << std::endl;
  for (int i = 0; i < 256; ++i) {
    std::cout << " " << std::floor(i / 32.0);
    if (i != 255) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;


std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_8_TO_5_CEIL[256] = {" << std::endl;
  for (int i = 0; i < 256; ++i) {
    std::cout << " " << std::ceil(i / 8.0);
    if (i != 255) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;

  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_8_TO_4_CEIL[256] = {" << std::endl;
  for (int i = 0; i < 256; ++i) {
    std::cout << " " << std::ceil(i / 16.0);
    if (i != 255) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;

  std::cout << "constexpr uint8_t Javelin::Data::BITSCALE_8_TO_3_CEIL[256] = {" << std::endl;
  for (int i = 0; i < 256; ++i) {
    std::cout << " " << std::ceil(i / 32.0);
    if (i != 255) {
      std::cout << ",";
    }
    if (i % 10 == 9) {
       std::cout << std::endl;
    }
  }
  std::cout << "};" << std::endl << std::endl;
}
