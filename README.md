# LRU Cache Simulation in C++

## Overview
This repository contains a C++ implementation of a Least Recently Used (LRU) cache simulation. The simulation uses arrays and a clock counter to manage memory accesses and cache replacement. It provides a simple demonstration of how an LRU cache might be implemented in a low-level programming language.

## Features
- Simulates an LRU cache using dynamic arrays.
- Implements a `Memory` class that handles the logic for loading words (`lw`) and storing cache management.
- Provides a driver class to test two scenarios, showcasing the LRU cache behavior.
- Includes detailed reporting of cache hits, misses, and the state of registers.

## Files
- `main.cpp`: Contains the driver to run the simulation scenarios.
- `memory.h`: Defines the `Memory` class with all the necessary LRU cache logic.
