/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<stdio.h>
int check(int);
void main()
{
int i,j,i1=0,j1=0,x=0,max=0,a=0;
for(i=1;i<=998;i++)
	{
	for(j=1;j<=998;j++)
		{
		/*printf("i=%d\tj=%d\n",i,j);*/
		x=i*j;
		/*printf("%d\n",x);*/
		a=check(x);
		if(a==1)
			{
			if(x>max)
				{
				max=x;
				i1=i;
				j1=j;
				}
			}
		}
	}
printf("%d X %d=%d\n",i1,j1,max);
}
int check(int x)
{
int reverse=0,n;
n=x;
while(n!=0)
	{
	reverse=reverse*10;
	reverse=reverse + n%10;
	n=n/10;
	}
if(x==reverse)
return 1;
else 
return 0;
}
