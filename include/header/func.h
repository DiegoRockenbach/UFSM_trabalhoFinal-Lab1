#include <stdio.h>
#include <stdbool.h>

struct casa {
	float	posX;
	float posY;
	int player;				// 0 = casa vazia / 1 = player1 / 2 = player2
	bool isPossibleMove;
	bool isSelected;
};

int geraCordRandom();

bool checaAtaqueEsquerda(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer);

bool checaAtaqueDireita(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer);

bool checaAtaqueCima(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer);

bool checaAtaqueBaixo(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer);

int flipaVez(int vez);

void limpaSelectedTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y]);

void checaPossibleMoves(size_t x, size_t y, struct casa tabuleiro[x][y], int iSelected, int jSelected);

void desenhaTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y], ALLEGRO_BITMAP *peca_P1, ALLEGRO_BITMAP *peca_P1_Selected, ALLEGRO_BITMAP *peca_P1_Alvo, ALLEGRO_BITMAP *peca_P2,  ALLEGRO_BITMAP *peca_P2_Selected, ALLEGRO_BITMAP *peca_P2_Alvo, ALLEGRO_BITMAP *dot_isPossibleMove);

void inicializaTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y]);