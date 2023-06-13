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
	string** tabuleiroFinal;
	int boardSize;

	Tabuleiro(int);

	~Tabuleiro();

	/// <summary>
	/// Dar print do tabuleiro (TABULEIRO DE CALCULO) no ecr�
	/// </summary>
	void printBoard();

	/// <summary>
	/// Mostra o tabueliro do jogador
	/// </summary>
	void ShowTabuleiro();

	/// <summary>
	/// Posicionar Bombas e em linhas todas diferentes e colunas todas diferentes
	/// </summary>
	void PosicionarBombas();

	/// <summary>
	/// Posicionar numeros a volta do
	/// </summary>
	void PosicionarHints(coordsMinas);

	/// <summary>
	/// Fun��o que serve para O jogador fazer GUESS
	/// </summary>
	bool Guess();

	/// <summary>
	/// Fun��o que serve para verificar os espa�os proximos do tabuleiro
	/// </summary>
	void CheckSpaces(coordsMinas);

	/// <summary>
	/// Verifica se o player ganhou
	/// </summary>
	bool WinningChecker();
	
};


