#include"graph.h"

int main(int argc, char const *argv[])
{
    uint64_t *puzzle = (uint64_t*)malloc(sizeof(uint64_t));
    
    intiPuzle(puzzle);
    printBits(puzzle);
    swapPuzzle(puzzle, 0, 2);
    printBits(puzzle);

    return 0;
}
