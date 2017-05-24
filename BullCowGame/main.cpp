#include <iostream>
#include <string>

using namespace std;

int main();

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

//Entry point
int main() 
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();

	return 0;
}

//introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to the Bulls and Cows Game!\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram?\n";
	return;
}

//run the game core
void PlayGame()
{
	
	//constexpr to control guess limit of the game
	constexpr int GUESS_LIMIT = 5;

	//loop a number of turns to get guesses and print back
	for (int counter = 1; counter <= GUESS_LIMIT; counter++)
	{
		cout << "What is your guess? ";
		cout << "Your guess was: " << GetGuess() << endl;
		cout << endl;
	}
	return;
}

//get guess from user
string GetGuess() 
{
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	string Response = "";
	cout << "Do you want to play again? (y/n) ";
	getline(cin, Response);
	if ((Response[0] == 'Y') || (Response[0] == 'y'))
	{
		cout << "\n returns True";
		return true;
	}
	else if ((Response[0] == 'N') || (Response[0] == 'n'))
	{
		cout << "\n returns False";
		return false;
	}
	else 
	{
		cout << "Wrong input! Exitting...";
		return false;
	}	
}
