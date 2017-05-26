#include "FBullCowGame.h"
#include <string>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;


int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetCurrentGuess() const { return MyCurrentTries; }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

int32 FBullCowGame::GetMaxTries() const 
{ 	
	TMap<int32, int32> WordLengthToTries{ {3,3},{4,5},{5,6},{6,8} };
	return WordLengthToTries[MyHiddenWord.length()]; 
}

void FBullCowGame::Reset()
{

	const FString HIDDEN_WORD = "bot";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTries = 1;

	bIsGameWon = false;
	return;
}



//testing enum
EErrorCodes FBullCowGame::CheckGuessValidityEnum(FString Guess) const
{
	if (Guess.length() < MyHiddenWord.length())
	{
		return EErrorCodes::SHORT;
	}
	else if (Guess.length() > MyHiddenWord.length())
	{
		return EErrorCodes::LONG;	
	}
	else if (!IsIsogram(Guess))
	{
		return EErrorCodes::NOT_ISOGRAM;
	}
	else if (!IsLowercase(Guess))
	{
		return EErrorCodes::NOT_LOWER;
	}
	else
	{
		return EErrorCodes::OK;	
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

	if (BullCowCount.Bulls == MyHiddenWord.length())
	{
		bIsGameWon = true;
		
	}
	else
	{
		bIsGameWon = false;
	}


	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) {

		Letter = tolower(Letter);

		if (LetterSeen[Letter]) 
		{ 
			return false; 
		}
		else 
		{ 
			LetterSeen[Letter] = true; 
		}
	}
	
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	//loop over each char
	for (auto Letter : Word) 
	{
		if (!islower(Letter)) { return false; }
	}
	return true;
}
