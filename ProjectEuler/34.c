#include <stdio.h>
#include <math.h>

int factorial(int );

int main(void) {
	int n=10, i,nTemp;
	int sum = 0, megaSum = 0;
	// The calculation of upper bound is inmportant
	/*
	 since the largest sum of factorials we can produce from an 8-digit number is itself a 7-digit number (set all digits equal to 9 and look at 8 *9!, which only has 7 digits). So, we know the numbers that we're looking at are at most 7-digit numbers.
	*/
	printf("\n");
	for(n = 10; n < 9*factorial(9) + 1; n++){
		sum = 0;
		nTemp = n;
		for(i = 0; i < (int)floor(log10(n))+1; i++ ){
			sum += factorial(nTemp%10);
			nTemp /= 10;
		}
		if (sum == n){
			printf("\n--------------Found One--------------\n%d\n",n);
			megaSum += n;
		}
	}
	printf("\nAnswer =\t%d\n", megaSum);
}

int factorial(int n){
	int pdt = 1 , i;
	for(i=1 ; i<=n ; i++ ){
		pdt *= i;
	}
	return pdt;
}
