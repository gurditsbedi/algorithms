/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/
#include<stdio.h>
#define MAX 1000000
int numlen(int );
int primetest(int );
int permutator(int );
int small(int );
int main(){
	int i,count=1;
	/*
	since 2 is a circular prime number and counting 
	starts from 3 and tests only odd numbers.
	so count=1.
	*/
	permutator(i);
	for(i=3;i<=MAX;i=i+2){
		if(small(i)==0 && primetest(i)==0){
			if(permutator(i)==1)
				count++;
				//printf("\ncount=%d for  %d",count,i);
		}
	}
	printf("\n*cps are: %d",count);
	return 0;
}
int primetest(int n){
	int i,c=0;
	for(i=2;i<=n/2;i++){
		if(n%i==0)
			c++;
	}
	return c;
}
int permutator(int n){
	int i,j=1,temp,orin;
	int c,cdash=1;
	int a[10];
	printf("\nNumber received=%d",n);
	orin=n;
	for(i=0;i<10;i++){
		a[i]=-1;
	}
	//printf("input of number into array form");
	i=1;
	while(n!=0){
		a[i]=n%10;
		n/=10;
		i++;
	}
	n=orin;
	c=numlen(n);
	//printf("\nc=%d",c);
	//printf("\n%d",n);
	//circular permutations program
	while(j<c){
		i=9;
		while(i>0){
			if(a[i]!=-1){
				temp=a[i];
				while(a[i]!=-1){
					a[i]=a[i-1];
					i--;
					if(i==1){
						a[i]=temp;
						break;
					}
				}
			}
		i--;
		}
		i=9;
		n=0;
		while(i>=0){
			if(a[i]!=-1){
				n=n*10+a[i];
			}
			//printf("\n%d",n);
			i--;
		}
	//printf("\n%d",n);
	//checking part
	if(primetest(n)==0)
		cdash++;
	//printf("\n%d",cdash);
	j++;
	}
	//printf("\nbf_ch c=%d\tcdash=%d",c,cdash);
	if(c==cdash){
		printf("\nThe number %d is a circular prime",orin);
		return 1;
	}
	else 
		return 0;
}
int numlen(int x){
	int c=0;
		while(x!=0){
		x/=10;
		c++;
	}
	return c;
}
int small(int n){
	//if(n%5==0)
		//return 1;
	while(n!=0){
		if(n%2==0)
			return 1;
		n/=10;
	}
	return 0;
}
