#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"
#include "c_brique.h"


void collisions(c_pad& p_1, c_ball& ball, c_score& score_1,
	c_brique briques[], int&is_service, int&n_briques) {
	//BUT	:d�tecter les collisions entres objets
	//ENTREE:la raquette, la balle, le score, le tableau de briques, 2 entiers
	//SORTIE:/

	//collision balle - raquette
	if (SDL_HasIntersection(ball.get_rect_p(), p_1.get_rect_p())) {

		collision_pad(p_1, ball, -1);
	}

	//collision balle - brique
	for (int n_i = 0; n_i < (LIGNES * COLONNES); n_i++)

		if (briques[n_i].get_actif() == true && SDL_HasIntersection(ball.get_rect_p(), briques[n_i].get_rect_p())) {

			collision_brique(briques[n_i], ball);
			n_briques--;
		}


	//rebondissement balle - bords
	ball.bounce();

	//d�limitation mouvements raquettes � l'�cran
	p_1.boundary();

	if (ball.get_rect().y + BALL_SIZE > HEIGHT) {
		score_1.sub_score();
		is_service = 1;
	}
}


void collision_pad(c_pad& pad, c_ball& ball, int dir) {
	//BUT	: gestion des collisions entre la balle et une raquette (angle et direction)
	//ENTREE: 1 joueur, la balle
	//SORTIE: /

	float demi_pad = pad.get_rect().w / 2;

	double in = (pad.get_rect().x + demi_pad) - (ball.get_rect().x + BALL_SIZE/2);
	double nor = in / (pad.get_rect().w / 2);
	double b = nor * (5 * PI / 12);

	ball.set_vel_y(dir * BALL_SPEED * cos(b));
	ball.set_vel_x(BALL_SPEED * -sin(b));
}


void collision_brique(c_brique& brique, c_ball& ball) {
	//BUT	:g�rer les collisions et rebonds de la balle avec les briques
	//ENTREE:le tableau de briques, la balle
	//SORTIE:/

	if (ball.get_rect().x >= brique.get_rect().x) {
		ball.set_vel_x(-ball.get_vel_x());
		ball.set_rect_pos_x(ball.get_rect().x - 20);
	}
	if (ball.get_rect().x <= brique.get_rect().x) {
		ball.set_vel_x(-ball.get_vel_x());
		ball.set_rect_pos_x(ball.get_rect().x + 20);
	}
	if (ball.get_rect().y <= brique.get_rect().y) {
		ball.set_vel_y(-ball.get_vel_y());
		ball.set_rect_pos_y(ball.get_rect().y - 20);
	}
	if (ball.get_rect().y >= brique.get_rect().y) {
		ball.set_vel_y(-ball.get_vel_y());
		ball.set_rect_pos_y(ball.get_rect().y + 20);
	}

	brique.set_actif(false);
}