/*
 * Phubeth Mettaprasert
 * Driver class to test the two scenarios.
 */

#include <iostream>
#include "memory.h"

void scenario1();
void scenario2();

int main() {
    scenario1();
    scenario2();


}

void scenario1() {
    std::cout << "SCENARIO 1:\n==========\n";
    Memory memory(100, 15);
    memory.lw(1,1);
    memory.lw(2,5);
    memory.lw(3,1);
    memory.lw(3,7);
    memory.lw(2,7);
    memory.printReport();
    std::cout << std::endl;
}

void scenario2() {
    std::cout << "SCENARIO 2:\n==========\n";
    Memory memory(300, 15);
    memory.lw(3,6);
    memory.lw(0,12);
    memory.lw(1,4);
    memory.lw(2,12);
    memory.lw(3,8);
    memory.printReport();
    std::cout << std::endl;
}



