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
    int counter=0;
    do{
        cout << "Insert a number: ";
        cin >> x;
        counter++;
    }
    while (check_validity(x)!=1);

    numbers=(int *)malloc(sizeof(int)*counter);

    return 0;
}