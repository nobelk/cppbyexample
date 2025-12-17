#include "../include/my_struct.hpp"
#include <array>
#include <assert.h>
#include <cstdarg>
#include <iostream>
#include <string>
#include <thread>

/**
 * Snippets from cppbyexample.
 */

int double_number_a(const int x) { return x * 2; }

void double_number_b(int *x) { *x *= 2; }

void double_number_c(int &x) {
  x *= 2;
  return;
}

// variadic argument
int sum(int count, ...) {
  int total, i, temp;
  total = 0;
  va_list args;
  va_start(args, count);

  for (int i = 0; i < count; i++) {
    temp = va_arg(args, int);
    total += temp;
  }
  va_end(args);
  return total;
}

// void thread function
void thread_func_simple() {
  std::cout << "Printing from the thread" << std::endl;
  return;
}

enum week { mon, tue, wed, thu, fri, sat, sun };

typedef unsigned char byte;

typedef struct data {
  std::mutex mtx;
  int x;
} data;

void thread_func(data *d) {
  d->mtx.lock();
  d->x = 2;
  d->mtx.unlock();
  return;
}

class human {
  int height;
  int weight;

public:
  human(int height, int weight) {
    this->height = height;
    this->weight = weight;
  }
  ~human() {}

  int get_height() const { return height; }
  int get_weight() const { return weight; }
};

template <class T> T largest(T n1, T n2) { return (n1 > n2) ? n1 : n2; }

double divide(double num, double denom) {
  if (denom == 0) {
    throw "Cannot divide by 0";
  }
  return num / denom;
}

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

  // variadic arguments
  int numbers[] = {3, 5, 7};
  int sum_of_numbers = sum(3, numbers[0], numbers[1], numbers[2]);

  std::cout << "sum of array: " << sum_of_numbers << std::endl;

  // threads
  std::thread thread_obj(thread_func_simple);
  thread_obj.join();
  std::cout << "Thread returned" << std::endl;

  // Mutex
  data d1;
  std::thread thread_obj1(thread_func, &d1);
  thread_obj1.join();
  std::cout << "X has safely been modified to " << d1.x << std::endl;

  // heap allocation
  int *p = new int;
  std::cout << "Default value of p: " << *p << std::endl;
  delete p;

  int z = 10;
  assert(z == 10);

  // range
  std::vector<int> v = {0, 1, 2};
  for (const int &i : v) {
    std::cout << i << std::endl;
  }

  int a1[] = {1, 2, 3, 4, 5};
  for (auto u : a1) {
    std::cout << u << std::endl;
  }

  std::cout << " Largest " << largest<int>(x, y) << std::endl;

  // lambda
  auto multiply = [&x](int y) -> int { return x * y; };
  std::cout << multiply(5) << std::endl;

  // try-catch
  try {
    std::cout << divide(2.0, 0.0) << std::endl;
  } catch (const char *err) {
    std::cerr << err << std::endl;
  }

  return 0;
}
