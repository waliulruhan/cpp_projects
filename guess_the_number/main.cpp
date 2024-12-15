#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    int the_number = rand() % 100 + 1;  
    cout << "A random number between 1 and 100 has been chosen!" << endl;

    int guessed_number{};
    int attempts = 0;
    while (true) {
        cout << "Guess the number between 1 and 100: ";
        cin >> guessed_number;

        if (cin.fail()) {
            // Clear the error state and ignore invalid input
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid number!" << endl;
            continue;
        }

        attempts++;  

        if (guessed_number > the_number) {
            cout << "Guess a lower number!" << endl;
        } else if (guessed_number < the_number) {
            cout << "Guess a higher number!" << endl;
        } else {
            cout << "Yeah! You've guessed the number in " << attempts 
                 << " tries. The number was " << the_number << "." << endl;
            break;
        }
    }

    return 0;
}
