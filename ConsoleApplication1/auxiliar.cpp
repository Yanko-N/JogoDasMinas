#include "auxiliar.h"
#include "Tabuleiro.h"


int auxiliar:: GetBoardSize() {
	bool quit = false;
	int boardSize = 0;

	do {
		system("cls");


		cout << "\t What's the size of the board do want to play?";
		cin >> boardSize;

		if (boardSize > 0) {

			string quitOp;
			cout << "\t are you sure this is the correct size of the board?";
			cin >> quitOp;

			if (quitOp.find("sim") != string::npos || quitOp.find("yes") != string::npos) {
				quit = true;
			}
			else if (quitOp.find("nao") != string::npos || quitOp.find("no") != string::npos) {
				//Nothing happpen here
			}
			else {
				cout << "\t Please retry again, anwser Yes, Sim to accept ";
				system("pause");
			}
		}
		
	} while (!quit);

	return boardSize;
}

void auxiliar::MainMenu() {
	cout << "\tJogo das Minas \n \t Desenvolvido por Vitor Novo\n";
	system("pause");
	bool quit = false;
	do {
		system("cls");
		string op;
		cout << "\n\t1-Play\n\t2-Quit\n r.:";
		cin >> op;

		if (op.find("1") != string::npos) {

			Tabuleiro tabuleiro = Tabuleiro(GetBoardSize());
			tabuleiro.PosicionarBombas();
			tabuleiro.ShowTabuleiro();
			while (true)
			{
				
				bool lose = tabuleiro.Guess();
				bool won = tabuleiro.WinningChecker();
				
				
				
				if (!lose && !won) {

					
					tabuleiro.printBoard();
					cout << "GAME OVER!!!\n";
					std::system("pause");
					break;
				}
				if (won && lose) {
					tabuleiro.printBoard();
					cout << "Congrats you won!!!\n";
					std::system("pause");
					break;
				}

				tabuleiro.ShowTabuleiro();
				
			}
			
		
			

		}
		else if (op.find("2") != string::npos)
		{
			//quit option
			quit = true;
		}
		else
		{
			//exeption
			cout << " \n\n\tERROR that's not a valid option\n";
		}

	} while (!quit);

}

