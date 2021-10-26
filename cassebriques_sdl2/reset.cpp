#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"
#include "c_brique.h"


void reset(c_score& score, int&is_service, c_pad&pad, int&n_briques, c_brique briques[]) {
	//BUT	:réinitialiser le plateau de jeu et les variables associées
	//ENTREE:score, deux entiers, la raquette du joueur, le tableau des briques
	//SORTIE:/

	score.set_score(LIVES);

	pad.set_rect_pos(pad.get_x_i(), pad.get_y_i());

	for (int n_i = 0; n_i < (LIGNES * COLONNES); n_i++)
		briques[n_i].set_actif(true);

	n_briques = LIGNES * COLONNES;

	is_service = 1;
}