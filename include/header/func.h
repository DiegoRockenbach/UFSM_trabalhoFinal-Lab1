#include <stdio.h>
#include <stdbool.h>

struct casa {
	float	posX;
	float posY;
	int player;				// 0 = casa vazia / 1 = player1 / 2 = player2 / 3 = computador
	bool isPossibleMove;
	bool isSelected;
};


bool checaAtaqueCima(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer);

bool checaAtaqueBaixo(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer);

bool checaAtaqueEsquerda(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer);

bool checaAtaqueDireita(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer);