#include <iostream>

int get_val() {
  int x = 1;
  return x;
}

int main() {
  // 什么是左值，什么事右值
  // 等号左边是左值，等号右边是右值，以下是反例
  int a = 1; // a 左值
  int b = a; // a 右值？
  //
  // 能取到地址是左值，否则是右值
  int x = 1; // left
  x++;       // right
  ++x;       // left
  get_val(); // right
  // 字符串字面量是左值
  auto p = &"hello world";
  std::cout << p << std::endl;
  return 0;
}
