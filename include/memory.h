#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

/*
  Calculates a new capacity for the dynamic array
  Doubles the size
  If called for the first time after initializing the Chunk (capacity = 0) we start with 8
*/
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : capacity * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

/*
  Handles dynamic memory managment
  The two size arguments control which operation to perform
  oldSize = 0, newSize = Non-zero -> allocate new block
  oldSize = Non-zero, newSize = 0 -> Free allocation
  oldSize > newSize               -> Shrink existing allocation
  oldSize < newSize               -> Grow existion allocation
*/
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif