#include <iostream>
#include <string>
#include "HangmanGame.h"

using namespace std;

int main()
{
	srand(time(nullptr));

	HangmanGame game;
	game.play();
}
