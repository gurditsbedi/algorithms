/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double prime(double );
void main()
{
double n,i,a,max=0;
printf("Enter the number: ");
scanf("%lf",&n);
a=n/2;
for(i=1;i<n/2;i=i+2)
	{
	//printf("i=%.0lf",i);
	if(fmod(n,i)==0)
		{
		n=n/i;
		//printf("n=%.0lf\ti=%.0lf\tmax=%.0lf\n",n,i,max);
		if(prime(i)==1)
			{
			if(i>max)
				{
				max=i;
				}
			}
		}
	}
printf("n=%.0lf\tmax=%.0lf\n",n,max);
max=(max>n)?max:n;//conditional operator (condtion?true:false)
printf("%.0lf\t\n",max);
}
double prime(double n)
{
double i,c=0;
for(i=1;i<=n;i++)
	{
	if(fmod(n,i)==0)
	c++;
	}
if(c==2)
return 1;
else
return 0;
}
