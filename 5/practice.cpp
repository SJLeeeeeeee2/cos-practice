#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    char str1[6]={'h','e','l','l','o',0}; //0: null terminator, end of the string
    char str2[6]={'w','o','r','l','d',0}; 
    char *p;

    p=str2;

    cout << "str1 = " << str1 << endl; //prints hello
    cout << "str2 = " << str2 << endl; //prints world

    p[-1]=','; //str1의 nullpointer 자리를 ','로 바꿈

    cout << "str1 = " << str1 << endl; //prints hello,world

    return 0;
}