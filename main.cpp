#include <array>
#include <iostream>
#include <string>

/**
 * Snippets from cppbyexample.
 */

int double_number_a(const int x) { return x * 2; }

void double_number_b(int *x) { *x *= 2; }

void double_number_c(int &x) {
  x *= 2;
  return;
}

struct my_struct {
  int p;
  int q;
};

// efficiently store multiple data structures in the same
// memory location
// only one value can be stored within the union
union my_data {
  int i;
  float f;
  char str[20];
};

enum week { mon, tue, wed, thu, fri, sat, sun };

typedef unsigned char byte;

int main() {
  std::cout << "Bismillah" << std::endl;

  auto k = 9; // automatically infer types

  std::string greeting_d = "Hello";
  char greeting_b[] = "Hello";

  std::cout << k << std::endl
            << greeting_b << std::endl
            << greeting_d << std::endl;

  std::array<int, 5> myarray;

  for (size_t i = 0; i < myarray.size(); ++i) {
    myarray[i] = i;
    std::cout << myarray[i] << std::endl;
  }

  auto x = 10;

  std::cout << double_number_a(x) << std::endl;

  double_number_c(x);
  std::cout << x << std::endl;

  double_number_b(&x);

  std::cout << x << std::endl;

  for (auto i = 0; i < 5; ++i) {
    std::cout << i << std::endl;
  }

  auto y = 1;

  while (y < 5) {
    std::cout << y << std::endl;
    y++;
  }

  auto x1 = 'A';

  if (x1 < 'A') {
    std::cout << "x1 is less than A" << std::endl;
  } else {
    std::cout << "x1 is greater than equal to A" << std::endl;
  }

  // storage duration of an object
  extern int a; // defined elsewhere
  static int b; // holds value between invocations
  thread_local int e;
  const int c = 11;
  std::atomic<int> d; // can be only modified by one thread at a time

  volatile int f; // can be modified externally, program will check the value
  // even if it has not changed locally

  // ternary operator
  x < 0 ? std::cout << "x is less than 0" << std::endl
        : std::cout << "x is greater than or equal to 0" << std::endl;

  // addressof
  std::cout << std::addressof(x) << std::endl;

  // IO
  std::cout << "x=?";
  std::cin >> x;
  std::cout << "x is now: " << x << std::endl;

  // Bitwise operation
  unsigned char r = 5;
  unsigned char s = 9;
  std::cout << "r & s =" << (r & s) << std::endl;
  std::cout << "r | s =" << (r | s) << std::endl;
  std::cout << "r ^ s =" << (r ^ s) << std::endl;
  std::cout << "~r = " << (~r) << std::endl;
  std::cout << "r << 1=" << (r << 1) << std::endl;
  std::cout << "r >> 1=" << (r >> 1) << std::endl;

  // typedef
  byte b1 = 'c';

  return 0;
}
