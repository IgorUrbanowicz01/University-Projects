#include"graph.h"

int main(int argc, char const *argv[])
{
    uint64_t *puzzle;
    intiPuzle(puzzle);
    printBits(puzzle);
    swapPuzzle(puzzle, 2, 4);
    printBits(puzzle);

    return 0;
}
