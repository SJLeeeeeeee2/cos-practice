#include <iostream>
using namespace std;

int run(){
    char str[6]={'h','e','l','l','o',0}; 
    char *p;

    p=str;

    for (int i=0;i<32;i++)
        cout << "p[" << i << "] = " << hex << (0xff&p[i]) << endl; 
    //prints the hexcode of the hello and blabla
    return 0;
}

int main(int argc, char *argv[]){
    cout << "main = " << (void *)main << endl; //address of the main function, 0x623e25dd12d6
    run();

    return 0;
}