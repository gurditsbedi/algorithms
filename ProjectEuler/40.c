/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d(n) represents the nth digit of the fractional part, find the value of the following expression.

d(1) × d(10) × d(100) × d(1000) × d(10000) × d(100000) × d(1000000)
*/#include<stdio.h>
#include<math.h>
int position(int );
int number(int ,int ,int );
int numlen(int );
int main(){
	int i,a,product=1;
	for(i=0;i<=6;i++){
		a=pow(10,i);
		printf("\n%d\t\t",a);
		product*=position(a);
	}
	printf("\n***Answer***\nproduct=%d\n",product);
	//position(i);
}
int position(int n){
	int i,j,subpos,pos,quo,mod;
	int a=numlen(n),temp=0,tempt=0;
	/**/
	//printf("\nEnter the number: %d",n);
	for(i=1;i<a;i++){
		tempt+=9*i*pow(10,i-1);
		if(tempt<n){
			temp=tempt;
		}
		//printf("\t**temp=%d",temp);
	}
	//printf("\ntemp=%d\ttempt=%d",temp,tempt);
	if(n>=pow(10,a-1) && n<=tempt)
		a--;
	pos=(n-temp)/a;
	subpos=(n-temp)%a;
//	printf("\npos=%d\nsubpos=%d",pos,subpos);
	i=pow(10,a-1)+pos;
	//if(n>=pow(10,a-1) && n<=tempt)
//	printf("\t\ni=%d",i);
	if(subpos==0)
		i--;
//	printf("\tiiiii=%d",i);
	return number(i,numlen(n-temp),subpos);
}
int number(int i,int a,int subpos){
	char str[10]="";
	int out;
	sprintf(str,"%d",i);
	//printf("\nstring way:%s",str);
	if(subpos!=0){
		out=str[subpos-1]-'0';
	}
	else{
		out=str[numlen(i)-subpos-1]-'0';
	}
	printf("\t%d",out);
	return out;
}
int numlen(int n){
	int c=0;
	while(n!=0){
		c++;
		n/=10;
	}
	return c;
}
