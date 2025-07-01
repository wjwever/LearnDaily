#include <iostream>
// talk about left value reference

class X {
public:
  X() {
    // std::cout << "default constructor" << std::endl;
    printf("default constructor\n");
  }
  X(const X &x) {
    // std::cout << "copy constructor\n";
    printf("copy constructor\n");
  }
  X &operator=(const X &x) {
    // std::cout << "= constructor\n";
    printf("= constructor\n");
    return *this;
  }
  ~X() { printf("deconstructor\n"); }
};

X make_x() {
  // X x;
  // return x;
  return X();
}

int main() {
  // 左值引用，引用的对象是一个左值
  int x = 1;
  int &a = x;
  // compile error below
  // int& b = 1;
  // 常量左值引用，可以引用左值，右值
  const int &c = x;
  const int &d = 1;

  X x1;
  std::cout << "---\n\n";
  X x2(x1);
  std::cout << "---\n\n";
  X x3(make_x());
  std::cout << "---\n\n";
  x3 = make_x();
  std::cout << "---\n\n";

  return 0;
}
