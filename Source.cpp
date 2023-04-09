#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

string chooseWord(vector<string> words)
{
    srand(time(NULL));
    int random = rand() % words.size();
    return words[random];
}

void displayGame(int incorGuessCount)
{
    cout << " _________  " << endl;
    cout << "|         | " << endl;
    cout << "|         " << (incorGuessCount >= 1 ? "O" : "") << "   " << endl;
    cout << "|        " << (incorGuessCount >= 2 ? "/" : "") << (incorGuessCount >= 3 ? "|" : "") << (incorGuessCount >= 4 ? "\\" : "") << endl;
    cout << "|        " << (incorGuessCount >= 5 ? "/" : "") << " " << (incorGuessCount >= 6 ? "\\" : "") << endl;
    cout << "|              " << endl;
    cout << "|              " << endl;
    cout << "===============" << endl;
}

void displayWord(string word, vector<char> guessedLetters) {
    cout << "Word: ";
    for (int i = 0; i < word.length(); i++) {
        if (find(guessedLetters.begin(), guessedLetters.end(), word[i]) != guessedLetters.end()) {
            cout << word[i];
        }
        else {
            cout << "_";
        }
    }
    cout << endl;
}

void displayStats(time_t startTime, int incorGuessCount, string word, vector<char> guessedLetters) {
    time_t endTime = time(NULL);
    double totalTime = difftime(endTime, startTime);
    cout << endl;
    cout << "Time: " << totalTime << " seconds" << endl;
    cout << "Incorrect guesses: " << incorGuessCount << endl;
    cout << "Word: " << word << endl;
    cout << "Your Guesses: ";
    for (int i = 0; i < guessedLetters.size(); i++) {
        cout << guessedLetters[i] << " ";
    }
    cout << endl;
}

void main() {
    vector<string> words{ "computer", "programming", "algorithm", "software", "developer", "robot" };

    string word = chooseWord(words);

    int incorGuessCount = 0;

    vector<char> guessedLetters;

    time_t startTime = time(NULL);

    while (incorGuessCount < 6) {
        displayGame(incorGuessCount);
        displayWord(word, guessedLetters);

        cout << "Guess a letter: ";
        char guess;
        cin >> guess;

        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You already guessed that letter. Try again." << endl;
            continue;
        }
        guessedLetters.push_back(guess);

        if (word.find(guess) != string::npos) {
            cout << "Correct!" << endl;
        }
        else {
            cout << "Incorrect." << endl;
            incorGuessCount++;
        }

        bool wordGuessed = true;
        for (int i = 0; i < word.length(); i++) {
            if (find(guessedLetters.begin(), guessedLetters.end(), word[i]) == guessedLetters.end()) {
                wordGuessed = false;
                break;
            }
        }
        if (wordGuessed) {
            cout << "Congratulations! You guessed the word." << endl;
            break;
        }
    }

    displayGame(incorGuessCount);
    displayWord(word, guessedLetters);
    displayStats(startTime, incorGuessCount, word, guessedLetters);

}