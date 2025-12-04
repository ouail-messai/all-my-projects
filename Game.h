#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Read.h";
#include "Prints.h";

using namespace std;
namespace Game
{

	string ComputerWiner;
	enum enchos { Stone = 1, Peper = 2, Scissors = 3 };
	struct stWon
	{
		int PlayerWin = 0, ComputerWin = 0, DrowWin = 0;
	};
	struct stGame
	{
		int  Round;
		stWon Won;
		int ChoisePlayer, ComputerChoise;
	};
	int Random(int from, int to)
	{
		int random = rand() % (to - from + 1) + from;

		return random;
	}
	string l(stGame& Game)
	{
		Game.Won.ComputerWin++;
		cout << "\a\a";
		system("color 4f");
		return "[Computer Winner]";
	}
	string PalyerWiner(stGame& Game)
	{
		Game.Won.PlayerWin++;
		system("color 2f");
		return "[player Winner]";
	}
	string ChoisePrints(int Choise)
	{
		switch (Choise)
		{
		case enchos::Stone:
			return "Stone";

		case enchos::Peper:
			return "Peper";

		case enchos::Scissors:
			return "Scissors";
		}
		return "";
	}
	string WinnerPrints(stGame& Game)
	{
		if (Game.ChoisePlayer == Game.ComputerChoise)
		{
			Game.Won.DrowWin++;
			system("color 6f");
			return "[No Winner]";
		}
		else
		{
			switch (Game.ChoisePlayer)
			{
			case enchos::Stone:
				if (Game.ComputerChoise == enchos::Peper)
				{
					return l(Game);
				}
				else
				{
					return PalyerWiner(Game);
				}
			case enchos::Peper:
				if (Game.ComputerChoise == enchos::Scissors)
				{
					return l(Game);
				}
				else
				{
					return PalyerWiner(Game);
				}
			case enchos::Scissors:
				if (Game.ComputerChoise == enchos::Peper)
				{
					return PalyerWiner(Game);
				}
				else
				{
					return l(Game);
				}
			}
			return"";
		}
	}
	void HowWinner(stGame& Game, int Round)
	{
		printf("--------------------------- Rounds [ %02d ] -------------------------------------\n", Round + 1);
		cout << setw(15) << "Player 1 Choise : " << ChoisePrints(Game.ChoisePlayer) << endl;
		cout << setw(15) << "Computer Choise : " << ChoisePrints(Game.ComputerChoise) << endl;
		cout << setw(15) << "Rounds Winner : " << WinnerPrints(Game) << endl;
		cout << "--------------------------------------------------------------------------" << endl;
	}
	string FinalWin(stWon Won)
	{
		string Resolt;

		Resolt = (Won.ComputerWin > Won.PlayerWin) ? "Computer" : "Player";
		return Resolt;
	}
	void Review(int Rounds, stGame& Game)
	{
		for (int i = 0; i < Rounds; i++)
		{
			printf("\n\nRounds [ %02d ] begins :\n\n", i + 1);

			Game.ChoisePlayer = Read::YourChos("Your Chos : [1]:Stone,[2]:Peper,[3]:Scissors ? ");
			Game.ComputerChoise = Random(1, 3);

			HowWinner(Game, i);
		}
	}
	void GameResults(stGame Game)
	{
		cout << " \n----------------------[GAME RESULTS]--------------------------------\n";
		cout << setw(20) << " \tGame Rounds        : " << setw(3) << Game.Round << endl;
		cout << setw(20) << " \tPlayer 1 Won Time  : " << setw(3) << Game.Won.PlayerWin << endl;
		cout << setw(20) << " \tCoumpter Wom Time  : " << setw(3) << Game.Won.ComputerWin << endl;
		cout << setw(20) << " \tDrow Time          : " << setw(3) << Game.Won.DrowWin << endl;
		cout << setw(20) << " \tFinal Winner       : " << setw(3) << FinalWin(Game.Won) << endl;
		cout << " \n--------------------------------------------------------------------\n" << endl;
	}
	void StratGame()
	{
		char PlayAgain;

		do {
			stGame Game;

			Game.Round = Read::NumberOfRounds("How Meny Rounds 1 to 10 ?\n");

			Review(Game.Round, Game);

			Print::GameOverPrints();
			GameResults(Game);

			cout << " Do you want to play again n/y ?";
			cin >> PlayAgain;
			cout << endl;

			Print::Restart();

		} while (PlayAgain == 'Y' || PlayAgain == 'y');
	}

}
