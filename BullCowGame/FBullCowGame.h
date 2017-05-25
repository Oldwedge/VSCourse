#pragma once

#include <string>

class FBullCowGame 
{
public:
	FBullCowGame()
	{
		Reset();
	}

	int GetCurrentGuess() const;
	int GetMaxTries() const;
	bool IsGameWon() const;
	
	void AddTry();
	void Reset();
	bool CheckGuessVlidity(std::string);

private:
	int MyCurrentTries;
	int MyMaxTries;
};
