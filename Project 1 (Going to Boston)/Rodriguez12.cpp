/*
 * Rodriguez4.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: Jonathan Rodriguez
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
//#define AUTOBET

using namespace std;

int main ()
{
	int UserM = 1000;
	int CompM = 1000;
	int UD1, UD2, UD3, CD1, CD2, CD3; // UD = User Dice . CD = Computer Dice
	int UserBet, UserSum, CompSum, RoundNum = 0; 
	srand(time(0));
	
	while (true) {
		UD1 = rand () % 6+1;
		UD2 = rand () % 6+1;
		UD3 = rand () % 6+1;
		CD1 = rand () % 6+1;
		CD2 = rand () % 6+1;
		CD3 = rand () % 6+1;
		++RoundNum;
		
		cout << "[Round " << RoundNum << "] You Rolled (" << UD1 << "," << UD2 << "," << "?),";
		cout << " machine rolled (" << CD1 << "," << CD2 << "," << "?)...";

		cout << "\nHow much are you going to bet: ";
// Preprocessor Directive

	#ifndef AUTOBET
		cin >> UserBet; 
	#else // Logic for Deetermining Bet
		if (UD1 + UD2 <= 6) {
			UserBet = rand()%5+1; 
		}
		else if (UD1 + UD2 >= 7) {
			UserBet = rand()%5+6;
		}
		cout << "" << UserBet << '\n';
	#endif
		
	while (UserBet > 10 || UserBet < 1 ) {
		cout << "your bet must be between $1 and $10, type again: ";
		cin >> UserBet;
		}

// User Calculations	
		
	if (UD1 == UD2 && UD2 == UD3) {
		UserSum = UD1 + UD2 + UD3;
		cout << "You Had (" << UD1 << "," << UD2 << "," << UD3 << ") ... Big Fish !!! \n";
	}
	else if (UD1 < UD2 || UD1 < UD3) {
		cout << "You had (" << UD1 << "," << UD2 << "," << UD3 << ") -> You Rolled (";
		UD1 = rand()%6+1;
		cout << UD1 << "," << UD2 << ") and then rolled (" << UD3 << ") -> ";
		UserSum = UD1 + UD2 + UD3;
		cout << "You Scored " << UserSum << ".\n";
	}
	else if (UD2 < UD1 || UD2 < UD3) {
		cout << "You had (" << UD1 << "," << UD2 << "," << UD3 << ") -> You Rolled (";
		UD2 = rand()%6+1;
		cout << UD1 << "," << UD2 << ") and then rolled (" << UD3 << ") -> ";
		UserSum = UD1 + UD2 + UD3;
		cout << "You Scored " << UserSum << ".\n";
	}
	else if (UD3 < UD1 || UD3 < UD2) {
		cout << "You had (" << UD1 << "," << UD2 << "," << UD3 << ") -> You Rolled (";
		UD3 = rand()%6+1;
		cout << UD1 << "," << UD2 << ") and then rolled (" << UD3 << ") -> ";
		UserSum = UD1 + UD2 + UD3;
		cout << "You Scored " << UserSum << ".\n";
	}
	else {
		break;
	}
	
// Computer Calculations
	
	if (CD1 == CD2 && CD2 == CD3) {
		CompSum = CD1 + CD2 + CD3;
		cout << "Machine Had (" << CD1 << "," << CD2 << "," << CD3 << ") ... Big Fish !!! \n";
	}
	else if (CD1 < CD2 || CD1 < CD3) {
		cout << "Machine had (" << CD1 << "," << CD2 << "," << CD3 << ") -> Machine Rolled (";
		CD1 = rand()%6+1;
		cout << CD1 << "," << CD2 << ") and then rolled (" << CD3 << ") -> ";
		CompSum = CD1 + CD2 + CD3;
		cout << "Machine Scored " << CompSum << ".\n";
	}
	else if (CD2 < CD1 || CD2 < CD3) {
		cout << "Machine had (" << CD1 << "," << CD2 << "," << CD3 << ") -> Machine Rolled (";
		CD2 = rand()%6+1;
		cout << CD1 << "," << CD2 << ") and then rolled (" << CD3 << ") -> ";
		CompSum = CD1 + CD2 + CD3;
		cout << "Machine Scored " << CompSum << ".\n";
	}
	else if (CD3 < CD1 || CD3 < CD2) {
		cout << "Machine had (" << CD1 << "," << CD2 << "," << CD3 << ") -> Machine Rolled (";
		CD3 = rand()%6+1;
		cout << CD1 << "," << CD2 << ") and then rolled (" << CD3 << ") -> ";
		CompSum = CD1 + CD2 + CD3;
		cout << "Machine Scored " << CompSum << ".\n";
	}
	else {
		break;
	}

// Multiplier of Betting & Winning or Losing
	if ((UD1 == UD2 && UD2 == UD3) == CompSum){
		UserM += UserBet * 50;
		CompM -= UserBet * 50;
		cout << "You Win :) ";
	}
	else if ((CD1 == CD2 && CD2 == CD3) == UserSum){
		UserM -= UserBet * 50;
		CompM += UserBet * 50;
		cout << "You Lose :( ";
	}
	else if (((UD1 == UD2 && UD2 == UD3) && (CD1 == CD2 && CD2 == CD3)) || (UserSum == CompSum)){
		cout << "Tied! ";
	}
	else if (UD1 == UD2 && UD2 == UD3){
		UserM += UserBet * 50;
		CompM -= UserBet * 50;
		cout << "You Win :) ";
	}
	else if (CD1 == CD2 && CD2 == CD3) {
		UserM -= UserBet * 50;
		CompM += UserBet * 50;
		cout << "You Lose :( ";
	}
	else if (UserSum > CompSum) {
		UserM += UserBet * (UserSum - CompSum);
		CompM -= UserBet * (UserSum - CompSum);
		cout << "You Win :) ";
	}
	else if (UserSum < CompSum){
		UserM += UserBet * (UserSum - CompSum);
		CompM -= UserBet * (UserSum - CompSum);
		cout << "You Lose :( ";
	}
	else {
		break;
	}
	cout << "You have $" << UserM << "," << " machine has $" << CompM << "...\n\n"; 

	// End of Betting Game	

	if (UserM <= 0) {
		cout << "You Lost the game! \n";
		break;
	}
	else if (CompM <= 0) {
		cout << "You Won the Game! \n";
		break;
		}
	else
		continue;
	}
}