#include "FBullCowGame.h"
#include <iostream>

using FString = std::string;
using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentGuess() const { return MyCurrentTries; }

void FBullCowGame::AddTry()
{
	MyCurrentTries++;
	return;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAXIMUM_TRIES = 8;
	MyMaxTries = MAXIMUM_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTries = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessVlidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//return variable for result
	FBullCowCount BullCowCount;
	//increase try counter
	MyCurrentTries++;
	
	//put the provided guess in a variable
	FString UserGuess = Guess;
	FString LetterToCompare = "";
	FString HiddenWordLetter = "";
	//get hidden word length
	int32 HiddenWordLength = MyHiddenWord.length();

	//loop through all letters in the guess
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		//couldn't find a better way
		LetterToCompare = UserGuess.substr(i,1);
		
		// compare guess with hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			//get the hidden word letter
			//std::cout << "\nComparing '" << LetterToCompare << "' with ";
			HiddenWordLetter = MyHiddenWord.substr(j, 1);
			//std::cout << "'" << HiddenWordLetter << "'. ";
			//if they match then
			if (LetterToCompare == HiddenWordLetter && i == j) {
				//increment Bulls if they are in the same place
				BullCowCount.Bulls++;
				//std::cout << "Perfect match!\n";
			} else if (LetterToCompare == HiddenWordLetter && i != j) {
				//increment cows if not
				BullCowCount.Cows++;
				//std::cout << "Right letter, wrong position!\n";
			} else {
				//do nothing
				//std::cout << "Not even close!\n";
				
			}
				
				
		}
	
	}
	
	return BullCowCount;
}
