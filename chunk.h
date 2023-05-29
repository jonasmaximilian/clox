#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

/*
  Each instruction will be represented by a 
  one-byte operation code
  e.g. add, subtract, look up variable
*/
typedef enum {
  OP_RETURN,
} OpCode;

/* Dynamic array, which stores instructions */
typedef struct {
  int count;
  int capacity;
  uint8_t* code;
} Chunk;

/* Initializes our dynamic array */
void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
/* Add bytecode to the chunk */
void writeChunk(Chunk* chunk, uint8_t byte);

#endif