#include <iostream>
#include "human.h"
using namespace std;
//implement
int main(){
    Human *hw;
    hw=new Human("Hyunwoo Lee");
    hw->print();
    hw->setAge(40);
    hw->print();
}
//g++ -c human.cpp main.cpp
//g++ -o human human.o main.o