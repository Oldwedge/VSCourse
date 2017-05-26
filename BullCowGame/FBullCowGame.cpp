#include "FBullCowGame.h"
#include <algorithm>
#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetCurrentGuess() const { return MyCurrentTries; }

void FBullCowGame::Reset()
{
	constexpr int32 MAXIMUM_TRIES = 8;
	MyMaxTries = MAXIMUM_TRIES;

	const FString HIDDEN_WORD = "bogus";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTries = 1;
	return;
}

bool FBullCowGame::IsGameWon(FBullCowCount BullCowCount) const
{

	if (BullCowCount.Bulls == MyHiddenWord.length()) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//testing enum
EErrorCodes FBullCowGame::CheckGuessValidityEnum(FString Guess) const
{
	bool LengthIsCorrect = false;
	bool IsIsogram = false;
	
	if (Guess.length() < MyHiddenWord.length())
	{
		//tell user guess is too short
		return EErrorCodes::SHORT;
		LengthIsCorrect = false;

	}
	else if (Guess.length() > MyHiddenWord.length())
	{
		//tell user guess is too long
		return EErrorCodes::LONG;
		LengthIsCorrect = false;
	}
	else if (Guess.length() == MyHiddenWord.length())
	{
		//correct
		LengthIsCorrect = true;
	}
	else
	{
		//should not happen, let's return false and maybe return a error message
		return EErrorCodes::UNKNOWN;
		LengthIsCorrect = false;
	}


	//loop to check that guess is an isogram
	if (LengthIsCorrect)
	{

		FString GuessChar = "";
		FString GuessCompare = "";

		for (int32 i = 0; i < Guess.length(); i++)
		{

			GuessChar = Guess[i];

			for (int32 j = 0; j < Guess.length(); j++)
			{

				GuessCompare = Guess[j];

				if (i != j && GuessChar == GuessCompare)
				{

					IsIsogram = false;

					//ugly workaround to break outer loop as well
					i = Guess.length() + 1;
					return EErrorCodes::NOT_ISOGRAM;
					break;

				}
				else
				{

					IsIsogram = true;

				}

			}

		}

	}
	
	return EErrorCodes();
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTries++;
	
	FBullCowCount BullCowCount;

	FString UserGuess = Guess;
	FString LetterToCompare = "";
	FString HiddenWordLetter = "";

	//get hidden word length
	int32 HiddenWordLength = MyHiddenWord.length();

	//loop through all letters in the guess
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		LetterToCompare = UserGuess[i];
		// compare guess with hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			HiddenWordLetter = MyHiddenWord[j];
			//if they match then
			if (LetterToCompare == HiddenWordLetter && i == j) 
			{
				BullCowCount.Bulls++;
			} 
			else if (LetterToCompare == HiddenWordLetter && i != j) 
			{
				BullCowCount.Cows++;
			}
			else
			{
				//do nothing
			}	
		}
	}
	return BullCowCount;
}

FString FBullCowGame::LowerCaseGuess(FString Guess)
{

	FString LowGuess = Guess;

	transform(LowGuess.begin(), LowGuess.end(), LowGuess.begin(), ::tolower);

	return LowGuess;
	
}
