#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
using namespace std;
namespace Read
{
	int NumberOfRounds(string messag)
	{
		int number;

		do {
			cout << messag;
			cin >> number;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Invelbel Number Tray agen:\n";
				cin >> number;
			}
		} while (number <= 0 || number >= 11);

		return number;
	}
	int YourChos(string messag)
	{
		int chos;

		do {
			cout << messag;
			cin >> chos;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Invelbel Number Tray agen:\n";
				cin >> chos;
			}
		} while (chos <= 0 || chos >= 4);

		return chos;
	}
}
