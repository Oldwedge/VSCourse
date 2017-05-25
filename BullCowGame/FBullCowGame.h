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
	bool IsGameWon() const;
	
	void AddTry();
	void Reset();
	bool CheckGuessVlidity(FString);

	//provide method to return bulls and cows
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTries;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
