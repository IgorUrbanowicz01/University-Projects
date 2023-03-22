#include"graph.h"

#define PUZZLE_SIZE 16

uint8_t getPosition(uint64_t *puzzle, int start_bit) {
    uint64_t mask = 0xfULL << start_bit; 
    uint64_t bits = (*puzzle & mask) >> start_bit; 
    return (uint8_t)bits; 
}

void insert_bits(uint64_t *puzzle, uint8_t bits, int start_bit) {
    uint64_t mask = 0xfULL << start_bit; 
    *puzzle &= ~mask;
    *puzzle |= ((uint64_t)bits << start_bit); 
}

void swapPuzzle(uint64_t *puzzle, int x, int y){
    uint8_t bitsX = getPosition(puzzle, x);
    uint8_t bitsY = getPosition(puzzle, y);
    insert_bits(puzzle, bitsX, y);
    insert_bits(puzzle, bitsY, x);
}

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void  intiPuzle(uint64_t *puzzle){
    int arr[PUZZLE_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    shuffle(arr, PUZZLE_SIZE);
    *puzzle = 0;
for (int i = 0; i < PUZZLE_SIZE; i++)
{
    printf("%d ", arr[i]);
}
printf("\n");


for (int i = 0; i < PUZZLE_SIZE; i++) {
        insert_bits(puzzle,(uint8_t)arr[i], i);
    }
}

void printBits(uint64_t *puzzle)
{
    for (int i = 0; i <= 15; i++) {
        uint8_t temp = getPosition(puzzle, i);
        printf("%d: %u |",i, temp);
    }
    printf("\n");
}
