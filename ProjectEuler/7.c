/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/
#include<stdio.h>
long int prime(long int);
void main()
{
	long int i=1,n=0,c=0;
	printf("Prime number number: ");
	scanf("%ld",&n);
	while(i<=n)
	{
		while(1)
		{
			if(prime(i)==1)
			c++;
			if(c==n)
			{
				printf("%ld\n",i);
				break;
			}
			i++;
		}
	}
}
long int prime(long int n)
{
	long int i=0,c=0;
	if(n==2||n==3||n==5)
	return 1;
	if(n%2==0)
	return 0;
	if(n%3==0)
	return 0;
	if(n%5==0)
	return 0;
	else
	{
		for(i=1;i<=n;i=i+2)
		{
			if(n%i==0)
			c++;
		}
		if(c==2)
		//printf("1");
		return 1;
		else
		//printf("0");
		return 0;
	}
}
	
	
