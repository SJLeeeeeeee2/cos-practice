#include <iostream>

int main(int argc, char *argv[]){
	int fahr, celsius;
	int lower, upper, step;
	lower = ascii_to_int(argv[1]);
	upper = ascii_to_int(argv[2]);
	step = ascii_to_int(argv[3]);
	fahr = lower; //";"

	while (fahr<=upper){
		celsius = 5 * (fahr - 32) /9; // Cel(x) cel(o)
		std::cout << "fahr: " << fahr << "\tcelsius:" << celsius << std::endl; //"std::"
		fahr = fahr + step;
	}
	return 0;
}

int ascii_to_int(char *str){
	char c;
	c = str[0];

	return c - 0x30;
}
