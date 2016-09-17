/*
** Implementaion of the following
** 1. Bubble Sort
** 2. Insertion Sort
** 3. Selectoin Sort
*/

#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int* ,int );
int insertSort(int* ,int );
int selectionSort(int* ,int );
int display(int* ,int );

int main(void ){
	//Sample array
	int a[20]={23,12,24,355,61,28,45,73,29,11,34,25,15,4,56,42,59,87,19,9};
	int n,i,j,choice;

	printf("Enter the Numbers of elements:\t");
	scanf("%d",&n);
	//for custom input
	/*for(i=0;i<n;i++){
		printf("Enter element No.%d:\t",i+1);
		scanf("%d",&a[i]);
	}
	// */
	printf("\nThe Array is:\n");
	display(&a[0],n);
	printf("\n\n");

	//Sorting Menu
	do{
		printf("1. Press 1 for Bubble Sort\n2. Press 2 for Insertion Sort\n
				3. Press 3 for Selection Sort\nEnter Your Choice: ");
		scanf("%d",&choice);
	}
	while(choice<1 || choice>3);
	switch(choice){
		case 1:bubbleSort(&a[0],n);
		break;
		case 2:insertSort(&a[0],n);
		break;
		case 3:selectionSort(&a[0],n);
		break;
		default:exit(0);
	}

	printf("\n\nThe Array after sorting is:\n");
	display(&a[0],n);
	printf("\n");
}

int bubbleSort(int* m,int n){
	int i,j,k=1,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			if(*(m+i)>*(m+i+j)){
				temp=*(m+i);
				*(m+i)=*(m+i+j);
				*(m+i+j)=temp;	
			}
			printf("\n%d ->  ",k++);
			display(m,n);
		}
	}
}

int insertSort(int* m,int n){
	int i,j,k=1,temp;
	for(i=1;i<=n-1;i++){
		j=i;
		while(j>0 && *(m+j)<*(m+j-1)){
			temp=*(m+j);
			*(m+j)=*(m+j-1);
			*(m+j-1)=temp;
			j--;
		}
		printf("\n%d ->  ",k++);
		display(m,n);
	}
}

int selectionSort(int* m,int n){
	int i,j,k=1,min,minPos,key;
	for(i=0;i<n-1;i++){
		key = *(m+i);
		min = *(m+i);
		minPos = i;
		for(j=i;j<n;j++){
			if(*(m+j) < min){
				min = *(m+j);
				minPos = j;
			}
		}
		*(m+i) = *(m + minPos);
		*(m + minPos) = key;
		printf("\n%d ->  ",k++);
		display(m,n);
	}
}

int display(int* m,int n){
	int i;
	for(i=0;i<n-1;i++){
		printf("%d, ",*(m+i));
	}
	printf("%d",*(m+i));
}