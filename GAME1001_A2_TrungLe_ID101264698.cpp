//***CODES BY TRUNG LE (KYLE)***
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define INVENTORY_SIZE 9
#define WEAPON_VARIETY_SIZE 6

class MechWeapon {
private:
	int id = 0;
	string name = "Empty";
	double cost = 0.0;
	string sound_fx = "N U L L";
	int ammo = 0;
	int ammo_max = 0;
	int cooldown = 0;
	int cooldown_max = 0;
	bool is_being_used = false;
	bool is_owned = true;
	bool is_hidden = true;
public:
	int GetId() {
		return id;
	}
	string GetName() {
		return name;
	}
	double GetCost() {
		return cost;
	}
	string GetSoundFx() {
		return sound_fx;
	}
	int GetAmmo() {
		return ammo;
	}
	void SetAmmo(int ammo) {
		if (ammo < 0) {
			this->ammo = 0;
		}
		else {
			this->ammo = ammo;
		}
	}
	int GetAmmoMax() {
		return ammo_max;
	}
	int GetCooldown() {
		return cooldown;
	}
	void SetCooldown(int cooldown) {
		if (cooldown < 0) {
			this->cooldown = cooldown_max;
		}
		else {
			this->cooldown = cooldown;
		}
	}
	int GetCooldownMax() {
		return cooldown_max;
	}
	bool GetUsed() {
		return is_being_used;
	}
	void SetUsed(bool is_being_used) {
		this->is_being_used = is_being_used;
	}
	bool GetOwned() {
		return is_owned;
	}
	void SetOwned(bool is_owned) {
		this->is_owned = is_owned;
	}
	bool GetHidden() {
		return is_hidden;
	}

	MechWeapon() {}
	MechWeapon(int id, string name, double cost, string sound_fx, int ammo_max, int cooldown_max, bool is_owned) {
		this->id = id;
		this->name = name;
		this->cost = cost;
		this->sound_fx = sound_fx;
		this->ammo_max = ammo_max;
		this->ammo = ammo_max;
		this->cooldown_max = cooldown_max;
		this->cooldown = cooldown_max;
		this->is_owned = is_owned;
		this->is_hidden = false;
	}
};

class PlayerInventory {
private:
	int inventory[INVENTORY_SIZE] = { 0,0,0,0,0,0,0,0,0 };
	double balance = 3500;
public:
	bool HasItem(int id) {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (inventory[i] == id) {
				return true;
			}
		}
		return false;
	}
	bool IsEmptySlot(int in_index) {
		if (in_index<0 || in_index>INVENTORY_SIZE) {
			return true;
		}
		else if (inventory[in_index] == 0) {
			return true;
		}
		return false;
	}
	bool IsEmptyHanded() {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (inventory[i] != 0) {
				return false;
			}
		}
		return true;
	}
	int GetBalance() {
		return balance;
	}
	void SetBalance(int balance) {
		this->balance = balance;
	}

	int* GetInventoryPtr() {
		int* inventory_ptr = inventory;
		return inventory_ptr;
	}
	void SetInventory(int slot_number, int id) {
		inventory[slot_number] = id;
	}
	int GetNextAvailableSlot() {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (inventory[i] == 0) {
				return i;
			}
		}
		return -1;
	}

	void PrintCurrBalance() {
		std::cout << ">>> Current balance: $" << balance << endl;
	}
	void PrintCurrInventory(MechWeapon* mw_ptr) {
		int player_inventory_next_avail = GetNextAvailableSlot();
		string player_all_inventory_str = "";
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			for (int j = 0; j < WEAPON_VARIETY_SIZE; j++) {
				if (inventory[i] == mw_ptr[j].GetId()) {
					if (i == player_inventory_next_avail) {
						player_all_inventory_str += "{" + mw_ptr[j].GetName() + "}\n";
					}
					else {
						player_all_inventory_str += "[" + mw_ptr[j].GetName() + "]\n";
					}
				}
			}
		}
		std::cout << ">>> Current inventory: " << endl;
		std::cout << player_all_inventory_str;
		std::cout << "{ } = New item will be added to this slot. [ ] = Regular slot." << endl;
	}
	void PrintInventoryMenu(MechWeapon* mw_ptr) {
		string open_bracket = "[";
		string close_bracket = "]";
		std::cout << "--- INVENTORY ---" << endl;
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			for (int j = 0; j < WEAPON_VARIETY_SIZE; j++) {
				if (inventory[i] == mw_ptr[j].GetId()) {
					if (!mw_ptr[j].GetHidden()) {
						open_bracket = "[";
						close_bracket = "]";
						if (mw_ptr[j].GetUsed()) {
							open_bracket = "{";
							close_bracket = "}";
						}
						std::cout << open_bracket
							<< "(" + to_string(i+1) + ") "
							<< mw_ptr[j].GetName()
							<< ", AMMO: "
							<< mw_ptr[j].GetAmmo()
							<< ", COOLDOWN: "
							<< mw_ptr[j].GetCooldown()
							<< close_bracket
							<< endl;
					}
				}
			}
		}
		std::cout << "{ } = Current weapon. [ ] = Available weapon." << endl;
	}
	void UseWeapon(int in_index, MechWeapon* mw_ptr) {
		for (int j = 0; j < WEAPON_VARIETY_SIZE; j++) {
			if (inventory[in_index] == mw_ptr[j].GetId()) {
				int ammo = mw_ptr[j].GetAmmo();
				ammo--;
				if (ammo < 0) {
					cout << ">>>>> Empty clip! Please wait for cooldown!" << endl;
				}
				else {
					cout << endl;
					cout << ">>>>> " << mw_ptr[j].GetSoundFx() << endl;
					cout << endl;
					mw_ptr[j].SetAmmo(ammo);
				}
			}
		}
		// UPDATE COOLDOWN
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			for (int j = 0; j < WEAPON_VARIETY_SIZE; j++) {
				if (inventory[i] == mw_ptr[j].GetId()) {
					if (!mw_ptr[j].GetHidden()) {
						int ammo = mw_ptr[j].GetAmmo();
						int cooldown = mw_ptr[j].GetCooldown();
						if (ammo == 0 || ammo < 0) {
							cooldown--; 
							mw_ptr[j].SetCooldown(cooldown);
						}
						if (cooldown == 0) {
							mw_ptr[j].SetCooldown(mw_ptr[j].GetCooldownMax());
							mw_ptr[j].SetAmmo(mw_ptr[j].GetAmmoMax());
						}
					}
				}
			}
		}
	}

	PlayerInventory() {}
};

void PrintWeaponMenu(MechWeapon* mw_ptr) {
	std::cout << "----- STORE MENU -----" << endl;
	std::cout << left << setw(5) << "NO"
		<< left << setw(20) << "NAME"
		<< left << setw(11) << "PRICE"
		<< left << setw(5) << "AMMO"
		<< left << setw(10) << "COOLDOWN"
		<< endl;
	//[Q] What if I used mw_ptr->Get ?
	for (int i = 0; i < WEAPON_VARIETY_SIZE; i++) {
		if (!mw_ptr[i].GetHidden()) {
			std::cout << left << setw(5) << "(" + to_string(mw_ptr[i].GetId()) + ") "
				<< left << setw(20) << mw_ptr[i].GetName() 
				<< "$"
				<< left << setw(10) << fixed << setprecision(2) << mw_ptr[i].GetCost()
				<< left << setw(5) << mw_ptr[i].GetAmmo()
				<< left << setw(10) << mw_ptr[i].GetCooldown()
				<< endl;
		}
	}
	std::cout << "Cancel purchase: (0) Exit" << endl;
}
bool WeaponExists(int in_id, MechWeapon* mw_ptr) {
	for (int i = 0; i < WEAPON_VARIETY_SIZE; i++) {
		if (in_id == mw_ptr[i].GetId()) {
			return true;
		}
	}
	return false;
}
void RunGame() {
	// INIT
	MechWeapon default_weapon;
	MechWeapon machine_gun = MechWeapon(1, "Machine Gun", 500.0, "DAKA-DAKA-DAKA!", 3, 2, false);
	MechWeapon missile_launcher = MechWeapon(2, "Missile Launcher", 750.0, "WHOOSH!", 2, 2, false);
	MechWeapon laser_pointer = MechWeapon(3, "Laser Pointer", 1000.0, "ZIIIII!", 2, 3, false);
	MechWeapon lightning_rod = MechWeapon(4, "Lightning Rod", 1500.0, "KA-BOOM!", 2, 3, false);
	MechWeapon tactical_nuke = MechWeapon(5, "Tactical Nuke", 3000.0, "FOXDIE!", 1, 5, false);
	MechWeapon weapon_db[WEAPON_VARIETY_SIZE] = { default_weapon, machine_gun, missile_launcher, laser_pointer, lightning_rod, tactical_nuke };
	MechWeapon* weapon_db_ptr = weapon_db;

	PlayerInventory player_inventory = PlayerInventory();
	int* player_inventory_ptr = player_inventory.GetInventoryPtr();
	int player_inventory_next_avail;
	string player_all_inventory_str;

	// THE STORE
	bool is_running_store = true;
	bool is_running_purchasing = true;
	int in_store_choice;
	do {
		std::cout << "Welcome to the Armory." << endl;
		std::cout << "(1) Buy Weapons" << endl;
		std::cout << "(2) Check Balance" << endl;
		std::cout << "(3) Exit Store" << endl;
		std::cout << "Please choose the type of transaction: ";
		cin >> in_store_choice;

		switch (in_store_choice) {
		case 1:
			// PRINT BALANCE + INVENTORY
			std::cout << "--- PLAYER INFO ---" << endl;
			player_inventory.PrintCurrBalance();
			player_inventory.PrintCurrInventory(weapon_db_ptr);

			while (is_running_purchasing) {
				std::cout << endl;
				// PRINT WEAPON DB
				PrintWeaponMenu(weapon_db_ptr);

				int in_weapon_id;
				std::cout << "What weapon do you want to buy [1-5]? ";
				cin >> in_weapon_id;

				if (in_weapon_id == 0) {
					is_running_purchasing = false;
				}
				else if (!WeaponExists(in_weapon_id, weapon_db_ptr)) {
					std::cout << ">>> Unable to purchase! Item not found in Armory!" << endl;
				}
				else if (player_inventory.HasItem(in_weapon_id)) {
					std::cout << ">>> Unable to purchase! You already have this item!" << endl;
				}
				else {
					double balance = player_inventory.GetBalance();
					double item_price = weapon_db[in_weapon_id].GetCost();
					if (balance < item_price) {
						std::cout << ">>> Unable to purchase! You don't have enough money!" << endl;
					}
					else {
						player_inventory.SetBalance(balance - item_price);
						player_inventory.SetInventory(player_inventory.GetNextAvailableSlot(), in_weapon_id);
						weapon_db[in_weapon_id].SetOwned(true);
						std::cout << ">>> Purchase successful! Please see below for your updated inventory: " << endl;
						player_inventory.PrintCurrBalance();
						player_inventory.PrintCurrInventory(weapon_db_ptr);
					}
				}
			}
			break;
		case 2:
			player_inventory.PrintCurrBalance();
			break;
		case 3:
			is_running_store = false;
			std::cout << "Disconnecting from Armory..." << endl;
			break;
		default:
			break;
		}
	} while (is_running_store);

	// THE SIMULATION
	bool is_running_sim = true;
	int in_weapon_choice;
	cout << "You are now entering the battlefield." << endl;
	cout << "You must use your weapon(s). Just press a numbered key and Enter." << endl;
	cout << "Don't worry about aiming or the graphics. They will be added as DLCs once the professor shows me da wae." << endl;
	cout << endl;
	while (is_running_sim) {
		if (player_inventory.IsEmptyHanded()) {
			// EMPTY-HANDED
			cout << ">>> Go home, Jack! You're not even armed. You're not yet ready for the mission." << endl;
			is_running_sim = false;
		}
		else {
			// BOUGHT WEAPON
			player_inventory.PrintInventoryMenu(weapon_db_ptr);
			std::cout << "Exit game: (0) Exit" << endl;

			cout << "Choose weapon: ";
			cin >> in_weapon_choice;
			if (in_weapon_choice == 0) {
				is_running_sim = false;
			}
			else if (player_inventory.IsEmptySlot(in_weapon_choice-1)) {
				cout << ">>> That's an empty slot! Please choose something else." << endl;
			}
			else {
				player_inventory.UseWeapon(in_weapon_choice-1, weapon_db_ptr);
			}
		}
	}
	cout << "Ending simulation..." << endl;
	cout << "Returning to real world..." << endl;
}

int main() {
	RunGame();

	system("pause");
	return 1;
}
//***CODES BY TRUNG LE (KYLE)***