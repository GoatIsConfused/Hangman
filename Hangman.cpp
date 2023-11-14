#include <iostream>
#include <string>
#include <ctime>

char letters[] = {'_', '_', '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' };
std::string phrases[] = { "pool", "egg", "fire", "sun", "arm", "bacon and eggs", "police man", "words", "im playing hangman"};
int failedLetters = 0;
bool guessResult;
int maxFails = 12;

bool wordNotCompleted(std::string word) {
	for (int x = 0; x != word.length(); x++) {
		if (word[x] == '_') {
			return true;
		}
	}
	return false;
}

int main()
{
	srand(time(NULL)); // initialize rand with seed of current time
	int chosenPhrase = rand() % (sizeof(phrases) / sizeof(phrases[0]));

	std::string phraseOutput = "";

	for (int x = 0; x != phrases[chosenPhrase].length(); x++) { // Builds output string to be displayed to the user
		if (phrases[chosenPhrase][x] != ' ') {
			phraseOutput += "_";
		}
		else {
			phraseOutput += " ";
		}
	}

	while (failedLetters < maxFails && wordNotCompleted(phraseOutput)) {
		std::cout << "Letters: ";
		for (int x = 0; x != sizeof(letters); x++) {
			std::cout << letters[x] << " ";
		}
		std::cout << std::endl;

		std::cout << "Word: " << phraseOutput << std::endl << "Failed Letters: " << failedLetters << "/" << maxFails << std::endl << "What letter do you want to pick? ";

		char input;
		std::cin >> input;
		int index = input - 'a'; // gives a number between 0 and 25
		if (letters[index] == input) { // Verify input hasn't been already done
			std::cout << "You have guessed that letter already!" << std::endl;
			continue;
		}
		letters[index] = input;

		guessResult = false;

		for (int x = 0; x != phrases[chosenPhrase].length(); x++) { // Adds the letter to where ever it fits in phraseOutput
			if (phrases[chosenPhrase][x] == input) {
				guessResult = true;
				phraseOutput[x] = input;
			}
		}

		if (guessResult == false) {
			failedLetters += 1;
		}
	}

	if (!wordNotCompleted(phraseOutput)) {
		std::cout << "Congratulations you win the word was: " << phrases[chosenPhrase] << std::endl;
	}
	else {
		std::cout << "Oh no you didn't get it :(. The word was: " << phrases[chosenPhrase] << std::endl;
	}

	return 0;
};
