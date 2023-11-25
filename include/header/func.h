#include <stdio.h>
#include <stdbool.h>

struct PVPHistorico {
	int partidasJogadas;
  int vitoriasP1;
  int vitoriasP2;
  int partidaCurta;
  int partidaLonga;
};

struct PVCHistorico {
	int partidasJogadas;
  int vitoriasP1;
  int vitoriasP2;
  int partidaCurta;
  int partidaLonga;
};

struct casa {
	float	posX;
	float posY;
	int player;				// 0 = casa vazia / 1 = player1 / 2 = player2 
	bool isPossibleMove;
	bool isSelected;
};

bool saveFile(size_t x, size_t y, struct casa tabuleiro[x][y], bool isOnPVP, bool isOnPVC, int timer);

bool loadSaveFile(size_t x, size_t y, struct casa tabuleiro[x][y], bool isOnPVP, bool isOnPVC, ALLEGRO_TIMER *timer);

void writeFileHistorico(struct PVPHistorico filePVP, struct PVCHistorico filePVC);

void readFileHistorico(struct PVPHistorico filePVP, struct PVCHistorico filePVC);

bool checaVictory(size_t x, size_t y, struct casa tabuleiro[x][y], int vez);

int geraCordRandom();

bool checaAtaqueEsquerda(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer, int contLoop);

bool checaAtaqueDireita(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer, int contLoop);

bool checaAtaqueCima(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer, int contLoop);

bool checaAtaqueBaixo(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int iOrig, int jSelected, int jOrig, int flagPodeComer, int contLoop);

int flipaVez(int vez);

void limpaSelectedTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y]);

void checaPossibleMoves(size_t x, size_t y, struct casa tabuleiro[x][y], int iSelected, int jSelected);

void desenhaTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y], ALLEGRO_BITMAP *peca_P1, ALLEGRO_BITMAP *peca_P1_Selected, ALLEGRO_BITMAP *peca_P1_Alvo, ALLEGRO_BITMAP *peca_P2,  ALLEGRO_BITMAP *peca_P2_Selected, ALLEGRO_BITMAP *peca_P2_Alvo, ALLEGRO_BITMAP *dot_isPossibleMove);

void inicializaTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y]);