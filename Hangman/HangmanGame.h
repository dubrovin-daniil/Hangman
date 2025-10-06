#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class HangmanGame
{
private:
	// Fields
	string words[10];
	string randomWord;
public:
	// Constructor
	HangmanGame() {
		srand(time(nullptr));

		decryptedWords();
		randomWord = words[rand() % 10];
	}


	// Methods
	void decryptedWords();
	void play();
};

