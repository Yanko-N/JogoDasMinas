#include "auxiliar.h"
#include "Tabuleiro.h"


int auxiliar:: GetBoardSize() {
	bool quit = false;
	int boardSize = 0;
	string boardInput;
	do {
		try {
			system("cls");


			std::cout << "\t What's the size of the board do want to play?";
			std::cin >> boardInput;
			boardSize = std::stoi(boardInput);
			if (boardSize  > 0) {

				string quitOp;
				cout << "\t are you sure this is the correct size of the board?";
				std::cin >> quitOp;

				if (quitOp.find("sim") != string::npos || quitOp.find("yes") != string::npos) {
					quit = true;
				}else {
					std::cout << "\t Please retry again, anwser Yes, Sim to accept ";
					system("pause");
				}
			}
		}
		catch (const std::invalid_argument& ex) {
			std::cout << "\t Please input the correct input";
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

