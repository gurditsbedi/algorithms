/*
** This is a simple program which outputs all the possible combination of 
** a string. 
*/
#include <iostream>

using namespace std;

//counter for listing the output with a number
int i=1;

int permutator( string  str, int s, int e){
    char t;
    if ( s==e){
        //for listing the output with a number
        cout<< i++<< "\t";
        //print the permuted string
        cout<< str<< endl;
        return 0;
    }
    for( int i=s; i<e; i++){
        //swap str[s] and str[i]
        t = str[s];
        str[s] = str[i];
        str[i] = t;

        //The great - RECURSION
        permutator( str, s+1, e);

        //swap str[s] and str[i] again
        //returning to original position
        t = str[s];
        str[s] = str[i];
        str[i] = t;
    }
}

int main(){
    string str = "";
    cout<< "Enter a string: ";
    cin>> str;
    permutator( str, 0, str.length() );
    return 0;
}
