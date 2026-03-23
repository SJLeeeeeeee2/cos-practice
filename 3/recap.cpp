#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

	int num1, num2, sum;
	cout << "Enter first integer: ";
	cin >> num1;
	cout << "Enter second integer: ";
	cin >> num2;
	sum=0;

	if (num1<=num2){
		for (int i=num1; i<=num2; i++){
			sum+=i;
		}
		cout << sum << endl;
	} else {
		cerr << "Error! The first integer must be smaller than the second integer!" << endl;
		return 1; //terminate immediately
	}
	
	return 0;
}
