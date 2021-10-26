#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"
#include "c_brique.h"

void quit(Window_Renderer& w_r, c_score score_1, c_brique briques[]) {
	//BUT	:libérer la mémoire
	//ENTREE:la fenetre, le renderer, les scores, le tableau de briques
	//SORTIE:

	//pointeurs dans classes gérés par destructeurs de classes

	/*if (briques)
		delete(briques);*/

	if (w_r.p_renderer)
		SDL_DestroyRenderer(w_r.p_renderer);

	if (w_r.p_window)
		SDL_DestroyWindow(w_r.p_window);

	if (score_1.get_font())
		TTF_CloseFont(score_1.get_font());

	SDL_Quit();
}
