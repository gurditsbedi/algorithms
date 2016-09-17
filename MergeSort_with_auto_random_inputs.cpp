/*
** Implementaion of famous 'Merge-Sort' in cpp
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define LOA 9 //LOA: length of array

int merge(int num[], int s, int c, int e){
    int temp[LOA] = {0};
    int pos1 = s, pos2 = c+1;
    for( int i=0; i<e-s+1; i++){
    	//For debugging purpose
        //cout<<endl; for(int j=0; j<e-s+1; j++){ cout<< temp[j]<< "\t"; }

    	//If any of the 2 parts get completely ended. then this code executes.
        if( pos1 > c ){
            //cout<<"pos1 > c"<<endl; //For debugging purpose
            while( pos2 <= e){
                temp[i] = num[pos2];
                i++; pos2++;
            }
            break;
        } else if( pos2 > e){
            //cout<< "pos2 > e"<<endl; //For debugging purpose
            while( pos1 <= c){
                temp[i] = num[pos1];
                i++; pos1++;
            }
            break;
        }

        //The regular checking for smallest number in any of the so called subarrays
        if( num[pos1] < num[pos2]){
            //cout<<"num[pos1] < num[pos2]"; //For debugging purpose
            temp[i] = num[pos1];
            pos1++;
        } else if( num[pos2] < num[pos1]){
            //cout<<"num[pos2] < num[pos1]"; //For debugging purpose
            temp[i] = num[pos2];
            pos2++;
        } else {
        	//cout<< "num[pos2] == num[pos1]"; //For debugging purpose
            temp[i] = num[pos1];
            temp[i+1] = num[pos2];
            pos1++; pos2++; i++;
        }
    }

    //For debugging purpose
    //cout<<"temp->>"; for(int i=0; i<e-s+1; i++){ cout<< temp[i]<< "\t"; }

    //To copy the contents of temp array into original array
	for(int i=s; i<e+1; i++){ num[i] = temp[i-s]; }

	//For debugging purpose
	//cout<< endl;for(int i=0; i<LOA; i++){ cout<< num[i]<< "\t"; }
}

void partition(int num[], int s, int e){

    //For debugging purpose
	//cout<< "----->"<< s<< "\t"<< e<< "\t\t"; for( int i = s; i<=e; i++){cout<< num[i]<< "\t";}cout<< endl;


	if( s<e){
        int center = (s+e)/2;
        partition( num, s, center);
        partition( num, center+1, e);
        merge( num, s, center, e);
        //see each phase
        for(int i=0; i<LOA; i++){ cout<< num[i]<< "\t"; } cout<< endl;
	}
}

int main(){
    int numbers[LOA];

    srand((unsigned)time(0));
    //input the array wiht random numbers
    for(int i0 = 0; i0 < LOA; i0++){ numbers[i0]=rand()%(99-11+1)+11 ; }//{ numbers[i0]= temp%10; temp /=10;}

    //Print the intial array
    cout<< "Original:  ";
   	for(int i=0; i<LOA; i++){
   		cout<< numbers[i]<< " ";
   	}
   	cout<<"\n\n";

   	//initiation of sorting
    partition( numbers, 0, LOA-1);

	//print the sorted Array
	cout<<"\n";
	cout<< "Sorted:  ";
	for(int i=0; i<LOA; i++){
		cout<< numbers[i]<< " ";
	}
    cout<<endl;
    return 0;
}
