#include "define.h"

#include "c_rect.h"
#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"


int main(int argc, char* argv[]) {
	//VARIABLES
	Window_Renderer w_r;		//fenetre et rendu

	c_pad p_1;			//raquette joueur
	c_ball ball;		//balle

	c_score score_1;		//tableau des scores

	FPS_Manager fps;		//gestion des fps

	bool is_running;		//etat du jeu
	int is_service;			//0 -> en jeu, 1-> en service, 2-> service donné

	//bool briques[LIGNES * COLONNES];

	//MAIN
	init(w_r, score_1, p_1, ball, fps, is_service, is_running);

	while (is_running) {
		event_handler(is_running, is_service, p_1, ball, score_1, fps);

		update(w_r, score_1, ball, p_1, is_service);

		render(w_r, fps, score_1, ball, p_1);
	}


	quit(w_r, score_1);

	return 0;
}