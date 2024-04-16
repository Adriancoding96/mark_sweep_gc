//
// Created by adrian on 16/04/2024.
//

#ifndef MARK_SWEEP_GC_MEMORYPOOL_H
#define MARK_SWEEP_GC_MEMORYPOOL_H

#include <cstddef>
#include <iostream>
#include <vector>
#include <stdexcept>

class MemoryPool {

private:
    struct Block {
        Block *next;
    };

    Block *freeList;
    std::vector<char> pool;
    size_t blockSize;
    size_t blockCount;

    void initializePool();

public:
    MemoryPool(size_t blockSize, size_t count);
    void *allocate();
    void free(void *ptr);
    ~MemoryPool();

};

#endif //MARK_SWEEP_GC_MEMORYPOOL_H
