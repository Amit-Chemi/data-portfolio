// OOP - Alternative Evaluation
// Name: Amit Chemi , ID: 207637802

#include <iostream>
#include <string>
#include "Store.h"
#include "Vegetable.h"
#include "Fruit.h"
#include "Package.h"
#include "Dairy.h"
#include "Cheese.h"
#include "OtherDairy.h"

using namespace std;

// helper function to convert a string to an integer
int convertStringToInt(const string& str) {
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		// check if the character is a digit
		if (str[i] >= '0' && str[i] <= '9') {
			// multiply by 10 and add the numeric value of the character (by subtracting the ASCII value of '0')
			num = num * 10 + (str[i] - '0');
		}
	}
	return num;
}

// function to read products from the user
void readProducts(Store& store) {
	int serial, shelf, type, area;
	char row;
	double quantity;

	while (true) {
		cout << "\n--- Adding a New Product ---\n";
		cout << "Enter a product serial number (or type -1 to stop and return to menu): ";
		cin >> serial;

		if (serial == -1) {
			break;
		}

		// check if serial already exists
		if (store.isSerialExists(serial)) {
			cout << "Error: Product with this serial already exists! Please try a different serial number.\n";
			continue; // skip the rest of the loop and start over
		}

		cout << "Enter row (single upper case character, e.g., A): ";
		cin >> row;

		// check row (A-Z)
		if (row < 'A' || row > 'Z') {
			cout << "Error: row must be between A-Z! Please try again.\n";
			continue;
		}

		cout << "Enter shelf (number between 1-5): ";
		cin >> shelf;

		// check shelf (1-5)
		if (shelf < 1 || shelf>5) {
			cout << "Error: shelf must be between 1-5! Please try again.\n";
			continue;
		}

		cout << "Enter quantity (number): ";
		cin >> quantity;

		cout << "Enter type (1 = Agricultural, 2 = Package, 3 = Dairy): ";
		cin >> type;

		cout << "Enter area code (1 = hidden, 2 = medium exposure, 3 = high exposure): ";
		cin >> area;

		// check area (1-3)
		if (area < 1 || area>3) {
			cout << "Error: area must be between 1-3! Please try again.\n";
			continue;
		}

		// type 1: Agricultural product
		if (type == 1) {
			string name;
			int kind, seasons, suppliers;

			cout << "Enter agricultural product name (1 word): ";
			cin >> name;

			cout << "Enter kind (1 = Vegetable, 2 = Fruit): ";
			cin >> kind;

			cout << "Enter number of seasons: ";
			cin >> seasons;

			cout << "Enter number of suppliers: ";
			cin >> suppliers;

			if (kind == 1) { // vegetable
				int vitamins;
				cout << "Enter number of vitamins: ";
				cin >> vitamins;

				store.addProduct(new Vegetable(serial, row, shelf, quantity, type, area, name, seasons, suppliers, vitamins));
				cout << "\n Product added successfully!\n";
			}
			else if (kind == 2) { // fruit
				int sugar;
				cout << "Enter sugar amount: ";
				cin >> sugar;

				store.addProduct(new Fruit(serial, row, shelf, quantity, type, area, name, seasons, suppliers, sugar));
				cout << "\n Product added successfully!\n";
			}
		}
		// type 2: Package
		else if (type == 2) {
			string word;
			string names[100];
			int numProducts = 0;

			cout << "Enter product names in the package (separated by space).\n";
			cout << "When you are done, type the TOTAL NUMBER of the products to stop: ";

			// read words until a number is found
			while (cin >> word) {
				if (word.length() > 0 && word[0] >= '0' && word[0] <= '9') {
					numProducts = convertStringToInt(word);
					break;
				}
				names[numProducts] = word;
				numProducts++;
			}
			int colors;
			cout << "Enter number of colors in package design: ";
			cin >> colors;

			store.addProduct(new Package(serial, row, shelf, quantity, type, area, numProducts, names, colors));
			cout << "\n Product added successfully!\n";
		}
		// type 3: Dairy
		else if (type == 3) {
			string word1, word2;
			cout << "Enter dairy product name (exactly 2 word, separated by space): ";
			cin >> word1 >> word2;
			string name = word1 + " " + word2;

			int kind, colors;
			double fat;

			cout << "Enter kind (1 = Beverage, 2 = Yogurt, 3 = Cheese, 4 = Other): ";
			cin >> kind;

			cout << "Enter number of colors: ";
			cin >> colors;

			cout << "Enter fat percentage: ";
			cin >> fat;

			if (kind == 1 || kind == 2) { // beverage or yogurt
				store.addProduct(new Dairy(serial, row, shelf, quantity, type, area, kind, name, colors, fat));
				cout << "\n Product added successfully!\n";
			}
			else if (kind == 3) { // cheese
				int extras;
				cout << "Enter number of extras: ";
				cin >> extras;

				store.addProduct(new Cheese(serial, row, shelf, quantity, type, area, name, colors, fat, extras));
				cout << "\n Product added successfully!\n";
			}
			else if (kind == 4) { // other dairy
				string word;
				string names[100];
				int count = 0;

				cout << "Enter non dairy ingridient names (separated by space). \n";
				cout << "When you are done, type the TOTAL NUMBER of ingredients to stop: ";

				// read ingredients until a number is found
				while (cin >> word) {
					if (word.length() > 0 && word[0] >= '0' && word[0] <= '9') {
						count = convertStringToInt(word);
						break;
					}
					names[count] = word;
					count++;
				}
				store.addProduct(new OtherDairy(serial, row, shelf, quantity, type, area, name, colors, fat, count, names));
				cout << "\n Product added successfully!\n";
			}
		}
	}
}

void printMenu() {
	cout << "\n--- SuperShop Menu ---\n";
	cout << "1. Print store details\n";
	cout << "2. Change advertising factor\n";
	cout << "3. Calculate total price\n";
	cout << "4. Add products\n";
	cout << "5. Exit\n";
	cout << "Choose an option: ";
}

int main() {
	// initialize store
	Store myStore("SuperShop", 3);

	int choice = 0;
	while (choice != 5) {
		printMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\n--- Store Details ---\n";
			myStore.print(cout);
			break;

		case 2: {
			int newFactor;
			cout << "Enter new advertising factor: ";
			cin >> newFactor;
			myStore.setAdFactor(newFactor);
			cout << "Advertising factor updated.\n";
			break;
		}
		case 3:
			cout << "\nTotal expected price: " << myStore.calcTotalPrice() << "\n";
			break;

		case 4:
			readProducts(myStore);
			break;

		case 5:
			cout << "Exiting system. Goodbye!\n";
			break;

		default:
			cout << "Invalid choice. Please try again.\n";
			break;

		}
	}
	return 0;
}