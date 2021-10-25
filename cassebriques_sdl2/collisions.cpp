#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"


void collisions(c_pad& p_1, c_ball& ball, c_score& score_1, c_rect& brique,
	int&is_service) {
	//BUT	:détecter les collisions entres objets
	//ENTREE:la raquette, la balle, le score, un booleen
	//SORTIE:/

	//collision balle - raquette
	if (SDL_HasIntersection(ball.get_rect_p(), p_1.get_rect_p())) {

		collision_pad(p_1, ball, -1);
	}

	//collisions balle - brique
	bool reset_briques = true;
	for (int n_i = 0; n_i < (LIGNES * COLONNES); n_i++) {
		set_briques(brique, n_i);
		collision_brique(brique, ball, n_i);

		if (briques[n_i])
			reset_briques = false;
	}
	if (reset_briques)
		reset(score_1, is_service, p_1);

	//rebondissement balle - bords
	ball.bounce();

	//délimitation mouvements raquettes à l'écran
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


void collision_brique(c_rect& brique, c_ball& ball, int n_i) {

	if (SDL_HasIntersection(ball.get_rect_p(), brique.get_rect_p()) && briques[n_i]) {

		briques[n_i] = false;

		if (ball.get_rect().x >= brique.get_rect().x) {
			ball.set_vel_x(-ball.get_vel_x());
			ball.set_rect_pos_x(ball.get_rect().x - 20);
		}
		if (ball.get_rect().x <= brique.get_rect().x) {
			ball.set_vel_x(-ball.get_vel_x());
			ball.set_rect_pos_x(ball.get_rect().x + 20);
		}
		if (ball.get_rect().y >= brique.get_rect().y) {
			ball.set_vel_y(-ball.get_vel_y());
			ball.set_rect_pos_y(ball.get_rect().y - 20);
		}
		if (ball.get_rect().y >= brique.get_rect().y) {
			ball.set_vel_y(-ball.get_vel_y());
			ball.set_rect_pos_y(ball.get_rect().y + 20);
		}
	}
}