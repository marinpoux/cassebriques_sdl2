#include "define.h"

#include "c_rect.h"
#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"


void fps_counter(FPS_Manager& fps) {
	//BUT	: compter les fps
	//ENTREE: l'objet FPS_Manager
	//SORTIE: /

	fps.n_last_frame = SDL_GetTicks();
	if (fps.n_last_frame >= (fps.last_time + 1000)) {
		fps.last_time = fps.n_last_frame;
		fps.n_frame_count = 0;
	}
}