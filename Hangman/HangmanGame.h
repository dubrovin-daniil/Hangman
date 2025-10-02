#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <vector>
#include <string>
#include <ctime>
#include <fstream>

class HangmanGame {
public:
    HangmanGame(const std::vector<std::string> &w) : words(w) {
        srand(time(nullptr));
        randomWord = words[rand() % words.size()];
    }

    void createEncryptedFile();
    void play();

private:
    std::vector<std::string> words;
    std::string randomWord;
};

#endif
