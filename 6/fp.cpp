#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct human_st{
    const char *name;
    int age;
    void (*print)(struct human_st *); //function pointer
} human_t;

void print_info(human_t *p){
    cout << "name: " << p->name << " age: " << p->age << endl;
}

int main(int argc, char *argv[]){
    human_t *hw; //struct human_st *hw;

    hw=(human_t *)malloc(sizeof(human_t));
    hw->name="Hyunwoo";
    hw->age=40;
    hw->print=print_info;

    hw->print(hw);
    return 0;
}