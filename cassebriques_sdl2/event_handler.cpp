#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"

void event_handler(bool&is_running, int&is_service, c_pad& p_1,c_ball&ball,
	c_score& score_1, c_brique briques[], int& n_briques, FPS_Manager& fps) {
	//BUT	:gestion des évenements (collisions, entrées clavier, service)
	//ENTREE:1 booleen, 2 entiers, la raquette, la balle, le score, le tableau de briques, les fps
	//SORTIE:/

	//si les vies sont épuisées ou qu'il n'y a plus de briques, on recommence
	if (score_1.get_score() <= 0 || n_briques == 0) {

		SDL_Delay(1000);
		reset(score_1, is_service, p_1, n_briques, briques);
	}

	//conditions du service
	if (is_service == 1 || is_service ==2) {
		service(is_service, p_1, ball);
	}

	//entrées clavier
	input(is_running, p_1, is_service);

	//collisions
	collisions(p_1, ball, score_1, briques, is_service, n_briques);

	//compteur fps
	fps_counter(fps);
}
