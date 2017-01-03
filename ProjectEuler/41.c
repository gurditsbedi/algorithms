/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int numlen(float );
int numsum(float );
int prime_chk(float );
int pndgtl_chk(float );
int main(void ){
	int i;
	for(i=7654321;i>=1234;i=i-2){//for the logic given below the prime pandigital should be of 4 or 7 digits only (7654321<req no.>999)
		//If sum of digits of a pandigital number are 1,3,6,10,15,21,28,36,45 simply 10,28 or multiple of 3. And if sum of digits is a multiple of 3 then the number is divisible by 3. Hence not prime.
		if(numsum(i)==10 || numsum(i)==28){ 
			if(prime_chk(i)==0 && pndgtl_chk(i)==0){
					//since i am counting in descending order first encountered number is the required number
					printf("\n***Answer***\nLargest Pandigital Prime = %d\n",i);
					exit(0);
			}
		}
	}
}
int numlen(float n){
	int c=0;
	while(n!=0){
		c++;
		n=floor(n/10);
	}
	return c;
}
int numsum(float n){
	int sum=0;
	while(n!=0){
		sum+=fmodf(n,10);
		n=floor(n/10);
	}
	return sum;
}
int prime_chk(float n){//Inputs are odd numbers
	int c=0,i;
	for(i=3;i<sqrt(n);i=i+2){
		if(fmodf(n,i)==0)
			c++;
	}
	return c;
}
int pndgtl_chk(float n){
	int i,j,nl=numlen(n);
	float tester,testcmp=0,nwork;
	for(i=1;i<=nl;i++){
		nwork=n;
		tester=fmodf(n,10);
		if(tester>nl || tester==0)
			return 1;//Not true
		for(j=1;j<=nl-i;j++){
			nwork=floor(nwork/10);
			testcmp=fmodf(nwork,10);
			if(testcmp>nl || testcmp==0 || testcmp==tester )
				return 1; //Not true
		}
		n=floor(n/10);
	}
	return 0;//True
}
