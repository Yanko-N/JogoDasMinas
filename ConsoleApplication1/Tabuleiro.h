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
	/// Dar print do tabuleiro (TABULEIRO DE CALCULO) no ecrã
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
	/// Função que serve para O jogador fazer GUESS
	/// </summary>
	bool Guess();

	/// <summary>
	/// Função que serve para verificar os espaços proximos do tabuleiro
	/// </summary>
	void CheckSpaces(coordsMinas);

	/// <summary>
	/// Verifica se o player ganhou
	/// </summary>
	bool WinningChecker();
	
};


