/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12
It turns out that the conjecture was false.
What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int perfectSqrtCheck(int );
int primeCheck(int );
void main(){
	int i,j,num,check;
	for(i=5;i>0;i+=2){//infinte loop with odd numbers
		check=0;
		if(primeCheck(i)!=0){//sending only composite numbers futher
			//suitable prime number finding and checking	
			for(j=3;j<i;j+=2){
				if(primeCheck(j)==0){
					num = (i-j)/2;
					if(perfectSqrtCheck(num)==0){
						printf("\n%d = %d + 2*(%.0f^2)",i,j,sqrt(num));
						check=1;
						break;
					}
				}	
				else
					continue;
			}
			if(check!=1){//condition for getting the required number
				printf("\n\nAnswer = %d\n",i);
				exit(0);
			}
		}
	}
}
int perfectSqrtCheck(int x){
	if(sqrt(x)==(int)sqrt(x)){
		return 0;//perfect square
	}
	else{
		return  1;//not a perfect square
	}
}
int primeCheck(int n){
	int i,c=0;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
			c++;
	}
	return c;//if prime returns 0
}
