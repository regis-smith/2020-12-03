#pragma once
#include <cstddef> // for size_t

// A min_bucket of size n stores the smallest (at most) n
// ints ever inserted within itself.

class min_bucket {
public:
  min_bucket(size_t);
  ~min_bucket();
  void insert(int);
  int operator[](size_t);
  // make copy constructor and copy assignment unavailable
  min_bucket(const min_bucket&) = delete;
  min_bucket& operator=(const min_bucket&) = delete;
private:
  size_t size, count;
  int* nums = nullptr;
};
