/*
** A solution to the famous 'Maximum Sub-array Sum'.
** Also available on www.hackerrank.com/challenges/maxsubarray
*/

#include <iostream>
using namespace std;

int main(){
	int noOfCases, size, sumPositive=0, max_so_far, curr_max, l=0;
	int a[100001];

	cin>> noOfCases;
	for(int i0=0; i0<noOfCases; i0++){
		//input
		cin>> size;
		for( int i=0; i<size; i++){
			cin>> a[i];
		}
		//processing
        sumPositive = 0; l=0;
        max_so_far = a[0]; curr_max = a[0];
		for( int i=1; i<size; i++){
			if(a[i]>0){
                sumPositive += a[i];
			}

			if( a[i]<0){
				l++;
			}

            curr_max = max(a[i], curr_max+a[i]);
            max_so_far = max(max_so_far, curr_max);
//            cout<< max_so_far<<" " << sumPositive<< endl;
//            cout<< "-------"<<endl;
		}
		if( a[0]>0)
			sumPositive += a[0];
		if( a[0]<0){
			l++;
		}
		if( l==size){
			sumPositive = max_so_far;
		}
		cout<< max_so_far<<" " << sumPositive<< endl;
	}
	return 0;
}
