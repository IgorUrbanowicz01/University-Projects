#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

void printBits(uint64_t *puzzle);
void  intiPuzle(uint64_t *puzzle);
uint8_t getPosition(uint64_t *puzzle, int start_bit);
void insert_bits(uint64_t *puzzle, uint8_t bits, int start_bit);
void swapPuzzle(uint64_t *puzzle, int x, int y);
void shuffle(int arr[], int n);