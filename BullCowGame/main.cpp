#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

int main();
void PrintIntro();
void PlayGame();
FText GetValidGuess();
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
	//for future versions, provide method to vary word length
	std::cout << "Welcome to the Bulls and Cows Game!\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?\n";
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

		std::cout << "You got " << NumberOfBulls << " bulls and " << NumberOfCows << " cows." << std::endl;
	}
	while ((!BCGame.IsGameWon(BullCowCount)) && (BCGame.GetCurrentGuess() <= BCGame.GetMaxTries()));

	//summarize game, check if the user won and print final result
	if (BCGame.IsGameWon(BullCowCount) == true) {
		std::cout << "\n**************************************\n";
		std::cout << "* Congratulations! You won the game! *\n";
		std::cout << "**************************************\n\n";
	}
	else
	{	
		std::cout << "\n*************\n";
		std::cout << "* GAME OVER *\n";
		std::cout << "*************\n\n";
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
		std::cout << "Try number " << BCGame.GetCurrentGuess() << ". What is your guess? ";
		//get guess
		
		std::getline(std::cin, Guess);
		std::cout << std::endl;
		//send for convertion
		Guess = BCGame.LowerCaseGuess(Guess);

		// validate guess enum
		GuessStatus = BCGame.CheckGuessValidityEnum(Guess);

		//evaluate validation
		switch (GuessStatus)
		{
		case EErrorCodes::SHORT:
			ErrorMessage = "The word is too short.";
			break;
		case EErrorCodes::LONG:
			ErrorMessage = "The word is too long.";
			break;
		case EErrorCodes::NOT_ISOGRAM:
			ErrorMessage = "The word is not an isogram.";
			break;
		case EErrorCodes::OK:
			ErrorMessage = "";
			break;
		case EErrorCodes::UNKNOWN:
			ErrorMessage = "Unknown Error!";
			break;
		default:
			break;
		}

		std::cout << ErrorMessage << std::endl;
	
	} while (GuessStatus != EErrorCodes::OK);

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
