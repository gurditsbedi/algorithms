/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include<stdio.h>
#include<math.h>
int prime(int);
int main(void)
{
	int i,n,max;
	double sum=0;
	for(i=2;i<=2000000;i++)
	{
		n=i;
		if(prime(n)==1)
		{
			sum=sum+(double)n;
		}
	}
	printf("%.0lf\n",sum);
}
int prime(int n)
{
	int i,c=0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			c++;
			break;
		}
	}
	if(c==0)
	return 1;
	else
	return 0;
}
