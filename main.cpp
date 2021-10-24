#include"MyString.h"


void title(string);
void mainMenu();
void inputSelect(int&, int, int);
void MyStringMenu();

int main() {
	int choice;

	while (1) {
		system("cls");
		title(" WELCOME TO OUR PROGRAM");
		mainMenu();
		inputSelect(choice, 1, 2);

		if (choice == 1) {
			system("cls");
			MyString s1;
			title(" ENTER STRING BEFORE DOING SOMETHING");
			cout << "Enter string: ";
			cin >> s1;

			do {
				system("cls");

				title(" A PROGRAM BUILDING STRING");
				MyStringMenu();
				inputSelect(choice, 1, 8);
				system("cls");

				switch (choice) {
				case 1: {
					
					title(" LENGTH OF STRING");
					cout << "Your string: " << s1 << endl;
					cout << "\nA number of character: ";
					cout << s1.length() << endl;

					break;
				}

				case 2: {
					title(" PRINT SUBTRING");
					cout << "Your string: " << s1 << endl;
					int start, length;
					cout << "\nCreate substring from start with length:\n";
					cout << "Start = ";
					cin >> start;
					cout << "Length = ";
					cin >> length;

					char* tmp = s1.subString(start, length);

					if (tmp == NULL)
						cout << "Error...\n";
					else {
						cout << "Sub string: " << tmp;

						delete[] tmp;
						tmp = NULL;
					}
					cout << endl;

					break;
				}

				case 3: {
					title(" STRING CONCATENATION");
					cout << "Your string: " << s1 << endl;
					MyString s2;
					cout << "\nEnter string: ";
					cin >> s2;
					cout << "\nAfter string concatenation: ";
					cout << s1 + s2 << endl;

					break;
				}

				case 4: {
					title(" INSERT STRING");
					cout << "Your string: " << s1 << endl;
					int pos;
					char* s2 = new char[1000];
					cout << "\nEnter string: ";
					cin >> s2;
					do {
						cout << "\nInput the position: ";
						cin >> pos;

						if (pos < 0 || pos > s1.length())
							cout << "\nYou entered wrong. Please re-enter" << endl;
					} while (pos < 0 || pos > s1.length());

					char* tmp = s1.insert(pos, s2);
					cout << "\nAfter inserting the string: " << tmp << endl;;

					if (tmp) {
						delete[] tmp;
						tmp = NULL;
					}
					break;
				}
				case 5: {
					title(" DELETE STRING");
					cout << "Your string: " << s1 << endl;
					int start, count;
					cout << "\nEnter starting index: ";
					cin >> start;
					cout << "\nA number of charaters need deleting: ";
					cin >> count;

					if (s1.erase(start, count) == NULL)
						cout << "Error...";
					else
						cout << "\nAfter deleting the string: " << s1.erase(start, count);
					cout << endl;

					break;
				}

				case 6: {
					title(" REPLACE STRING");
					cout << "Your string: " << s1 << endl;
					int start, lenth;
					char* tmp;
					char* s2 = new char[1000];

					cout << "\nEnter starting index: ";
					cin >> start;

					cout << "\nA number of charaters need replacing: ";
					cin >> lenth;

					cout << "\nEnter string: ";
					cin >> s2;

					tmp = s1.replace(start, lenth, s2);
					if (!tmp)
						cout << "Error...";
					else {
						cout << "\nAfter replacing the string: ";
						cout << tmp;

						delete[] tmp;
						tmp = NULL;
					}
					cout << endl;

					break;
				}

				case 7: {
					title(" FIND SUBSTRING");
					cout << "Your string: " << s1 << endl;
					int pos;
					char* s2 = new char[1000];

					cout << "\nInput substring to find: ";
					cin >> s2;

					do {
						cout << "\nThe position where to start finding: ";
						cin >> pos;
						if (pos < 0 || pos > s1.length())
							cout << "\nYou entered wrong. Please re-enter\n" << endl;
					} while (pos < 0 || pos > s1.length());

					if (s1.find(pos, s2) == true)
						cout << "\nExist in the string";
					else
						cout << "\nDoes not exist in the string";
					cout << endl;

					break;
				}

				case 8:
					continue;

				default:
					cout << "Your choice not available." << endl << endl;
				}
				cout << endl;
				system("pause");

			} while (choice != 8);
		}
		else {
			cout << "\t\t\t ======================================================================"
				<< "\n\t\t\t\t\t    *** THANK YOU! SEE YOU LATER! ***\n";
			return 0;
		}
	}
	return 0;
}
void title(string message) {
	system("cls");
	cout << "\t\t\t*******************************************************\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t***";
	for (int i = 0; i < (50 - message.size()) / 2; i++)
		cout << " ";
	cout << message;
	for (int i = 0; i < (50 - message.size()) / 2; i++)
		cout << " ";
	cout << "***\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t*******************************************************\n";
}

void inputSelect(int& ans, int beg, int end) {
	cout << "Your choice: ";
	cin >> ans;
	if (ans<beg || ans>end) {
		cout << "Enter error! Please enter again!\n";
		return inputSelect(ans, beg, end);
	}
}

void mainMenu()
{
	cout << "\t\t\t  ***************************************************\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [1] A program building string                 *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [2] Exit                                      *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  ***************************************************\n\n";
}

void MyStringMenu()
{

	cout << "\t\t\t  ***************************************************\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [1] Return a number of character.             *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [2] Return a sub-string.                      *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [3] Operator+ a new string into current string*\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [4] Insert a new string into current string.  *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [5] Delete a sub-string.                      *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [6] Replace a string with a new string.       *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [7] Find a sub-string into current string.    *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  *   [8] Back.                                     *\n"
		<< "\t\t\t  *                                                 *\n"
		<< "\t\t\t  ***************************************************\n\n";
}
