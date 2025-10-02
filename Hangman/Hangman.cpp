#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include "HangmanGame.h"
#include <algorithm>

namespace fs = std::filesystem;

std::vector<std::string> lang;
std::vector<std::string> words;

bool loadTextFile(const std::string &path, std::vector<std::string> &target) {
    std::ifstream file(path);
    if (!file.is_open()) return false;
    target.clear();
    std::string line;
    while (std::getline(file, line)) target.push_back(line);
    return true;
}

std::string selectLanguage(const std::string &langDir) {
    std::vector<std::string> available;
    if (!fs::exists(langDir) || !fs::is_directory(langDir)) {
        std::cerr << "Language directory not found: " << langDir << "\n";
        return "";
    }

    for (auto &p : fs::directory_iterator(langDir)) {
        if (p.path().extension() == ".txt")
            available.push_back(p.path().stem().string());
    }

    if (available.empty()) {
        std::cerr << "No language files found in: " << langDir << "\n";
        return "";
    }

    std::cout << "Available languages:\n";
    for (auto &l : available) std::cout << "- " << l << "\n";

    std::string choice;
    while (true) {
        std::cout << "Select language: ";
        std::cin >> choice;
        if (std::find(available.begin(), available.end(), choice) != available.end())
            break;
        std::cout << "Invalid language!\n";
    }
    return choice;
}

int main() {
    std::string baseDir = "../lang"; // Ajusta según la ubicación de build/
    std::string langDir = baseDir + "/lang";
    std::string wordsDir = baseDir + "/words";

    std::string langCode = selectLanguage(langDir);
    if (langCode.empty()) return 1;

    if (!loadTextFile(langDir + "/" + langCode + ".txt", lang)) {
        std::cerr << "Failed to load language file.\n";
        return 1;
    }

    if (!loadTextFile(wordsDir + "/" + langCode + ".txt", words)) {
        std::cerr << "Failed to load words file.\n";
        return 1;
    }

    HangmanGame game(words);
    game.createEncryptedFile();
    game.play();
    return 0;
}
