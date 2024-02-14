#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr)); // Seed the random number generator

    // Generate a secret number between 1 and 100
    const int MIN_SECRET_NUMBER = 1;
    const int MAX_SECRET_NUMBER = 100;
    int secretNumber = rand() % (MAX_SECRET_NUMBER - MIN_SECRET_NUMBER + 1) + MIN_SECRET_NUMBER;

    // Define difficulty levels
    struct Difficulty {
        int value;
        int chances;
    };

    Difficulty difficulties[] = {
        {1, 10}, // Easy
        {2, 7},  // Medium
        {3, 5}   // Hard
    };

    // Display welcome message and prompt user to choose difficulty
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Choose the level of difficulty:" << endl;
    for (const auto &difficulty : difficulties) {
        cout << difficulty.value << ". ";
        switch (difficulty.value) {
            case 1:
                cout << "Easy (" << difficulty.chances << " chances)" << endl;
                break;
            case 2:
                cout << "Medium (" << difficulty.chances << " chances)" << endl;
                break;
            case 3:
                cout << "Hard (" << difficulty.chances << " chances)" << endl;
                break;
        }
    }

    int chosenDifficulty;
    cout << "Enter your choice: ";
    cin >> chosenDifficulty;

    // Validate user input and retrieve the number of chances
    int chances;
    for (const auto &difficulty : difficulties) {
        if (chosenDifficulty == difficulty.value) {
            chances = difficulty.chances;
            break;
        }
    }

    // If the chosen difficulty is not valid, exit the game
    if (chances == 0) {
        cout << "Invalid choice. Exiting the game." << endl;
        return 0;
    }

    cout << "Guess the secret number between " << MIN_SECRET_NUMBER << " and " << MAX_SECRET_NUMBER << "." << endl;

    // Game loop
    for (int attempt = 1; attempt <= chances; ++attempt) {
        int guess;
        cout << "Attempt " << attempt << ": Enter your guess: ";
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

    // Display the secret number and thank the player for playing
    cout << "The secret number was: " << secretNumber << endl;
    cout << "Thanks for playing!" << endl;

    return 0;
}
