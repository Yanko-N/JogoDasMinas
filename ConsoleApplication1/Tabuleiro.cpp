#include "Tabuleiro.h"

Tabuleiro::Tabuleiro(int boardSize) {
	this->boardSize = boardSize;
	tabuleiro = new string * [boardSize];
	tabuleiroFinal = new string * [boardSize];

	for (int i = 0; i < boardSize; i++) {

		tabuleiro[i] = new string[boardSize];
		tabuleiroFinal[i] = new string[boardSize];

		for (int j = 0; j < boardSize; j++) {

			tabuleiro[i][j] = ' ';
			tabuleiroFinal[i][j] = ' ';
		}
	}
}

Tabuleiro::~Tabuleiro() {
	for (int i = 0; i < this->boardSize; i++) {

		delete[] tabuleiro[i];
		delete[] tabuleiroFinal[i];
	}
	delete[] tabuleiro;
	delete[] tabuleiroFinal;
}

void Tabuleiro::printBoard() {
	cout << "  ";
	for (int coluna = 0; coluna < this->boardSize; coluna++) {
		if (this->boardSize >= 10) {
			if (coluna <= 10) {
				cout << "  " << coluna;
			}
			else {
				cout << " " << coluna;
			}

		}
		else
		{
			cout << "  " << coluna;
		}

	}
	cout << endl;

	for (int linha = 0; linha < this->boardSize; linha++) {

		for (int coluna = 0; coluna < this->boardSize; coluna++) {
			if (coluna == 0) {
				if (linha >= 10) {
					cout << linha << " ";
				}
				else
				{
					cout << linha << "  ";
				}

			}
			cout << "[" << tabuleiro[linha][coluna] << "]";
		}
		cout << endl;
	}

}

void Tabuleiro::ShowTabuleiro() {
	cout << "  ";
	for (int coluna = 0; coluna < this->boardSize; coluna++) {
		if (this->boardSize >= 10) {
			if (coluna <= 10) {
				cout << "  " << coluna;
			}
			else {
				cout << " " << coluna;
			}

		}
		else
		{
			cout << "  " << coluna;
		}

	}
	cout << endl;

	for (int linha = 0; linha < this->boardSize; linha++) {

		for (int coluna = 0; coluna < this->boardSize; coluna++) {
			if (coluna == 0) {
				if (linha >= 10) {
					cout << linha << " ";
				}
				else
				{
					cout << linha << "  ";
				}

			}
			cout << "[" << tabuleiroFinal[linha][coluna] << "]";
		}
		cout << endl;
	}
}

void Tabuleiro::PosicionarBombas() {
	srand((unsigned)time(NULL));
	int* randomNumbersX = new int[this->boardSize];
	int* randomNumbersY = new int[this->boardSize];

	for (int i = 0; i < this->boardSize; i++) {

		//calcular valores aleatorios diferentes para as linhas 
		bool xEqual;
		int randomx;
		do {
			xEqual = false;
			randomx = rand() % (this->boardSize);
			for (int j = 0; j < this->boardSize; j++) {
				if (randomNumbersX[j] == randomx)
				{
					xEqual = true;
				}
			}
		} while (xEqual);

		randomNumbersX[i] = randomx;

		//calcular valores aleatorios diferentes para as colunas 
		bool yEqual;
		int randomy;
		do {
			yEqual = false;
			randomy = rand() % (this->boardSize);
			for (int j = 0; j < this->boardSize; j++) {
				if (randomNumbersY[j] == randomy)
				{
					yEqual = true;
				}
			}
		} while (yEqual);

		randomNumbersY[i] = randomy;
	}

	//for debug purpose shows the position of the minas
	for (int i = 0; i < this->boardSize; i++) {
		cout << "[" << randomNumbersX[i] << "," << randomNumbersY[i] << "]\t\n";
	}

	//coloco o tabuleiro tudo a 0
	for (int l = 0; l < this->boardSize; l++) {

		for (int c = 0; c < this->boardSize; c++) {

			tabuleiro[l][c] = '0';
		}
	}

	for (int index = 0; index < this->boardSize; index++) {

		tabuleiro[randomNumbersX[index]][randomNumbersY[index]] = 'x';
		coordsMinas coords;
		coords.l = randomNumbersX[index];
		coords.c = randomNumbersY[index];
		PosicionarHints(coords);
	}


}

void Tabuleiro::PosicionarHints(coordsMinas coords) {
	try {
		string aux;

		if (coords.l > 0 && coords.c > 0) {
			aux = tabuleiro[coords.l - 1][coords.c - 1];

			if (aux != "x") {
				int se = std::stoi(aux);
				se++;
				tabuleiro[coords.l - 1][coords.c - 1] = to_string(se);
			}



		}

		if (coords.l > 0) {
			aux = tabuleiro[coords.l - 1][coords.c];
			if (aux != "x") {

				int s = std::stoi(aux);
				s++;
				tabuleiro[coords.l - 1][coords.c] = to_string(s);
			}

		}

		if (coords.l < this->boardSize - 1 && coords.c < this->boardSize - 1) {
			aux = tabuleiro[coords.l + 1][coords.c + 1];
			if (aux != "x") {
				int bd = std::stoi(aux);
				bd++;
				tabuleiro[coords.l + 1][coords.c + 1] = to_string(bd);

			}
		}

		if (coords.l > 0 && coords.c < this->boardSize - 1) {
			aux = tabuleiro[coords.l - 1][coords.c + 1];
			if (aux != "x") {
				int sd = std::stoi(aux);
				sd++;
				tabuleiro[coords.l - 1][coords.c + 1] = to_string(sd);
			}
		}

		if (coords.c > 0) {
			aux = tabuleiro[coords.l][coords.c - 1];
			if (aux != "x") {
				int e = std::stoi(aux);
				e++;
				tabuleiro[coords.l][coords.c - 1] = to_string(e);
			}
		}

		if (coords.c < this->boardSize - 1) {
			aux = tabuleiro[coords.l][coords.c + 1];
			if (aux != "x") {
				int d = std::stoi(aux);
				d++;
				tabuleiro[coords.l][coords.c + 1] = to_string(d);
			}
		}


		if (coords.l < this->boardSize - 1 && coords.c > 0) {
			aux = tabuleiro[coords.l + 1][coords.c - 1];
			if (aux != "x") {
				int be = std::stoi(aux);
				be++;
				tabuleiro[coords.l + 1][coords.c - 1] = to_string(be);
			}
		}

		if (coords.l < this->boardSize - 1) {
			aux = tabuleiro[coords.l + 1][coords.c];
			if (aux != "x") {
				int b = std::stoi(aux);
				b++;
				tabuleiro[coords.l + 1][coords.c] = to_string(b);
			}
		}



	}
	catch (const std::exception& ex) {
		cout << "Error:" << ex.what() << endl;
	}
}

bool Tabuleiro::Guess() {

	std::cout << "Guessing:" << endl;
	std::cout << "Linha :";
	string linha;
	std::cin >> linha;
	try {
		int l = std::stoi(linha);

		if (l >= 0 && l < this->boardSize) {
			//continua

			std::cout << "Coluna :";
			string coluna;
			std::cin >> coluna;
			try {
				int c = std::stoi(coluna);

				if (c >= 0 && c < this->boardSize) {
					//continua

					if (this->tabuleiro[l][c] == "x") {
						//GameOver
						return false;
					}
					else
					{
						system("cls");
						//Coordenada inicial
						coordsMinas coords;
						coords.l = l;
						coords.c = c;
						CheckSpaces(coords);
						return true;
					}

				}
				else {
					std::cout << "ERROR: INVALID NUMBER" << endl;
				}
			}
			catch (const std::exception& ex) {
				std::cout << "ERROR:" << ex.what() << endl;
			}
		}
		else
		{
			std::cout << "ERROR: INVALID NUMBER" << endl;
		}
	}
	catch (const std::exception& ex) {
		std::cout << "ERROR:" << ex.what() << endl;
	}


}

void Tabuleiro::CheckSpaces(coordsMinas coords) {

	try {
		string aux;

		aux = tabuleiro[coords.l][coords.c];
		if (aux != "x" && tabuleiroFinal[coords.l][coords.c] == " ") {
			tabuleiroFinal[coords.c][coords.l] = aux;
		}

		if (coords.l > 0 && coords.c > 0) {
			aux = tabuleiro[coords.l - 1][coords.c - 1];

			if (aux == "0" && tabuleiroFinal[coords.l - 1][coords.c - 1] == " ") {
				tabuleiroFinal[coords.l - 1][coords.c - 1] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l - 1;
				newCoords.c = coords.c - 1;
			}
			else if (aux != "x" && tabuleiroFinal[coords.l - 1][coords.c - 1] == " ") {
				tabuleiroFinal[coords.l - 1][coords.c - 1] = aux;
			}

		}

		if (coords.l > 0) {
			aux = tabuleiro[coords.l - 1][coords.c];
			if (aux == "0" && tabuleiroFinal[coords.l - 1][coords.c] == " ") {
				tabuleiroFinal[coords.l - 1][coords.c] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l - 1;
				newCoords.c = coords.c;
				CheckSpaces(newCoords);
			}
			else if (aux != "x" && tabuleiroFinal[coords.l - 1][coords.c] == " ") {
				tabuleiroFinal[coords.l - 1][coords.c] = aux;
			}

		}

		if (coords.l < this->boardSize - 1 && coords.c < this->boardSize - 1) {
			aux = tabuleiro[coords.l + 1][coords.c + 1];
			if (aux == "0" && tabuleiroFinal[coords.l + 1][coords.c + 1] == " ") {
				tabuleiroFinal[coords.l + 1][coords.c + 1] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l + 1;
				newCoords.c = coords.c + 1;
				CheckSpaces(newCoords);

			}
			else if (aux != "x" && tabuleiroFinal[coords.l + 1][coords.c + 1] == " ") {
				tabuleiroFinal[coords.l + 1][coords.c + 1] = aux;
			}
		}

		if (coords.l > 0 && coords.c < this->boardSize - 1) {
			aux = tabuleiro[coords.l - 1][coords.c + 1];
			if (aux == "0" && tabuleiroFinal[coords.l - 1][coords.c + 1] == " ") {
				tabuleiroFinal[coords.l - 1][coords.c + 1] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l - 1;
				newCoords.c = coords.c + 1;
				CheckSpaces(newCoords);

			}
			else if (aux != "x" && tabuleiroFinal[coords.l - 1][coords.c + 1] == " ") {
				tabuleiroFinal[coords.l - 1][coords.c + 1] = aux;
			}
		}

		if (coords.c > 0) {
			aux = tabuleiro[coords.l][coords.c - 1];
			if (aux == "0" && tabuleiroFinal[coords.l][coords.c - 1] == " ") {
				tabuleiroFinal[coords.l][coords.c - 1] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l;
				newCoords.c = coords.c - 1;
				CheckSpaces(newCoords);

			}
			else if (aux != "x" && tabuleiroFinal[coords.l][coords.c - 1] == " ") {
				tabuleiroFinal[coords.l][coords.c - 1] = aux;
			}
		}

		if (coords.c < this->boardSize - 1) {
			aux = tabuleiro[coords.l][coords.c + 1];
			if (aux == "0" && tabuleiroFinal[coords.l][coords.c + 1] == " ") {
				tabuleiroFinal[coords.l][coords.c + 1] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l;
				newCoords.c = coords.c + 1;
				CheckSpaces(newCoords);

			}
			else if (aux != "x" && tabuleiroFinal[coords.l][coords.c + 1] == " ") {
				tabuleiroFinal[coords.l][coords.c + 1] = aux;
			}
		}


		if (coords.l < this->boardSize - 1 && coords.c > 0) {
			aux = tabuleiro[coords.l + 1][coords.c - 1];
			if (aux == "0" && tabuleiroFinal[coords.l + 1][coords.c - 1] == " ") {
				tabuleiroFinal[coords.l + 1][coords.c - 1] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l + 1;
				newCoords.c = coords.c - 1;
				CheckSpaces(newCoords);

			}
			else if (aux != "x" && tabuleiroFinal[coords.l + 1][coords.c - 1] == " ") {
				tabuleiroFinal[coords.l + 1][coords.c - 1] = aux;
			}
		}

		if (coords.l < this->boardSize - 1) {
			aux = tabuleiro[coords.l + 1][coords.c];
			if (aux == "0" && tabuleiroFinal[coords.l + 1][coords.c] == " ") {
				tabuleiroFinal[coords.l + 1][coords.c] = "0";
				coordsMinas newCoords;
				newCoords.l = coords.l + 1;
				newCoords.c = coords.c;
				CheckSpaces(newCoords);

			}
			else if (aux != "x" && tabuleiroFinal[coords.l + 1][coords.c] == " ") {
				tabuleiroFinal[coords.l + 1][coords.c] = aux;
			}
		}

	}
	catch (const std::exception& ex) {
		cout << "Error:" << ex.what() << endl;
	}
}

bool Tabuleiro::WinningChecker() {
	int boardNumber = (this->boardSize * this->boardSize) - this->boardSize;
	int counter = 0;

	for (int linha = 0; linha < this->boardSize; linha++) {
		for (int coluna = 0; coluna < this->boardSize; coluna++) {
			if (tabuleiro[linha][coluna] == tabuleiroFinal[linha][coluna]) {
				counter++;
			}
		}
	}

	if (counter == boardNumber) {
		return true;
	}
	else
	{
		return false;
	}
}

