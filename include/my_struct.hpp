#ifndef PROG_HPP
#define PROG_HPP

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

#endif
