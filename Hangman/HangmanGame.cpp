#include "HangmanGame.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Creates a file "words.txt" with encrypted words
void HangmanGame::createEncryptedFile() {
	FILE* file;

	errno_t err = fopen_s(&file, "words.txt", "w");

	if (err) {
		cout << "Error open file!" << endl;
	}
	else {
		for (int i = 0; i < 10; i++) {
			int encryptedWord;
			for (int j = 0; j < words[i].length(); j++) {
				encryptedWord = (words[i][j] / 2 + words[i][j] * 3);
			}
			fprintf(file, "%d\n", encryptedWord);
		}
		fclose(file);
	}
}

// Main game logic
void HangmanGame::play() {
	clock_t start = clock();

	char letter;
	bool trueLetter = false;
	int mistakes = 0;
	int attempts = 0;
	string playerLetters = "";
	string playerLettersAll = "";
	int wordLength = randomWord.length();
	char firstLetter = randomWord[0];
	char lastLetter = randomWord[wordLength - 1];


	cout << "Word: " << firstLetter;
	for (int i = 1; i < wordLength - 1; i++) {
		cout << "_";
	}
	cout << lastLetter << endl;

	while (mistakes != 6) {
		cout << "Enter a letter: ";
		cin >> letter;
		cout << "Word: " << firstLetter;
		for (int i = 1; i < wordLength - 1; i++) {
			if (randomWord[i] == letter) {
				cout << randomWord[i];
				trueLetter = true;
				if (playerLetters.find(letter) == string::npos) {
					playerLetters.append(1, letter);
				}
			}
			else if (playerLetters.find(randomWord[i]) != string::npos) {
				cout << randomWord[i];
			}
			else {
				cout << "_";
			}
		}
		cout << lastLetter << endl;

		playerLettersAll.append(1, letter);

		if (!trueLetter) {
			mistakes++;
			cout << "Wrong letter! Mistakes: " << mistakes << "/6" << endl;
		}
		else {
			trueLetter = false;
		}
		attempts++;

		if (playerLetters.length() == wordLength - 2) {
			break;
		}
	}
	clock_t end = clock();
	double timeSpent = double(end - start) / CLOCKS_PER_SEC;

	system("cls");

	if (mistakes < 6) {
		cout << "You won! The word you guessed is: " << randomWord << endl;
		cout << "Time spent: " << timeSpent << " seconds" << endl;
		cout << "Attempts: " << attempts << endl;
		cout << "Letters you used: ";
		for (int i = 0; i < playerLettersAll.length(); i++) {
			cout << playerLettersAll[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "You lost! The word was: " << randomWord << endl;
		cout << "Time spent: " << timeSpent << " seconds" << endl;
		cout << "Attempts: " << attempts << endl;
		cout << "Letters you used: ";
		for (int i = 0; i < playerLettersAll.length(); i++) {
			cout << playerLettersAll[i] << " ";
		}
		cout << endl;
	}
}





