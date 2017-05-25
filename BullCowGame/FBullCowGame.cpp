#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentGuess() const { return MyCurrentTries; }

void FBullCowGame::AddTry()
{
	MyCurrentTries++;
	return;
}

void FBullCowGame::Reset()
{
	constexpr int MAXIMUM_TRIES = 8;
	MyMaxTries = MAXIMUM_TRIES;
	MyCurrentTries = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessVlidity(std::string)
{
	return false;
}
