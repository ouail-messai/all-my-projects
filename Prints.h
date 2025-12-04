#pragma once
#include <iostream>
using namespace std;
namespace Print
{
	void Restart()
	{
		system("cls");

		system("color 07");
	}
	void GameOverPrints()
	{
		cout << "\n\n-------------------------------------------------------------------------\n\n";
		cout << "\t\t+++  G A M E    O V E R  +++\t\t\n";
		cout << "\n-------------------------------------------------------------------------\n" << endl;
	}
}