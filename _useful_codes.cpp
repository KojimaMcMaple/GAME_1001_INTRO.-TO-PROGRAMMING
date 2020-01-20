	bool is_valid_input = false;

	do {
		cout << "Q: How many students were surveyed ?" << endl;
		cout << "A: ";
		cin >> num_surv_students;

		cin.ignore(INT_MAX, '\n');
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "ERROR: Invalid input. Please try again." << endl;
		}
		else if (num_surv_students < 0) {
			cout << "ERROR: Number of students cannot be less than 0. Please enter a number > 0. " << endl;
		}
		else {
			is_valid_input = true;
		}
	} while (!is_valid_input);
	
	
	if (!bullet_vec.empty()) {
		bullet_vec.erase(remove(bullet_vec.begin(), bullet_vec.end(), nullptr), bullet_vec.end());
		bullet_vec.shrink_to_fit();
	}