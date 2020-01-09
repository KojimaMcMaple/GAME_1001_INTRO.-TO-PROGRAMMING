//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // file handling
#include <ctime> //for randomization
#include <algorithm> //for tolower
using namespace std;

int g_loss_score;
int g_win_score;
int g_tie_score;
string g_player_username;
string g_player_username_file_str;

void PrintErrInvalidStrInput(string in_str_arr[], short in_str_arr_size) {
	std::cout << "\n-> INVALID INPUT! Please only use the following: ";
	for (int i = 0; i < in_str_arr_size; i++)
	{
		// CHOICE BETWEEN COMMA OR DOT
		if (i != in_str_arr_size - 1) {
			std::cout << in_str_arr[i] << ", ";
		}
		else {
			std::cout << in_str_arr[i] << ".\n" << endl;
		}
	}
	std::cout << endl;
}

void PrintProgressReport(int win_score, int loss_score, int tie_score) {
	cout << left << setw(10) << "WIN";
	cout << left << setw(10) << "LOSS";
	cout << left << setw(10) << "TIE";
	cout << endl;

	cout << left << setw(10) << win_score;
	cout << left << setw(10) << loss_score;
	cout << left << setw(10) << tie_score;
	cout << endl;
}

string ConvertNumToStr(int in_num) {
	string result;
	switch (in_num) {
	case 0 : 
		result = "Rock";
		break;
	case 1 : 
		result = "Paper";
		break;
	case 2 : 
		result = "Scissor";
		break;
	default: 
		result = "";
		break;
	}
	return result;
}

bool HasSpecialChar(string in_str) {
	if (in_str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != string::npos)
	{
		return true;
	}
	return false;
}

bool IsFile(string file_name) {
	/*CHECK IF FILE EXISTS*/
	ifstream fin(file_name);
	
	if (fin.fail()) {
		return false;
	}
	return true;
}

bool RPSLogIn() {
	// INIT
	g_win_score = 0;
	g_loss_score = 0;
	g_tie_score = 0;
	g_player_username = "UNDEFINED";

	fstream fio;

	string in_player_username;
	string in_player_password;
	string in_player_password_confirm;
	bool is_username_valid_input = false;
	bool is_new_player = true;
	bool is_matching_password = false;

	string player_username_file_str;
	string player_password_file_str;

	// PLAYER INPUT
	do {
		std::cout << endl;
		std::cout << "LOGGING IN TO KYLE'S ROCK-PAPER-SCISSOR GAME..." << endl;
		std::cout << "Please enter your username: ";
		std::getline(cin, in_player_username);

		// INPUT VALIDATION
		is_username_valid_input = false;
		if (in_player_username.size() > 7) {
			if (HasSpecialChar(in_player_username)) {
				std::cout << "\n-> INVALID INPUT! Special characters not allowed because we need to save the file!\n";
			}
			else {
				is_username_valid_input = true;
			}
		}
		else {
			std::cout << "\n-> INVALID INPUT! Please use a username of at least 8 characters!\n";
		}
	} while (!is_username_valid_input);
	
	// IF VALID INPUT: SET GLOBAL VARS
	g_player_username = in_player_username;
	player_username_file_str = in_player_username + ".txt";
	g_player_username_file_str = player_username_file_str;
	player_password_file_str = in_player_username + "_password.txt";

	// PASSWORD CHECK
	if (IsFile(player_username_file_str)) {
		is_new_player = false;
	}

	if (is_new_player) {
		cout << "Create your password: ";
		getline(cin, in_player_password);
		is_matching_password = false;
		do {
			cout << "Confirm your password: ";
			getline(cin, in_player_password_confirm);
			if (in_player_password.compare(in_player_password_confirm) == 0) {
				is_matching_password = true;
			}
			else {
				cout << "-> ERROR: Password does not match!" << endl;
			}
		} while (!is_matching_password);

		ofstream player_password_file(player_password_file_str);
		string player_password_file_line;
		if (player_password_file.is_open()) {
			player_password_file << in_player_password;
			player_password_file.close();
		}
		else {
			cout << "\n-> ERROR: Unable to open for writing: " << player_password_file_str << "." << endl;
			return 0;
		}
	}
	else {
		is_matching_password = false;
		ifstream player_password_file(player_password_file_str);
		string player_password_file_line;
		int line_count = 0;
		while (getline(player_password_file, player_password_file_line)) {
			switch (line_count) {
			case 0:
				in_player_password_confirm = player_password_file_line;
			}
		}
		player_password_file.close();

		do {
			cout << "Enter your password: ";
			getline(cin, in_player_password);
			if (in_player_password.compare(in_player_password_confirm) == 0) {
				is_matching_password = true;
			}
			else {
				cout << "-> ERROR: Password does not match database!" << endl;
			}
		} while (!is_matching_password);
	}

	// DO NOT CONTINUE IF PASSWORD MISMATCH
	if (!is_matching_password) {
		return 0;
	}

	if (is_new_player) {
		// CREATE NEW FILE
		ofstream player_username_file(player_username_file_str);
		if (player_username_file.is_open()) {
			player_username_file << g_loss_score << endl;
			player_username_file << g_win_score << endl;
			player_username_file << g_tie_score;
			player_username_file.close();

			// WELCOME MESSAGE
			cout << "Welcome to the game, " << g_player_username << "! Since you're new these will be your starting scores: " << endl;
			PrintProgressReport(g_win_score, g_loss_score, g_tie_score);
			cout << "Continue playing will increase your scores so please come back!" << endl;
		}
		else {
			cout << "\n-> ERROR: Unable to open for writing: " << player_username_file_str << "." << endl;
			return 0;
		}
	}
	else {
		ifstream player_username_file(player_username_file_str);
		string player_username_file_line;

		if (player_username_file.is_open()) {
			int line_count = 0;
			while (getline(player_username_file, player_username_file_line)) {
				switch (line_count) {
				case 0:
					g_loss_score = stoi(player_username_file_line);
				case 1:
					g_win_score = stoi(player_username_file_line);
				case 2:
					g_tie_score = stoi(player_username_file_line);
				}
				line_count++;
			}
			player_username_file.close();

			// WELCOME MESSAGE
			cout << "Welcome back, " << g_player_username << "! You previously achieved the following scores: " << endl; 
			PrintProgressReport(g_win_score, g_loss_score, g_tie_score);
			cout << "Continue playing will increase your scores so please stick around!" << endl;
		}
		else {
			cout << "\n-> ERROR: Unable to open for reading: " << player_username_file_str << "." << endl;
			return 0;
		}
	}
	return 1;
}

short RPSDetermineWinLoss(short in_player, short in_com) {
	// LOSS = 0
	// WIN = 1
	// TIE = 2
	if (in_player == in_com) {
		return 2;
	}
	else {
		if (in_player == 0) {
			if (in_com == 1) { return 0; }
			else { return 1; }
		}
		else if (in_player == 1) {
			if (in_com == 0) { return 1; }
			else { return 0; }
		}
		else if (in_player == 2) {
			if (in_com == 0) { return 0; }
			else { return 1; }
		}
	}
	return 3;
}

bool RPSGameplay() {
	// INIT
	int win_score = 0;
	int loss_score = 0;
	int tie_score = 0;

	string player_valid_inputs[9] = { "rock", "r", "0",
										"paper", "p", "1",
										"scissor", "s", "2" };
	short player_valid_inputs_size = sizeof(player_valid_inputs) / sizeof(player_valid_inputs[0]);
	bool is_player_valid_input = false;
	string in_player_choice;
	string str_player_choice; //don't want to change the original input, create var to manipulate data
	short player_choice;
	short computer_choice;

	string win_message = "************************\n*-> Result: VICTORY! <-*\n************************";
	string loss_message = "*********************\n*-> Result: LOSS! <-*\n*********************";
	string tie_message = "********************\n*-> Result: TIE! <-*\n********************";
	
	string endgame_valid_inputs[4] = { "yes", "y", "no", "n" };
	short endgame_valid_inputs_size = sizeof(endgame_valid_inputs) / sizeof(endgame_valid_inputs[0]);
	bool is_endgame_valid_input = false;
	bool is_endgame = true;
	string in_endgame_choice;
	string str_endgame_choice; //don't want to change the original input, create var to manipulate data

	int num_o_rounds = 1;

	do {
		// PLAYER INPUT
		do {
			std::cout << endl;
			std::cout << "ROUND #" << num_o_rounds << ": Please choose Rock, Paper or Scissor: ";
			std::getline(cin, in_player_choice);
			str_player_choice = in_player_choice;
			
			std::transform(str_player_choice.begin(), str_player_choice.end(), str_player_choice.begin(), ::tolower);
			// INPUT VALIDATION & GET player_choice
			is_player_valid_input = false;
			for (int i = 0; i < player_valid_inputs_size; i++)
			{
				if (str_player_choice.compare(player_valid_inputs[i]) == 0) {
					is_player_valid_input = true;

					//player_valid_inputs always have equal elements for 3 arrays of "weapons", so we divide by 3
					if (i < player_valid_inputs_size / 3) {
						player_choice = 0;
					}
					else if (i < player_valid_inputs_size / 3 * 2) {
						player_choice = 1;
					}
					else {
						player_choice = 2;
					}
					break;
				}
			}

			if (!is_player_valid_input) {
				PrintErrInvalidStrInput(player_valid_inputs, player_valid_inputs_size);
			}
		} while (!is_player_valid_input);

		// GENERATE COMPUTER CHOICE
		std::srand(time(NULL));
		computer_choice = rand() % 3;

		// COMPARE BETWEEN PLAYER & COM, OUTPUT RESULT
		switch (RPSDetermineWinLoss(player_choice, computer_choice))
		{
		case 0:
			loss_score += 1;
			std::cout << loss_message << endl;
			break;
		case 1:
			win_score += 1;
			std::cout << win_message << endl;
			break;
		case 2:
			tie_score += 1;
			std::cout << tie_message << endl;
			break;
		}
		std::cout << "- Player " << g_player_username << " chose " << ConvertNumToStr(player_choice) << "." << endl;
		std::cout << "- Computer chose " << ConvertNumToStr(computer_choice) << "." << endl;

		// CONTINUE TO ANOTHER ROUND
		std::cout << endl;
		std::cout << "ROUND #" << num_o_rounds << " FINISHED! Current scores in this session: " << endl;
		PrintProgressReport(win_score, loss_score, tie_score);
		do {
			std::cout << "Play another round (Y/N)? ";
			std::getline(cin, in_endgame_choice);
			str_endgame_choice = in_endgame_choice;
			
			// INPUT VALIDATION & GET endgame_choice
			std::transform(str_endgame_choice.begin(), str_endgame_choice.end(), str_endgame_choice.begin(), ::tolower);
			is_endgame_valid_input = false;
			for (int i = 0; i < endgame_valid_inputs_size; i++)
			{
				if (str_endgame_choice.compare(endgame_valid_inputs[i]) == 0) {
					is_endgame_valid_input = true;

					//endgame_valid_inputs always have equal elements for 2 types of choices, so we divide by 2
					if (i < endgame_valid_inputs_size / 2) {
						is_endgame = false;
					}
					else {
						is_endgame = true;
					}
					break;
				}
			}
			if (!is_endgame_valid_input) {
				PrintErrInvalidStrInput(endgame_valid_inputs, endgame_valid_inputs_size);
			}
		} while (!is_endgame_valid_input);

		// UPDATE WHICH ROUND BEING PLAYED
		num_o_rounds++;

		if (is_endgame) {
			g_win_score += win_score;
			g_loss_score += loss_score;
			g_tie_score += tie_score;
			cout << "\nGAME OVER! Player " << g_player_username << " has achieved these total scores combined with existing scores: " << endl;
			PrintProgressReport(g_win_score, g_loss_score, g_tie_score);
			cout << "Thank you for playing KYLE'S ROCK-PAPER-SCISSOR GAME!" << endl;

			// SAVE PROGRESS
			// [Q]: Should I save during gameplay instead of waiting til the end ?
			ofstream player_username_file(g_player_username_file_str);
			if (player_username_file.is_open()) {
				player_username_file << g_loss_score << endl;
				player_username_file << g_win_score << endl;
				player_username_file << g_tie_score;
				player_username_file.close();
			}
			else {
				cout << "\n-> ERROR: Unable to open for writing: " << g_player_username_file_str << "." << endl;
				return 0;
			}
		}
	} while (!is_endgame);
	return 1;
}

int main() {
	if (RPSLogIn()) {
		RPSGameplay();
	}

	std::system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***