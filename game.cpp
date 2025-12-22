#include <iostream>
#include <cstdint>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;



int main() {
    random_device rd;  // Obtain a random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> randomNumber(1, 100); // Define the range
    // int randomnumber = randomNumber(eng); // Generate the random number


    int userguess;
    int computerguess = randomNumber(eng);
    int attempts = 0;

    cout << "Enter a number between 1 and 100: ";
    cin >> userguess;
    attempts++;

    while (userguess != computerguess) {
        if (userguess > 100 || userguess < 0)
        {
            cout << "Please enter a number between 1 to 100 : ";
            attempts = 0;
        }
        
        else if (userguess < computerguess) {
            cout << "Guess the higher number : " ;
        } 
        
        else {
            cout << "Guess the lower number : " ;
        }
        cin >> userguess;
        attempts++;
    }
    
    cout << "Congratulations! You guessed the number " << computerguess << " in " << attempts << " attempts." << endl;
    return 0;
}