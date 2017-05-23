#include <iostream>
#include <string>

using namespace std;

int main() 
{
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to the Bulls and Cows Game!\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram?\n";

	//get guess from user
	string Guess = "";
	cout << "What is your guess? ";
	cin >> Guess;
	//repeat
	cout << "Your guess was " << Guess << endl;

	return 0;
}