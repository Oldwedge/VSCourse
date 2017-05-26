#pragma once

#include <string>

using FString = std::string;
using int32 = int;

//all values initializes as 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

//enum to handle error feedback
enum class EErrorCodes
{
	OK,
	SHORT,
	LONG,
	NOT_ISOGRAM,
	NOT_LOWER,
	UNKNOWN
};

class FBullCowGame 
{
public:
	//class constructor 
	FBullCowGame()
	{
		//calling method to do the constructor work 
		Reset();
	}

	int32 GetCurrentGuess() const;
	int32 GetMaxTries() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	void Reset();
	//method to return validity check and error message enum
	EErrorCodes CheckGuessValidityEnum(FString Guess) const;
	//EErrorCodes CheckGuessValidity(FString Guess) const;
	//provide method to return bulls and cows
	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 MyCurrentTries;
	FString MyHiddenWord;
	bool bIsGameWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
