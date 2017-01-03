/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/
#include<stdio.h>
#include<math.h>
#define NUM 99
int chckr(double ,double );
int main(){
	int nmr,dnr,rtrn,nmrpdt=1,dnrpdt=1;//numerator,denominator,retrun , suffix pdt implies product
	double frac;//fraction
	int i=0,x,y,z;
	int a[8];
	for(dnr=NUM;dnr>=1;dnr--){
		for(nmr=10;nmr<dnr;nmr++){
			if(nmr%10==0 && dnr%10==0)//cancellation of trivial cases eg. 40/90
				continue;
			if(nmr/10==dnr/10 || nmr/10==dnr%10 || nmr%10==dnr/10 || nmr%10==dnr%10){//only creating non trivial fractions
				frac=(double)nmr/dnr;
				printf("\n%d/%d = %lf",nmr,dnr,frac);
				rtrn=chckr(nmr,dnr);
				if(rtrn==1){
					printf("\tCaught You!");
					a[i]=nmr;
					a[i+1]=dnr;
					i+=2;
				}
			}
		}
	}
	printf("\n\n\nThe fractions are:\n");
	for(i=0;i<8;i++){
		printf("%d",a[i]);
		if(i%2==0){
			nmrpdt*=a[i];
			printf("/");
		}
		else{
			dnrpdt*=a[i];
			printf("\n");
		}
	}
	printf("The product of these fraction is %d/%d",nmrpdt,dnrpdt);
	x=nmrpdt;
	y=dnrpdt;
	//lowest form part
	while(y!=0){
		z=y;
		y=x%y;
		x=z;
	}
	//HCF is X, so divideding by x we get the reduced fraction
	printf(" = %d/%d\n",nmrpdt/x,dnrpdt/x);
	return 0;
}
int chckr(double nmr,double dnr){
	double nmrd,dnrd,fracd;//d implies dash
	double frac;
	double a[8];
	int i=0;
	double* ptr;
	frac=nmr/dnr;
	if(floor(nmr/10)==floor(dnr/10)){
		nmrd=fmod(nmr,10);
		dnrd=fmod(dnr,10);
		if(nmrd>=dnrd){
			printf("\tfraction>=1");
			return -1;
		}
	}
	if(floor(nmr/10)==fmod(dnr,10)){
		nmrd=fmod(nmr,10);
		dnrd=floor(dnr/10);
		if(nmrd>=dnrd){
			printf("\tfraction>=1");
			return -1;
		}
	}
	if(fmod(nmr,10)==floor(dnr/10)){
		nmrd=floor(nmr/10);
		dnrd=fmod(dnr,10);
		if(nmrd>=dnrd){
			printf("\tfraction>=1");
			return -1;
		}
	}
	if(fmod(nmr,10)==fmod(dnr,10)){
		nmrd=floor(nmr/10);
		dnrd=floor(dnr/10);
		if(nmrd>=dnrd){
			printf("\tfraction>=1");
			return -1;
		}
	}
	fracd=nmrd/dnrd;
	printf("\t%.0lf/%.0lf=%lf",nmrd,dnrd,fracd);
	if(frac==fracd){
		return 1;
	}
	return 0;
}
