/*
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/
#include<stdio.h>
#include<math.h>
void main()
{
	double n=1000,temp,sum=0,pdt=1;
	int i,j;
	printf("Enter the Number: %.0lf",n);
	//scanf("%lf",&n);
	for(i=1;i<=n;i++)
	{
		pdt=1;
		temp=i;
		for(j=1;j<=i;j++)
		{
			pdt=pdt*temp;
			//pdt=fmod(pdt,1000000000);
			pdt=fmod(pdt,pow(10,11));
		}
		sum=sum+pdt;
	}
	printf("\n%.0lf\n",fmod(sum,pow(10,10)));
}
