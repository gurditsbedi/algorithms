#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 12
#define NUMLEN 3 // Length of digits in the file
int main(){
	FILE *fp;
	int i, j, k, temp, check, count;
	int numList[50];
	int code[10][SIZE] = { [0 ... 9 ] [ 0 ... (SIZE-1) ] = -1};// all elements become ( -1 )
	char output[256];
	char list[50][3];
		
	//opening of the file
	fp = fopen("p079_keylog.txt","r");
	
	if (fp == NULL){
	    printf("Error opening file!\n");
	    exit(1);
	}

	//copying the 50 numbers given in the file int a array
	//while(1){
	for( i = 0; fgets(output,sizeof(output),fp) != NULL; i++){
		//printf("Line %d: %s", i+1 , output);
		numList[i] = atoi(output);
	}
	
	//closing the file
	fclose(fp);
	
	//printing the number list array
	/*printf("The numList is (Integer)\n");
	for( i=0 ; i<50 ; i++){
		printf("%d\n",numList[i]);
	}
	printf("\n\n\n");*/
	
	//Checking of the available digits
	//floor(log10(numList[0])) + 1 is used to find the length of an integer
	for( i=0 ; i<50 ; i++){
		for(j=0 ; j< floor(log10(numList[0])) + 1; j++){ 
			temp =	(int)( numList[i]/pow(10,j) );
			code[temp%10][10] = temp%10;
		}
	}
	
	//CONVERSION of the numList into a 2-D char ARRAY
	for( i=0 ; i<50 ; i++ ){
		for( j=0 ; j<NUMLEN ; j++){
			temp =	(int)( numList[i]/pow(10,j) );
			list[i][NUMLEN - j-1] = temp%10;
		}
	}
	
	//List ARRAY PRINTING
	/*
	printf("printing the LIST ARRAY	( CHAR):\n");
	for( i=0 ; i<50 ; i++ ){
		for( j=0 ; j<NUMLEN ; j++){
			printf("%d\t",list[i][j]);
		}
		printf("\n");
	}*/
	
	//printing the code matrix
	/*printf("printing the code matrix:\n");
	for( i=0 ; i<10 ; i++){
		for( j=0 ; j<SIZE ; j++){
			//printf("%d-%d = %d\t",i , j, code[i][j]);
			//printf("%d-%d\t",i , j);
			printf("%d\t",code[i][j]);
		}
		printf("\n");
	}*/
	
	//The Analyzer process
	for( i=0 ; i<50 ; i++){
		for( j=0 ; j<NUMLEN-1 ; j++){
			/*temp =	(int)( numList[i]/pow(10,j) );
			check = temp%10;*/
			for( k=0 ; k< NUMLEN - j-1 ; k++){
				code[ list[i][NUMLEN - j -1] ][ list[i][NUMLEN - j-1 - (k+1) ] ] = 1;
			}
		}
	}
	
	/*printf("printing the code matrix 2nd Time:\n");
	for( i=0 ; i<10 ; i++){
		for( j=0 ; j<SIZE ; j++){
			//printf("%d-%d = %d\t",i , j, code[i][j]);
			//printf("%d-%d\t",i , j);
			printf("%d\t",code[i][j]);
		}
		printf("\n");
	}*/
	
	//Arranging the numbers
	for( i=0 ; i<10 ;i++){
		count = 0;
		for( j=0 ; j<12-2 ; j++){
			if( code[i][j] == -1 && code[i][10] != -1 )
				count++;
		}
		if( code[i][10] != -1 )
			code[i][11]= (12-2)-count;
	}
	
	/*printf("printing the code matrix 3rd Time :\n");
	for( i=0 ; i<10 ; i++){
		for( j=0 ; j<SIZE ; j++){
			//printf("%d-%d = %d\t",i , j, code[i][j]);
			//printf("%d-%d\t",i , j);
			printf("%d\t",code[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	
	//printing thr answer
	printf("The Number is ");
	check = 0;
	for( i=0 ; i<10 ; i++ ){
		//printf("\ni = %d \t check = %d , \t",i,check);
		for( j=0 ; j<10 ; j++ ){
			if ( code[j][10] != -1 && code[j][11] == check)
				printf("%d", code[j][10] );
		}
		check++;
	}
	
	printf("\n");
	return 0;
}

