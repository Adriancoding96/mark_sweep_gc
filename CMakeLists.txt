cmake_minimum_required(VERSION 3.27)
project(mark_sweep_gc)

set(CMAKE_CXX_STANDARD 17)

add_executable(mark_sweep_gc main.cpp
        MemoryPool/MemoryPool.cpp
        MemoryPool/MemoryPool.h
        Object/Object.cpp
        Object/Object.h
        ObjectManager/ObjectManager.cpp
        ObjectManager/ObjectManager.h
        GarbageCollector/GarbageCollector.cpp
        GarbageCollector/GarbageCollector.h)
