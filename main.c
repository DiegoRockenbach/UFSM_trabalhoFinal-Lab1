#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "include/header/func.h"


bool checaAtaqueEsquerda(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer){

	int j;

	printf("\nentrou checaAtaqueEsquerda\n");

	for (j = jSelected-1; j >= 0; j--){
		if (tabuleiro[iSelected][j].player == vez){
			return false;
		}
		else if (tabuleiro[iSelected][j].player != 0 && tabuleiro[iSelected][j].player != vez && flagPodeComer == true){
			return true;
		}
	}

	if (iSelected == 1){
		iSelected = 0;
		jSelected = 1;

		flagPodeComer = true;
		return checaAtaqueBaixo(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (iSelected == 2){
		iSelected = 0;
		jSelected = 2;

		flagPodeComer = true;
		return checaAtaqueBaixo(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (iSelected == 3){
		iSelected = 5;
		jSelected = 2;

		flagPodeComer = true;
		return checaAtaqueCima(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (iSelected == 4){
		iSelected = 5;
		jSelected = 1;

		flagPodeComer = true;
		return checaAtaqueCima(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else {
		return false;
	}

}

bool checaAtaqueDireita(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer){

	int j;

		printf("\nentrou checaAtaqueDireita\n");

	for (j = jSelected+1; j < 6; j++){
		if (tabuleiro[iSelected][j].player == vez){
			return false;
		}
		else if (tabuleiro[iSelected][j].player != 0 && tabuleiro[iSelected][j].player != vez && flagPodeComer == true){
			return true;
		}
	}

	if (iSelected == 1){
		iSelected = 0;
		jSelected = 4;

		flagPodeComer = true;
		return checaAtaqueBaixo(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (iSelected == 2){
		iSelected = 0;
		jSelected = 3;

		flagPodeComer = true;
		return checaAtaqueBaixo(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (iSelected == 3){
		iSelected = 5;
		jSelected = 3;

		flagPodeComer = true;
		return checaAtaqueCima(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (iSelected == 4){
		iSelected = 5;
		jSelected = 4;

		flagPodeComer = true;
		return checaAtaqueCima(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else {
		return false;
	}

}

bool checaAtaqueCima(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer){

	int i;

	printf("\nentrou checaAtaqueCima\n");

	for (i = iSelected-1; i >= 0; i--){
		if (tabuleiro[i][jSelected].player == vez){
			return false;
		}
		else if (tabuleiro[i][jSelected].player != 0 && tabuleiro[i][jSelected].player != vez && flagPodeComer == true){
			return true;
		}
	}

	if (jSelected == 1){
		iSelected = 1;
		jSelected = 0;

		flagPodeComer = true;
		return checaAtaqueDireita(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (jSelected == 2){
		iSelected = 2;
		jSelected = 0;

		flagPodeComer = true;
		return checaAtaqueDireita(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (jSelected == 3){
		iSelected = 2;
		jSelected = 5;

		flagPodeComer = true;
		return checaAtaqueEsquerda(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (jSelected == 4){
		iSelected = 1;
		jSelected = 5;

		flagPodeComer = true;
		return checaAtaqueEsquerda(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else {
		return false;
	}

}

bool checaAtaqueBaixo(size_t x, size_t y, struct casa tabuleiro[x][y], int vez, int iSelected, int jSelected, int flagPodeComer){

	int i;

	printf("\nentrou checaAtaqueBaixo\n");

	for (i = iSelected+1; i < 6; i++){
		if (tabuleiro[i][jSelected].player == vez){
			return false;
		}
		else if (tabuleiro[i][jSelected].player != 0 && tabuleiro[i][jSelected].player != vez && flagPodeComer == true){
			return true;
		}
	}

	if (jSelected == 1){
		iSelected = 4;
		jSelected = 0;

		flagPodeComer = true;
		return checaAtaqueDireita(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (jSelected == 2){
		iSelected = 3;
		jSelected = 0;

		flagPodeComer = true;
		return checaAtaqueDireita(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (jSelected == 3){
		iSelected = 3;
		jSelected = 5;

		flagPodeComer = true;
		return checaAtaqueEsquerda(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else if (jSelected == 4){
		iSelected = 4;
		jSelected = 5;

		flagPodeComer = true;
		return checaAtaqueEsquerda(6, 6, tabuleiro, vez, iSelected, jSelected, flagPodeComer);
	}
	else {
		return false;
	}

}




void limpaSelectedTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y]){

	int i, j;

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			tabuleiro[i][j].isPossibleMove = false;
			tabuleiro[i][j].isSelected = false;
		}
	}

}

void checaPossibleMoves(size_t x, size_t y, struct casa tabuleiro[x][y], int iSelected, int jSelected){
	
	if (iSelected == 0 && jSelected == 0){
		if (tabuleiro[iSelected][jSelected+1].player == 0){
			tabuleiro[iSelected][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected].player == 0){
			tabuleiro[iSelected+1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected+1].player == 0){
			tabuleiro[iSelected+1][jSelected+1].isPossibleMove = true;
		}
	}
	else if (iSelected == 0 && jSelected == 5){
		if (tabuleiro[iSelected][jSelected-1].player == 0){
			tabuleiro[iSelected][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected].player == 0){
			tabuleiro[iSelected+1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected-1].player == 0){
			tabuleiro[iSelected+1][jSelected-1].isPossibleMove = true;
		}
	}
	else if (iSelected == 5 && jSelected == 0){
		if (tabuleiro[iSelected-1][jSelected].player == 0){
			tabuleiro[iSelected-1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected][jSelected+1].player == 0){
			tabuleiro[iSelected][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected+1].player == 0){
			tabuleiro[iSelected-1][jSelected+1].isPossibleMove = true;
		}
	}
	else if (iSelected == 5 && jSelected == 5){
		if (tabuleiro[iSelected][jSelected-1].player == 0){
			tabuleiro[iSelected][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected].player == 0){
			tabuleiro[iSelected-1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected-1].player == 0){
			tabuleiro[iSelected-1][jSelected-1].isPossibleMove = true;
		}
	}
	else if (iSelected == 0 && jSelected > 0 && jSelected < 5){
		if (tabuleiro[iSelected][jSelected-1].player == 0){
			tabuleiro[iSelected][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected][jSelected+1].player == 0){
			tabuleiro[iSelected][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected-1].player == 0){
			tabuleiro[iSelected+1][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected].player == 0){
			tabuleiro[iSelected+1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected+1].player == 0){
			tabuleiro[iSelected+1][jSelected+1].isPossibleMove = true;
		}
	}
	else if (iSelected > 0 && iSelected < 5 && jSelected == 5){
		if (tabuleiro[iSelected-1][jSelected-1].player == 0){
			tabuleiro[iSelected-1][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected].player == 0){
			tabuleiro[iSelected-1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected][jSelected-1].player == 0){
			tabuleiro[iSelected][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected-1].player == 0){
			tabuleiro[iSelected+1][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected].player == 0){
			tabuleiro[iSelected+1][jSelected].isPossibleMove = true;
		}
	}
	else if (iSelected > 0 && iSelected < 5 && jSelected == 0){
		if (tabuleiro[iSelected-1][jSelected].player == 0){
			tabuleiro[iSelected-1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected+1].player == 0){
			tabuleiro[iSelected-1][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected][jSelected+1].player == 0){
			tabuleiro[iSelected][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected].player == 0){
			tabuleiro[iSelected+1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected+1].player == 0){
			tabuleiro[iSelected+1][jSelected+1].isPossibleMove = true;
		}
	}
	else if (iSelected == 5 && jSelected > 0 && jSelected < 5){
		if (tabuleiro[iSelected][jSelected-1].player == 0){
			tabuleiro[iSelected][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected-1].player == 0){
			tabuleiro[iSelected-1][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected].player == 0){
			tabuleiro[iSelected-1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected+1].player == 0){
			tabuleiro[iSelected-1][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected][jSelected+1].player == 0){
			tabuleiro[iSelected][jSelected+1].isPossibleMove = true;
		}
	}
	else if (iSelected > 0 && iSelected < 5 && jSelected > 0 && jSelected < 5){
		if (tabuleiro[iSelected-1][jSelected-1].player == 0){
			tabuleiro[iSelected-1][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected].player == 0){
			tabuleiro[iSelected-1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected-1][jSelected+1].player == 0){
			tabuleiro[iSelected-1][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected][jSelected-1].player == 0){
			tabuleiro[iSelected][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected][jSelected+1].player == 0){
			tabuleiro[iSelected][jSelected+1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected-1].player == 0){
			tabuleiro[iSelected+1][jSelected-1].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected].player == 0){
			tabuleiro[iSelected+1][jSelected].isPossibleMove = true;
		}
		if (tabuleiro[iSelected+1][jSelected+1].player == 0){
			tabuleiro[iSelected+1][jSelected+1].isPossibleMove = true;
		}
	}

}

void desenhaTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y], ALLEGRO_BITMAP *peca_P1, ALLEGRO_BITMAP *peca_P1_Selected, ALLEGRO_BITMAP *peca_P2,  ALLEGRO_BITMAP *peca_P2_Selected, ALLEGRO_BITMAP *dot_isPossibleMove) {
	
	int i, j;

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			if (tabuleiro[i][j].player == 1){
				if (tabuleiro[i][j].isSelected == true){
					al_draw_bitmap(peca_P1_Selected, tabuleiro[i][j].posX, tabuleiro[i][j].posY, 0);
				}
				else {
					al_draw_bitmap(peca_P1, tabuleiro[i][j].posX, tabuleiro[i][j].posY, 0);
				}	
			}
			else if (tabuleiro[i][j].player == 2){
				if (tabuleiro[i][j].isSelected == true){
					al_draw_bitmap(peca_P2_Selected, tabuleiro[i][j].posX, tabuleiro[i][j].posY, 0);
				}
				else {
					al_draw_bitmap(peca_P2, tabuleiro[i][j].posX, tabuleiro[i][j].posY, 0);
				}
			}
			else if (tabuleiro[i][j].player == 0 && tabuleiro[i][j].isPossibleMove == true){
				al_draw_bitmap(dot_isPossibleMove, tabuleiro[i][j].posX, tabuleiro[i][j].posY, 0);	//ta spawnando no x = 230 y = 325 e temq ir pra x = 240 e y = 335
			}
		}
	}
	
}

void inicializaTabuleiro(size_t x, size_t y, struct casa tabuleiro[x][y]) {

	int i, j;

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			if (i < 2){
				tabuleiro[i][j].posX = 240 + (48 * j) - 15;
				tabuleiro[i][j].posY = 245 + (46 * i) - 15;
				tabuleiro[i][j].player = 1;
				tabuleiro[i][j].isPossibleMove = false;
				tabuleiro[i][j].isSelected = false;
			}
			else if (i > 1 && i < 4){
				tabuleiro[i][j].posX = 240 + (48 * j) - 15;
				tabuleiro[i][j].posY = 245 + (46 * i) - 15;
				tabuleiro[i][j].player = 0;
				tabuleiro[i][j].isPossibleMove = false;
				tabuleiro[i][j].isSelected = false;
			}
			else if (i > 3){
				tabuleiro[i][j].posX = 240 + (48 * j) - 15;
				tabuleiro[i][j].posY = 245 + (46 * i) - 15;
				tabuleiro[i][j].player = 2;
				tabuleiro[i][j].isPossibleMove = false;
				tabuleiro[i][j].isSelected = false;
			}
		}
	}

}

int main() {

	int i, j, iSelected, jSelected, vez = 1;
	float x, y;
	bool isOnMenu = true, isOnPVP = false, isWaitingForMove = false;

	struct casa tabuleiro[6][6];

	al_init();
	al_init_image_addon();
	al_install_mouse();
	
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	ALLEGRO_DISPLAY *disp = al_create_display(720, 719);
	ALLEGRO_BITMAP *menuBG = al_load_bitmap("include/images/menu.png");
	ALLEGRO_BITMAP *mainBG = al_load_bitmap("include/images/tabuleiro.png");
	ALLEGRO_BITMAP *peca_P1 = al_load_bitmap("include/images/peca_preta.png");
	ALLEGRO_BITMAP *peca_P1_Selected = al_load_bitmap("include/images/peca_preta_Selected.png");
	ALLEGRO_BITMAP *peca_P2 = al_load_bitmap("include/images/peca_branca.png");
	ALLEGRO_BITMAP *peca_P2_Selected = al_load_bitmap("include/images/peca_branca_Selected.png");
	ALLEGRO_BITMAP *dot_isPossibleMove = al_load_bitmap("include/images/dotPossibleMove.png");
	
	
	ALLEGRO_FONT *font = al_create_builtin_font();

	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());

	inicializaTabuleiro(6, 6, tabuleiro);

	bool done = false;
	bool redraw = true;
	ALLEGRO_EVENT event;

	al_start_timer(timer);
	while (true) {
		al_wait_for_event(queue, &event);

		switch(event.type) {

			case ALLEGRO_EVENT_TIMER:
				redraw = true;
				break;

			case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
				if (isOnMenu == true){
					if (event.mouse.x >= 235 && event.mouse.y >= 150 && event.mouse.x <= 515 && event.mouse.y <= 265){
						isOnMenu = false;
						isOnPVP = true;
					}
					else if (event.mouse.x >= 235 && event.mouse.y >= 435 && event.mouse.x <= 515 && event.mouse.y <= 550){
						printf("\nPlayer vs Computer button!\n");
					}
				}

				if (isOnPVP == true){
					for (i = 0; i < 6; i++){
						for (j = 0; j < 6; j++){
							if (isWaitingForMove == true){
								if (((event.mouse.x >= tabuleiro[i][j].posX) && (event.mouse.x <= tabuleiro[i][j].posX + 30) && (event.mouse.y >= tabuleiro[i][j].posY) && (event.mouse.y <= tabuleiro[i][j].posY + 25)) && (tabuleiro[i][j].isPossibleMove == true)){
									
									tabuleiro[i][j].player = vez;
									tabuleiro[iSelected][jSelected].player = 0;

									event.mouse.x = 0;
									event.mouse.y = 0;
									limpaSelectedTabuleiro(6, 6, tabuleiro);
									desenhaTabuleiro(6, 6, tabuleiro, peca_P1, peca_P1_Selected, peca_P2, peca_P2_Selected, dot_isPossibleMove);
									isWaitingForMove = false;
								}
								else if (((event.mouse.x >= tabuleiro[i][j].posX) && (event.mouse.x <= tabuleiro[i][j].posX + 30) && (event.mouse.y >= tabuleiro[i][j].posY) && (event.mouse.y <= tabuleiro[i][j].posY + 25)) && (tabuleiro[i][j].isPossibleMove == false)) {
									event.mouse.x = 0;
									event.mouse.y = 0;
									limpaSelectedTabuleiro(6, 6, tabuleiro);
									desenhaTabuleiro(6, 6, tabuleiro, peca_P1, peca_P1_Selected, peca_P2, peca_P2_Selected, dot_isPossibleMove);
									isWaitingForMove = false;
								}
							}

							if (tabuleiro[i][j].player == vez){
								if ((event.mouse.x >= tabuleiro[i][j].posX) && (event.mouse.x <= tabuleiro[i][j].posX + 30) && (event.mouse.y >= tabuleiro[i][j].posY) && (event.mouse.y <= tabuleiro[i][j].posY + 25)){
									tabuleiro[i][j].isSelected = true;
									iSelected = i;
									jSelected = j;
									checaPossibleMoves(6, 6, tabuleiro, i, j);



									if (jSelected == 1 || jSelected == 2 || jSelected == 3 || jSelected == 4){
										if (checaAtaqueEsquerda(6, 6, tabuleiro, vez, iSelected, jSelected, false) == true){
											printf("pode comer pra esquerda!\n");
										}
										else {
											printf("nao pode comer pra esquerda!\n");
										}
										if (checaAtaqueDireita(6, 6, tabuleiro, vez, iSelected, jSelected, false) == true){
											printf("pode comer pra direita!\n");
										}
										else {
											printf("nao pode comer pra direita!\n");
										}
										if (checaAtaqueCima(6, 6, tabuleiro, vez, iSelected, jSelected, false) == true){
											printf("pode comer pra cima!\n");
										}
										else {
											printf("nao pode comer pra cima!\n");
										}
										if (checaAtaqueBaixo(6, 6, tabuleiro, vez, iSelected, jSelected, false) == true){
											printf("pode comer pra baixo!\n");
										}
										else {
											printf("nao pode comer pra baixo!\n");
										}
									}




									isWaitingForMove = true;
								}
							}
						}
					}
				}
				
				redraw = true;
				x = event.mouse.x;
				y = event.mouse.y;
				break;

			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				break;
		}

		if (done) {
			break;
		}

		if (redraw == true && al_is_event_queue_empty(queue)) {

			if (isOnMenu == true){
				al_draw_bitmap(menuBG, 0, 0, 0);

				al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", x, y);
			}
			if (isOnPVP == true){
				al_draw_bitmap(mainBG, 0, 0, 0);
				desenhaTabuleiro(6, 6, tabuleiro, peca_P1, peca_P1_Selected, peca_P2, peca_P2_Selected, dot_isPossibleMove);

				al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", x, y);
			}


			
			al_flip_display();

			redraw = false;
		}
	}


	al_destroy_bitmap(menuBG);
	al_destroy_bitmap(mainBG);
	al_destroy_bitmap(peca_P1);
	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);

	return 0;
}