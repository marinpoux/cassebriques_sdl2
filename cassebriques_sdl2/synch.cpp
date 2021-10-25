#include "define.h"

#include "c_rect.h"
#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"


void synch(FPS_Manager&fps) {
	//BUT	:afficher des fps constants
	//ENTREE:le gestionnaire de fps
	//SORTIE:/
	fps.n_frame_count++;

	int n_timer_fps = SDL_GetTicks() - fps.n_last_frame;

	if (n_timer_fps < (1000 / 60))
		SDL_Delay((1000 / 60) - n_timer_fps);
}