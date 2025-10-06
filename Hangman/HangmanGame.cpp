#include "HangmanGame.h"


using namespace std;


string hangmanMistakes[7] = {
	// 0 mistakes
	"  +---+\n"
	"  |   |\n"
	"      |\n"
	"      |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	// 1 mistakes
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	"      |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	// 2 mistakes
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	"  |   |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	// 3 mistakes
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	" /|   |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	// 4 mistakes
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	" /|\\  |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	// 5 mistakes
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	" /|\\  |\n"
	" /    |\n"
	"      |\n"
	"=========\n",

	// 6 mistakes
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	" /|\\  |\n"
	" / \\  |\n"
	"      |\n"
	"=========\n"
};

// Creates a file "words.txt" with encrypted words
//void HangmanGame::createEncryptedFile() {
//	ofstream file("words.txt");
//
//	if (!file) {
//		cout << "Error open file!" << endl;
//	}
//	else {
//		for (int i = 0; i < 10; i++) {
//			string encryptedWord = "";
//			for (int j = 0; j < words[i].length(); j++) {
//				char encrypt = words[i][j] + 3;
//				encryptedWord += encrypt;
//			}
//			file << encryptedWord << endl;
//		}
//		file.close();
//	}
//}

// Decrypts words from file
void HangmanGame::decryptedWords() {
	ifstream file("EncryptedWords.txt");
	string line;
	int index = 0;

	if (!file) {
		cout << "Error opening file!" << endl;
	}
	while (getline(file, line) && index < 10) { // Read words from file
		string decryptedWord = "";
		for (char letter : line) {
			decryptedWord += letter - 3;
		}
		words[index++] = decryptedWord;
	}

	file.close();
}


// Main game logic
void HangmanGame::play() {
	clock_t start = clock(); // Start time 

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
		trueLetter = false;

		cout << hangmanMistakes[mistakes] << endl;

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

			cout << "Enter any key to continue..." << endl;
			cin.ignore();
			cin.get();
		}
		else {
			trueLetter = false;
			cout << "Correct letter!" << endl;

			cout << "Enter any key to continue..." << endl;
			cin.ignore();
			cin.get();
		}
		attempts++;

		bool value = true;
		for (int i = 1; i < wordLength - 1; i++) {
			if (playerLetters.find(randomWord[i]) == string::npos) {
				value = false;
				break;
			}
		}
		if (value) {
			break;
		}
		system("cls");

		cout << "Word: " << firstLetter;
		for (int i = 1; i < wordLength - 1; i++) {
			if (randomWord[i] == letter) {
				cout << randomWord[i];
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

		cout << "Letters you used: ";
		for (int i = 0; i < playerLettersAll.length(); i++) {
			cout << playerLettersAll[i] << " ";
		}
		cout << endl;
	}
	clock_t end = clock();
	double timeSpent = double(end - start) / CLOCKS_PER_SEC;

	system("cls");

	if (mistakes < 6) {
		cout << hangmanMistakes[mistakes] << endl;

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
		cout << hangmanMistakes[mistakes] << endl;

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





