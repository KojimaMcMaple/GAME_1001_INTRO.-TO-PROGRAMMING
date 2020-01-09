#include <ctime>
#include <iostream> // Console input/output.
#include <string>   // Using strings.
using namespace std;

int main() // Entry point for every C++ program.
{
	// Declare variables.
	bool currentPlayer, quitGame = false;
	int randomNum, guess;
	string player1, player2;
	// Create random number from 1 to 100 inclusive.
	srand((unsigned)time(NULL)); // Seeds the random number sequence.
	randomNum = 1 + rand() % 100; // Returns 1-100 inclusive

	// Prompt the players for their names.
	cout << "Player 1, enter your name: ";
	cin >> player1;
	cout << "Okay, your name is " << player1 << endl;
	cout << "Player 2, enter your name: ";
	cin >> player2;
	cout << "Okay, your name is " << player2 << endl;

	// Randomize who goes first. You can also use a Boolean.
	currentPlayer = rand() % 2; // Sets currently player to 0 or 1. 

	// Start the game. Main game loop.
	do
	{   
		bool valid = false; // Need to reset valid every turn.
		do
		{
			// The ?: below is the conditional operator. It's a mini if/else.
			cout << (currentPlayer == 0 ? player1 : player2) << ", enter your guess [1-100]: ";
			cin >> guess; // cin is dangerous. We're not accounting for fail.
			cin.ignore(INT_MAX, '\n'); // Clear/flush out anything left in buffer.
									   // If we ARE in a fail state, this line will get ignored.
			if (cin.fail()) // Uh oh, our bad input created a stream fail.
			{
				cin.clear(); // Clear the error state.
				cin.ignore(INT_MAX, '\n'); // Clear/flush out anything left in buffer.
				cout << "Invalid input, try again." << endl;
			}
			else if (guess < 1 || guess > 100) // Out of bounds.
				cout << "I said 1-100! Try again." << endl;
			else
				valid = true;
		} while (!valid); // Some input validation.

		// Check the guess against three possibilities.
		if (guess < randomNum)
			cout << "Your guess is too low." << endl;
		else if (guess > randomNum)
			cout << "Your guess is too high." << endl;
		else // guess == randomNum
		{
			cout << "Your guess is correct!" << endl;
			quitGame = true;
		}
		if (quitGame == false) // Game is still on, switch player.
			currentPlayer = !currentPlayer;
	} while (quitGame == false); // !quitGame or quitGame != true
	cout << (currentPlayer == 0 ? player1 : player2) << " wins!" << endl;

	system("pause"); // Pause the console before closing. Not portable.
	return 0;
}