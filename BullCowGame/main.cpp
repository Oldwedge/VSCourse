#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

int main();
void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();
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
		PrintGameSummary();
		PlayAgain = AskToPlayAgain();
	} 
	while (PlayAgain);

	return 0;
}

//introduce the game
void PrintIntro() 
{
	//for future versions, provide method to vary word length
	std::cout << "\n\nWelcome to the Bulls and Cows Game!\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?";
	std::cout << std::endl;
	return;
}

//run the game core
void PlayGame()
{
	//start by resetting the state of the game
	BCGame.Reset();
	
	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";
		
	FBullCowCount BullCowCount;

	do{
		Guess = GetValidGuess();

		BullCowCount = BCGame.SubmitGuess(Guess);
		
		int32 NumberOfBulls = BullCowCount.Bulls;
		int32 NumberOfCows = BullCowCount.Cows;

		std::cout << "You got " << NumberOfBulls << " bulls and " << NumberOfCows << " cows! <<---\n\n";
	}
	while ((!BCGame.IsGameWon()) && (BCGame.GetCurrentGuess() <= BCGame.GetMaxTries()));
	
	return;
}


void PrintGameSummary()
{

	//summarize game, check if the user won and print final result
	if (BCGame.IsGameWon())
	{
		std::cout << "\n*****************************************************\n";
		std::cout << "* Congratulations! You won the game in " << (BCGame.GetCurrentGuess() - 1) << " attempt(s) *\n";
		std::cout << "*****************************************************\n\n";
	}
	else
	{
		std::cout << "\n*********************\n";
		std::cout << "***** GAME OVER *****\n";
		std::cout << "*********************\n\n";
	}
	return;
}

//get valid guess from user
FText GetValidGuess() 
{
	FText Guess = "";
	FText ErrorMessage = "";
	EErrorCodes GuessStatus = EErrorCodes::UNKNOWN;
	//loop to get guesses and print response
	do
	{
		std::cout << "\nTry # " << BCGame.GetCurrentGuess() << " / " << BCGame.GetMaxTries() << ". What is your guess? ";
		//get guess
		
		std::getline(std::cin, Guess);
		
		// validate guess enum
		GuessStatus = BCGame.CheckGuessValidityEnum(Guess);

		//evaluate validation
		switch (GuessStatus)
		{
		case EErrorCodes::SHORT:
			ErrorMessage = "The guess is too short.\n\n";
			break;
		case EErrorCodes::LONG:
			ErrorMessage = "The guess is too long.\n\n";
			break;
		case EErrorCodes::NOT_ISOGRAM:
			ErrorMessage = "The guess is not an isogram.\n\n";
			break;
		case EErrorCodes::NOT_LOWER:
			ErrorMessage = "The guess is not in lower case.\n\n";
			break;
		case EErrorCodes::OK:
			ErrorMessage = "--->> ";
			break;
		case EErrorCodes::UNKNOWN:
			ErrorMessage = "Unknown Error!\n\n";
			break;
		default:
			break;
		}

		std::cout << ErrorMessage;
	
	} while (GuessStatus != EErrorCodes::OK);

	return Guess;
}


bool AskToPlayAgain()
{
	FText Response = "";
	std::cout << "\nDo you want to play again? (y/n) ";
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
