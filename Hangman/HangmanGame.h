#pragma once
#include <iostream>
#include <string>

using namespace std;

class HangmanGame
{
private:
	// Fields
	string words[10] = { "bread", "table", "window", "phone", "corner", "forge", "store", "work", "friend", "family" };
	string randomWord;
public:
	// Constructor
	HangmanGame() {
		srand(time(nullptr));

		randomWord = words[rand() % 10];
	}

	// Methods
	void createEncryptedFile();
	void play();
};

