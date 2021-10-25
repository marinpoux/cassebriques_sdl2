#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"

void event_handler(bool&is_running, int&is_service, c_pad& p_1,c_ball&ball,
	c_score& score_1, FPS_Manager& fps) {
	//BUT	:gestion des évenements (collisions, entrées clavier, service)
	//ENTREE:3 booleens, les deux raquettes, la balle, les scores, les fps
	//SORTIE:/

	if (score_1.get_score() <= 0)
		reset(score_1, is_service, p_1);

	if (is_service == 1 || is_service ==2) {
		service(is_service, p_1, ball);
	}

	//entrées clavier
	input(is_running, p_1, is_service);

	//collisions
	collisions(p_1, ball, score_1, is_service);

	//compteur fps
	fps_counter(fps);
}
