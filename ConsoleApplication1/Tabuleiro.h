#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Tabuleiro
{
public:

	struct coordsMinas
	{
		int l, c;
	};

	string** tabuleiro;
	int boardSize;

	Tabuleiro(int);

	~Tabuleiro();

	/// <summary>
	/// Dar print do tabuleiro no ecrã
	/// </summary>
	void printBoard();

	/// <summary>
	/// Posicionar Bombas e em linhas todas diferentes e colunas todas diferentes
	/// </summary>
	void PosicionarBombas();

	/// <summary>
	/// Posicionar numeros a volta do
	/// </summary>
	void PosicionarHints(coordsMinas);


	
};


