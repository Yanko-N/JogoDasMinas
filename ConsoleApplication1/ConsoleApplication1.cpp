// ConsoleApplication1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "auxiliar.h"
#include "Tabuleiro.h"

using namespace std;
static auxiliar aux;

int main()
{

	cout << "\tJogo das Minas \n \t Desenvolvido por Vitor Novo\n";
	system("pause");
	bool quit = false;
	do {
		system("cls");
		string op;
		cout << "\n\t1-Play\n\t2-Quit\n r.:";
		cin >> op;
		
		if (op.find("1") != string::npos) {
			//play option
			cout << "PLAY";
			int boardGameSize = aux.getBoardSize();

			Tabuleiro tabuleiro = Tabuleiro(boardGameSize);
			
			tabuleiro.PosicionarBombas();
			tabuleiro.printBoard();
			system("pause");
		
		}
		else if(op.find("2") != string::npos)
		{
			//quit option
			quit = true;
		}
		else
		{
			//exeption
			cout << " \n\n\tERROR that's not a valid option";
		}

	} while (!quit);


	

}



