#include <iostream>
#include <string>
#include "FBullCowGame.h"

int main();

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

//Entry point
int main() 
{

	do 
	{
		PrintIntro();
		PlayGame();
		//AskToPlayAgain();
	} 
	while (AskToPlayAgain());

	return 0;
}

//introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to the Bulls and Cows Game!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram?\n";
	return;
}

//run the game core
void PlayGame()
{
	BCGame.Reset();
	
	int MaxTries = BCGame.GetMaxTries();
	
	//loop a number of turns to get guesses and print back
	for (int counter = 1; counter <= MaxTries; counter++)
	{
		std::cout << "Try number " << BCGame.GetCurrentGuess() << ". What is your guess? ";
		std::cout << "Your guess was: " << GetGuess() << std::endl;
		std::cout << std::endl;
		BCGame.AddTry();
	}
	return;
}

//get guess from user
std::string GetGuess() 
{
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::string Response = "";
	std::cout << "Do you want to play again? (y/n) ";
	std::getline(std::cin, Response);
	if ((Response[0] == 'Y') || (Response[0] == 'y'))
	{
		//std::cout << "\n returns True";
		return true;
	}
	else if ((Response[0] == 'N') || (Response[0] == 'n'))
	{
		//std::cout << "\n returns False";
		return false;
	}
	else 
	{
		std::cout << "\nWrong input! Exitting...\n";
		return false;
	}	
}
