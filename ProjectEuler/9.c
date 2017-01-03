/*


A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
#include<stdio.h>
void main()
{
	int a, b, c, maxa = 0, maxb = 0, maxc = 0;
	for (a = 0; a <= 1000; a++)
	{
		for (b = 0; b <= 1000; b++)
		{
			c = 1000 - a - b;
			if (a * a + b * b == c * c)
			{
				if (maxa < a && maxb < b && maxc < c)
				{
					maxa = a;
					maxb = b;
					maxc = c;
				}
			}
		}
	}
	printf("%d\t%d\t%d\t%d\n", maxa, maxb, maxc, maxa * maxb * maxc);
}
