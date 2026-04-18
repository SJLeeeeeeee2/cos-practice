#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    char str1[6]={'h','e','l','l','o',0}; //0: null terminator, end of the string
    char str2[6]={'w','o','r','l','d',0}; //null terminator는 공백으로 출력
    char *p;

    p=str2;

    cout << "str1 = " << str1 << endl; //prints hello
    cout << "str2 = " << str2 << endl; //prints world
    
    for (int i=-10;i<10;i++)
        cout << "p[" << i << "] = " << p[i] << endl; 
    //prints 00000hello world 0000 / 0: random char, 깨져있을수도
    return 0;
}