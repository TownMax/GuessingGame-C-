#include <iostream>
using namespace std;

void playGame() {
    const int secretNumber = 62;
    int guess;
    int lives = 3;

    cout << "\n--- Guessing Game ---\n";
    cout << "Guess the number between 1 and 100. You have " << lives << " lives.\n";

    while (lives > 0) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << "(❁´◡`❁)...... Correct! You guessed the number.\n";
            return;
        } else {
            lives--;

            // "Close" check without abs()
            if ((guess > secretNumber && guess <= secretNumber + 10) ||
                (guess < secretNumber && guess >= secretNumber - 10)) {
                cout << "^_^.... You're close! ";
            } else {
                cout << "(●'◡'●)..... Wrong guess. ";
            }

            if (lives > 0) {
                cout << "You have " << lives << " lives left.\n";
            } else {
                cout << "\n💀 Game Over! The correct number was " << secretNumber << ".\n";
            }
        }
    }
}

int main() {
    char choice;

    do {
        playGame();

        cout << "\nWhat would you like to do next?\n";
        cout << "R - Restart the game\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice (R/Q): ";
        cin >> choice;

        // Convert to uppercase manually and safely
        if (choice == 'r') choice = 'R';
        else if (choice == 'q') choice = 'Q';

        switch (choice) {
            case 'R':
                cout << "\nRestarting the game...\n";
                break;
            case 'Q':
                cout << "\nThanks for playing!\n";
                break;
            default:
                cout << "\nInvalid input! Quitting by default...\n";
                choice = 'Q';
        }

    } while (choice == 'R');

    return 0;
}
