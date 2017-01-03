/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/
#include<stdio.h>
#include<math.h>
void main()
{
	int a,b,c,p;
	int i,max=0,nos;
	int arrp[1001];
	int maxa,maxb,maxc;
	for(i=0;i<1001;i++)
		arrp[i]=0;
	printf("a\tb\tc\tp");
	for(a=1;a<=500;a++)
	{
		for(b=1;b<=500;b++)
		{
			for(c=1;c<=500;c++)
			{	
				p=a+b+c;
				if(a*a+b*b==c*c && p<=1000)
				{
					printf("\n%d\t%d\t%d\t%d",a,b,c,p);
					arrp[p]++;
				}
			}
		}
	}
	for(i=0;i<1001;i++)
	{
		if(arrp[i]>max)
		{
			max=arrp[i];
			p=i;
		}
	}
	//counting happens twice except for middle number
	if(max%2==1)
		nos=max/2 +1;
	else
		nos=max/2;
	printf("\nAnswer\nFor p=%d we get maximum number solution (%d solutions)",p,nos);
}