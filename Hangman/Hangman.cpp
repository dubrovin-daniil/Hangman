#include <iostream>
#include <string>
#include "HangmanGame.h"

using namespace std;

int main()
{
	HangmanGame game;

	game.createEncryptedFile();
	game.play();
}
