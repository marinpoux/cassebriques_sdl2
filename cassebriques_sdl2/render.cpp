#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"

void render(Window_Renderer& w_r, FPS_Manager&fps,
	c_score&score_1, c_ball& ball, c_pad& p_1) {
	//BUT	:afficher le rendu
	//ENTREE:la fenetre, le renderer, les fps, les scores, les raquettes, la balle
	//SORTIE:/
	
	//fond
	SDL_SetRenderDrawColor(w_r.p_renderer, w_r.couleur.r, w_r.couleur.g, w_r.couleur.b, w_r.couleur.a);
	SDL_RenderClear(w_r.p_renderer);

	//raquettes
	p_1.render_text(w_r);

	//balle
	ball.render_text(w_r);

	//scores
	score_1.set_text_dim(w_r);

	//fps constants
	synch(fps);

	//rendu
	SDL_RenderPresent(w_r.p_renderer);
}