#include "HangmanGame.h"
#include <iostream>
#include <cstdlib>
#include "vector"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

extern std::vector<std::string> lang;

std::string hangmanMistakes[7] = {
    "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",
    "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",
    "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",
    "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"
};

void HangmanGame::createEncryptedFile() {
    std::ofstream file("words.txt");
    if (!file) std::cout << lang[1] << std::endl;
    else {
        for (auto &w : words) {
            std::string encrypted;
            for (char c : w) encrypted += c + 3;
            file << encrypted << "\n";
        }
        file.close();
    }
}

void HangmanGame::play() {
    system(CLEAR);
    clock_t start = clock();

    char letter;
    bool trueLetter = false;
    int mistakes = 0;
    int attempts = 0;
    std::string playerLetters, playerLettersAll;
    int wordLength = randomWord.length();
    char firstLetter = randomWord[0];
    char lastLetter = randomWord[wordLength - 1];

    std::cout << lang[9] << firstLetter;
    for (int i = 1; i < wordLength - 1; i++) std::cout << "_";
    std::cout << lastLetter << std::endl;

    while (mistakes != 6) {
        std::cout << hangmanMistakes[mistakes];
        std::cout << lang[0];
        std::cin >> letter;

        std::cout << lang[9] << firstLetter;
        for (int i = 1; i < wordLength - 1; i++) {
            if (randomWord[i] == letter) {
                std::cout << randomWord[i];
                trueLetter = true;
                if (playerLetters.find(letter) == std::string::npos)
                    playerLetters.append(1, letter);
            } else if (playerLetters.find(randomWord[i]) != std::string::npos)
                std::cout << randomWord[i];
            else std::cout << "_";
        }
        std::cout << lastLetter << std::endl;

        playerLettersAll.append(1, letter);

        if (!trueLetter) {
            mistakes++;
            std::cout << lang[1] << " " << mistakes << "/6" << std::endl;
            std::cout << lang[3] << std::endl;
            std::cin.ignore();
            std::cin.get();
        } else {
            trueLetter = false;
            std::cout << lang[2] << std::endl;
            std::cout << lang[3] << std::endl;
            std::cin.ignore();
            std::cin.get();
        }
        attempts++;

        bool won = true;
        for (int i = 1; i < wordLength - 1; i++)
            if (playerLetters.find(randomWord[i]) == std::string::npos) { won = false; break; }

        if (won) break;

        system(CLEAR);
        std::cout << lang[9] << firstLetter;
        for (int i = 1; i < wordLength - 1; i++) {
            if (randomWord[i] == letter) {
                std::cout << randomWord[i];
                if (playerLetters.find(letter) == std::string::npos)
                    playerLetters.append(1, letter);
            } else if (playerLetters.find(randomWord[i]) != std::string::npos)
                std::cout << randomWord[i];
            else std::cout << "_";
        }
        std::cout << lastLetter << std::endl;
    }

    clock_t end = clock();
    double timeSpent = double(end - start) / CLOCKS_PER_SEC;

    system(CLEAR);
    std::cout << hangmanMistakes[mistakes] << std::endl;

    if (mistakes < 6) std::cout << lang[4] << randomWord << std::endl;
    else std::cout << lang[5] << randomWord << std::endl;

    std::cout << lang[6] << timeSpent << " seconds" << std::endl;
    std::cout << lang[7] << attempts << std::endl;
    std::cout << lang[8];
    for (char c : playerLettersAll) std::cout << c << " ";
    std::cout << std::endl;
}
