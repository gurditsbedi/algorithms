/*


2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include<stdio.h>

int lcm(int , int);

void main()

{

int i,n,temp=1,result;

printf("Number:");

scanf("%d",&n);

for(i=0;i<=n-1;i++)

	{
	
	result=lcm(temp,i+1);
	
	temp=result;
	
	}

printf("Answer=%d\n",temp);

}

int lcm(int x,int y)

{

int a,b,t,lcm;

a=x;

b=y;

while(b!=0)

	{

	t=b;

	b=a%b;

	a=t;

	}

lcm=(x/a)*y;

return (lcm);

}
