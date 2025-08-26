#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int playGame(int bestScore) {
    int minVal, maxVal;
    cout << "\n Welcome to the Number Guessing Game!\n";

    // Get range from user
    do {
        cout << "Enter minimum number: ";
        cin >> minVal;
        cout << "Enter maximum number: ";
        cin >> maxVal;
        if (minVal >= maxVal) {
            cout << " Minimum must be less than maximum. Try again.\n";
        }
    } while (minVal >= maxVal);

    // Generate random number
    srand(time(0));
    int secretNumber = rand() % (maxVal - minVal + 1) + minVal;

    // Attempts allowed (30% of range, between 5–15)
    int maxAttempts = (maxVal - minVal) * 0.3;
    if (maxAttempts < 5) maxAttempts = 5;
    if (maxAttempts > 15) maxAttempts = 15;

    cout << "\nYou have " << maxAttempts << " attempts to guess the number!\n";

    int attempts = 0, guess;
    bool won = false;

    while (attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << " → Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << " Correct! You guessed it in " << attempts << " attempts.\n";

            if (bestScore == -1 || attempts < bestScore) {
                bestScore = attempts;
                cout << " New best score!\n";
            }

            cout << "Your best score so far: " << bestScore << " attempts.\n";
            won = true;
            break;
        }
        else if (guess < secretNumber) {
            cout << " Too low! Try again.\n";
        }
        else {
            cout << " Too high! Try again.\n";
        }
    }

    if (!won) {
        cout << "\n Out of attempts! The correct number was " << secretNumber << ".\n";
    }

    return bestScore;
}

int main() {
    int bestScore = -1;
    char choice;

    do {
        bestScore = playGame(bestScore);
        cout << "\nPlay again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\n Thanks for playing! Final best score: " << bestScore << "\n";
    return 0;
}
