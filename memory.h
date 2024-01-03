/*
 * Phubeth Mettaprasert
 * HWK8 LRU Caches
 * Simulates an LRU cache using arrays and a clock counter.
 */


#ifndef LRU_CACHE_MEMORY_H
#define LRU_CACHE_MEMORY_H


//A class designed to simulate LRU cache
class Memory {
public:
    Memory(int initialNum, int size) {
        initializeMemoryArray(size, initialNum);
        initializeReg();
        initializeCache();
        hit = 0;
        miss = 0;
    }

    //Uses dynamic memory so a destructor is needed
    ~Memory() {
        delete [] memory;
        delete [] registers;
        delete [] cache;
        memory = nullptr;
        registers = nullptr;
        cache = nullptr;
    }


    //Load word and stores cache management
    void lw(int regIndex, int address) {

        bool found = false;
        int index = 0;
        while(!found && index < SIZE_CACHE) {
            if(cache[index].data == memory[address]){
                found = true;

                //If it is found update the clockcounter for the existing cache
                cache[index].clock = clockCounter;
                clockCounter++;

                //Increment the hit.
                hit++;
                registers[regIndex] = cache[index].data;
                return;
            }
            index++;
        }

        //If it is not found increment the miss.
        miss++;


        //Store the new cache line
        int tempIndex = 0;
        int smallestClock = cache[tempIndex].clock;
        for(int i = 1; i < SIZE_CACHE; i++) {
            if(smallestClock > cache[i].clock) {
                tempIndex = i;
                smallestClock = cache[i].clock;
            }
        }

        cache[tempIndex].valid = 1;
        cache[tempIndex].tag = address;
        cache[tempIndex].data = memory[address];
        cache[tempIndex].clock = clockCounter;
        clockCounter++;
        registers[regIndex] = cache[tempIndex].data;
    }

    //Used to print out the registers.
    void printRegister() {
        for(int i =0;i < REG_SIZE; i++ ) {
            std::cout << "r" << i << ": " << registers[i] << std::endl;
        }
    }

    //Print out the hits
    void printHit() {
        std::cout << "Hits: " << hit << std::endl;
    }

    //Print out the misses
    void printMiss() {
        std::cout << "Misses: " << miss << std::endl;
    }

    //Prints out the cache
    void printCache() {
        sortCache();
        for(int i = 0; i < SIZE_CACHE; i++) {
            std::cout<< "cache line " << i << ": v=" << cache[i]
            .valid << " tag=" << cache[i].tag << " data=" << cache[i]
            .data;
            if(i == 0) {
                std::cout << " LRU";
            }
            std::cout << std::endl;
        }
    }

    //Combination to print out the whole thing
    void printReport() {
        printRegister();
        printCache();
        printHit();
        printMiss();
    }


private:

    //The struct that stores the cache_line
    struct cache_line {
        int valid;
        int tag;
        int data;
        int clock;
    };

    //The pointers to the arrays.
    int * memory;
    int * registers;
    cache_line * cache;

    //Constraints
    int const SIZE_CACHE = 2;
    int const REG_SIZE = 4;


    int clockCounter = 0;
    int miss;
    int hit;


    void initializeMemoryArray(int size, int initialNum) {
        memory = new int[size];
        for(int i = 0; i < size;i++) {
            memory[i] = initialNum;
            initialNum += 10;
        }
    }

    void initializeReg() {
        registers = new int[REG_SIZE];
        for(int i = 0; i < REG_SIZE; i++) {
            registers[i] = 0;
        }
    }

    void initializeCache() {
        cache = new cache_line[SIZE_CACHE];
        for(int i = 0; i < SIZE_CACHE; i++) {
            cache[i].valid = 0;
            cache[i].tag = -1;
            cache[i].data = -1;
            cache[i].clock = -1;
        }
    }


    //Sort the cache at the end by the clock counter in order to get it to
    // print nicely.
    void sortCache() {
        for(int i = 0; i < SIZE_CACHE - 1; i++) {
            for(int j =0; j < SIZE_CACHE - i - 1;j++) {
                if(cache[j].clock > cache[j+1].clock) {
                    std::swap(cache[j], cache[j+1]);
                }
            }
        }
    }
};





#endif //LRU_CACHE_MEMORY_H
