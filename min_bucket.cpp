#include "min_bucket.h"
#include <exception>

min_bucket::min_bucket(size_t n): size(n), count(0)
{
  nums = new int [n];
  if (nums == nullptr) throw std::exception();
}

min_bucket::~min_bucket()
{
  delete [] nums;
}

void min_bucket::insert(int x)
{
  int i=0;
  while (i < count && x > nums[i]) i++;
  // now i is in the correct insertion position
  if (i >= size) return;
  // "move" items before inserting:
  // This is the for statement from the notes you
  // must fix.  You can rewrite the entire for
  // statement if you wish.  j should count down, not up.
  for (int j = /* ??? */; /* ??? */; --j) {
    if (j+1 < size) nums[j+1] = nums[j];
  }
  // finally insert x:
  nums[i] = x;
  if (count < size) count++;
}

int min_bucket::operator[](size_t n)
{
  if (n >= size) throw std::exception();
  return nums[n];
}
