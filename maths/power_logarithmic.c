#include <stdio.h>
#include <stdlib.h>

int power(int x,int y);

int main(int argc,char **argv){
	int result = power(atoi(argv[1]),atoi(argv[2]));
	printf("%d\n", result);
	return 0;
}

// Function to calculate x raised to the power of y using divide and conquer
int power(int x,int y){
	// Base case: any number raised to the power of 0 is 1
	if(y == 0) {
		return 1;
	}
	
	// If y is even, use the property (x^y) = (x^(y/2)) * (x^(y/2))
	if(y % 2 == 0) {
		return power(x, y / 2) * power(x, y / 2);
	}
	
	// If y is odd, use the property (x^y) = x * (x^((y-1)/2)) * (x^((y-1)/2))
	return x * power(x, (y - 1) / 2) * power(x, (y - 1) / 2);
}
