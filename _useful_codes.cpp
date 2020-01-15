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
	
	
	if (!bullet_vec.empty()) {
		bullet_vec.erase(remove(bullet_vec.begin(), bullet_vec.end(), nullptr), bullet_vec.end());
		bullet_vec.shrink_to_fit();
	}