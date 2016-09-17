/* This is solution for the program listed on hackerrank.com
 * URL : https://www.hackerrank.com/challenges/coin-change
 */
#include <iostream>

using namespace std;

// Definfing Array Length Limits
#define AMT 260 // Amount to be considered
#define NOC 60 // No of coins available

int main(){
	long long int amount, noOfCoins, currCoin;
	long long int coins[NOC];
	long long int calc[NOC][AMT];


	cin >> amount >> noOfCoins;
	for(int i = 0; i < noOfCoins; i++){
		cin >> coins[i];
	}

	// setting 1st row to 0
	for (int i = 0; i < amount+1; i++) {
		calc[0][i] = 0;
	}
	// setting 1st column to 1
	for (int i = 0; i < noOfCoins+1; i++) {
		calc[i][0] = 1;
	}

	// The is the block where the Algorithm does its job.
	for(int i = 1; i < noOfCoins+1; i++){
		currCoin = coins[i-1];
		for(int j = 1; j < amount+1; j++){
			if( currCoin > j){
				calc[i][j] = calc[i-1][j];
			} else {
				calc[i][j] = calc[i - 1][j] + calc[i][j-currCoin];
			}
		}
	}

	// For viweing the printed array. just add/remove a single backslash in
	// front the next line to uncomment/comment the whole block.
	/*
	std::cout << "0->\t";
	for (int j = 0; j < amount + 1; j++) {
		std::cout << calc[0][j] << "\t";
	}
	std::cout << std::endl;
	for(int i = 1; i < noOfCoins+1; i++){
		std::cout << coins[i-1] << "->\t";
		for(int j = 0; j < amount+1; j++){
			std::cout << calc[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	//*/

	// The Required Answer
	std::cout << calc[noOfCoins][amount] << std::endl;

	return 0;
}
