#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Initialize random seed

    int secretNumber = rand() % 1000 + 1 ; // Generate secret number between 1 and 100
    int guess;
    int chances;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Choose the level of difficulty:" << endl;
    cout << "1. Easy (10 chances)" << endl;
    cout << "2. Medium (7 chances)" << endl;
    cout << "3. Hard (5 chances)" << endl;
    cout << "Enter your choice: ";
    cin >> chances;

    switch (chances) {
        case 1:
            chances = 10;
            break;
        case 2:
            chances = 7;
            break;
        case 3:
            chances = 5;
            break;
        default:
            cout << "Invalid choice. Exiting the game." << endl;
            return 0;
    }

    cout << "Guess the secret number between 1 and 1000." << endl;

    for (int i = 1; i <= chances; ++i) {
        cout << "Attempt " << i << ": Enter your guess: ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the secret number." << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Try a higher number." << endl;
        } else {
            cout << "Try a lower number." << endl;
        }
    }

    cout << "The secret number was: " << secretNumber << endl;
    cout << "Thanks for playing!" << endl;

    return 0;
}
