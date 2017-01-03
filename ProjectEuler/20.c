/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/
#include<stdio.h>
#define NUM 200//Array size
int main(){
	int i,j,k,n=100,temp,sum=0;
	int a[NUM];
	printf("\nFor the Problem, Number is 100\nEnter the Number : ");
	scanf("%d",&n);
	for(k=0;k<NUM;k++)
		a[k]=0;
	a[0]=1;
	for(i=1;i<=n;i++){
		j=0;
		a[j]*=i;
		while(j<NUM){//this loop also makes each and every element of the array of unit digit
			temp=a[j];
			a[j]=a[j]%10;
			a[j+1]=a[j+1]*i+temp/10;
			j++;
		}
	}
	printf("\n");
	for(k=NUM-1;k>=0;k--){//Finding the first non-zero array element's index
		if(a[k]!=0)
			break;
	}
	printf("\n%d! = ",n);
	while(k>=0){
		//printf("\na[%d]=%d",k,a[k]);
		printf("%d",a[k]);
		sum+=a[k];
		k--;
	}
	printf("\n***Answer***\nThe sum of digits of %d! = %d\n",n,sum);
	return 0;
}

