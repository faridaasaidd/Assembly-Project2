# Assembly-Project2
# Cache Simulator Project

## Overview
This project contains a cache simulator that supports both direct-mapped and fully associative cache configurations. The simulator is designed to test the hit ratio for different memory access patterns and line sizes.

## Files
- **main.cpp**: Contains the main implementation of the cache simulator. It includes memory address generators, cache simulation functions, and the main function to run the simulations.
- **graph.py**: Contains a pthon code that generates hit rate against line size graphs from the results  for both direct map cache and for the fully associative cache

## Description of main.cpp
- Cache size is fixed to 65kB

- **Enums**:
  - `enum cacheResType { MISS = 0, HIT = 1 };`: Defines the result types of cache access.

- **Memory Address Generators**:
  - `unsigned int memGen1()`: Generates sequential addresses. Address is incremented by 1 each time.
  - `unsigned int memGen2()`: Generates random addresses within the range of 0 to 24 kB.
  - `unsigned int memGen3()`: Generates completely random addresses within the size of the DRAM.
  - `unsigned int memGen4()`: Generates sequential addresses within a small range of 0 to 4kB. Address is incremented by 1 each time.
  - `unsigned int memGen5()`: Generates sequential addresses within a larger range of 0 to 65kB. Address is incremented by 1 each time.
  - `unsigned int memGen6()`: Generates addresses with a fixed memory access pattern where addresses are accessed with a constant interval of 32 bytes between them within a range of 0 to 256kB.
    
- **Cache Simulators**:
  - `cacheResType cacheSimDM(vector<CacheLine>& directMappedCache, unsigned int addr, unsigned int lineSize)`: Simulates a direct-mapped cache.
  - `cacheResType cacheSimFA(vector<CacheLine>& fullyAssocCache, unsigned int addr, unsigned int lineSize)`: Simulates a fully associative cache with random replacement.
  - Both caches are initialized as empty caches.

- **Simulation Function**:
  - `void runSimulation(unsigned int (*memGen)(), vector<unsigned int>& testAddresses, unsigned int lineSize, cacheResType (*cacheSim)(vector<CacheLine>&, unsigned int, unsigned int), vector<CacheLine>& cache, bool useMemGen)`: Runs the simulation and calculates the hit ratio.
    
- **Test values**:
  - All tests were done on empty caches.
  - Other than testing using the memory address generators, 2 arrays are used to test the simulator using manually written address, with their expected outputs known to validate the output of the simulator.
  - The first test array 'testAddresses[]' makes sure that the basic hits and misses can be identified and updated after the cold start.
  - The second test array 'conflictAddresses[]' tests the difference between the fully associative cache and the direct map cache, as it has conflicting addresses which are handled differently in the direct map cache and the fully associative cache, resulting in a different hit rate.
  - We also tested the capacity conflict and made sure that the program stops/works accordingly.
    
- **Main Function**:
  - `int main()`: Sets up and runs the simulations with different line sizes for both cache configurations.

## Building the Project
- To run the project change the runSimulation() calls in lines 153 and 162 as needed.
- The first runSimulation() call produces the output using a fully associative cache, while the second one uses a direct map cache.
-  'runSimulation(memGen6, conflictAddresses, i, cacheSimFA, fullyAssocCache, 1)' using a format like this one, set the last parameter to 1 if a memory generator function will be used to run the simulator, and set it to 0 if manually-made test addresses in an array will be used.
-  Using this same format, replace 'memGem6' with the required memory generator to be tested, or if using test addresses in an array, replace 'conflictAddresses' with the name of the array
-  If manual test addresses are uses, the hit/miss of each address is outputed one by one in order to be able to validate the output
