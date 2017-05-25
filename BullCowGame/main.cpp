#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

int main();
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

//entry point
int main() 
{
	bool PlayAgain = false;

	do 
	{		
		PrintIntro();
		PlayGame();
		PlayAgain = AskToPlayAgain();
	} 
	while (PlayAgain);

	return 0;
}

//introduce the game
void PrintIntro() 
{
	//TODO provide method to vary word length
	constexpr int32 WORD_LENGTH = 6;
	std::cout << "Welcome to the Bulls and Cows Game!\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n";
	std::cout << std::endl;
	return;
}

//run the game core
void PlayGame()
{
	//start by resetting the state of the game
	BCGame.Reset();
	
	int32 MaxTries = BCGame.GetMaxTries();
	
	//loop a number of turns to get guesses and print back
	//TODO change from for to while loop
	for (int32 counter = 1; counter <= MaxTries; counter++)
	{
		std::cout << "Try number " << BCGame.GetCurrentGuess() << ". What is your guess? ";
		//TODO validate guess 

		//submit valid guess and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(GetGuess());
		//print result (bulls and cows)
		int32 NumberOfBulls = BullCowCount.Bulls;
		int32 NumberOfCows = BullCowCount.Cows;

		std::cout << "You got " << NumberOfBulls << " bulls and " << NumberOfCows << " cows." << std::endl;
		//TODO summarize game
	}
	return;
}

//get guess from user
FText GetGuess() 
{
	FText Guess = "";
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain()
{
	FText Response = "";
	std::cout << "Do you want to play again? (y/n) ";
	std::getline(std::cin, Response);
	if ((Response[0] == 'Y') || (Response[0] == 'y'))
	{
		return true;
	}
	else if ((Response[0] == 'N') || (Response[0] == 'n'))
	{
		return false;
	}
	else 
	{
		std::cout << "\nWrong input! Exitting...\n";
		return false;
	}	
}
