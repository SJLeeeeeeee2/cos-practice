#include <iostream>
using namespace std;
int check_validity(int x){
    if (x>0&&x<11)
        return 1;
    else{
        cout << "Please try again with another value." << endl;
        return 0;
    }
}

int main(int argc, char *argv[]){
    int i,x;
    int *numbers;
    do{
        cout << "Insert the number of inputs: ";
        cin >> x;
    }
    while (check_validity(x)!=1);

    numbers=(int *)malloc(sizeof(int)*x);
    for (i=0;i<x;i++){
        cout << "Please input " << i+1 << "th number: ";
        cin >> numbers[i];
    }
    for (i=0;i<x;i++){
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }

    return 0;
}