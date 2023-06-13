#include "auxiliar.h"
int auxiliar:: getBoardSize() {
	bool quit = false;
	int boardSize = 0;

	do {
		system("cls");


		cout << "\t What's the size of the board do want to play?";
		cin >> boardSize;
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
	} while (!quit);

	return boardSize;
}