//
// Created by adrian on 16/04/2024.
//

#include "MemoryPool.h"

void MemoryPool::initializePool() {
    freeList = reinterpret_cast<Block*>(&pool[0]); //Sets freeList ptr to the beginning of the pool
    Block *iter = freeList; //Iter is used to traverse and link blocks in the pool

    /*Iterates through each block of the pool creating a linked list where each block points to the next*/
    for(size_t i {0}; i < blockCount; i++) {
        iter -> next = reinterpret_cast<Block*>(&pool[i * blockSize]);
        iter = iter -> next;
    }
    iter->next = nullptr; //Sets the last block next pointer to nullptr, signaling the end of the list
}

MemoryPool::MemoryPool(size_t blockSize, size_t count)
                        : blockSize(blockSize), blockCount(count), pool(blockSize * count, 0) {

    if(blockSize < sizeof(Block*)) {
        throw std::invalid_argument("Block size must be larger than pointer size");
    }
    initializePool();
}

void *MemoryPool::allocate() {
    if(!freeList) { //Check for available memory, if none exists throw exception
        throw std::bad_alloc();
    }

    /*Grab and return the first free block and update freeList*/
    Block *block = freeList;
    freeList = freeList -> next;
    return block;
}

void MemoryPool::free(void *ptr) {
    Block *block = static_cast<Block*>(ptr); //Casts provided pointer to a Block
    block -> next = freeList; //Insert the freed block at the start of freeList
    freeList = block;
}

MemoryPool::~MemoryPool() {
    //TODO Implement destructor
}
