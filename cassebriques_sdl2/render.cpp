#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"
#include "c_brique.h"

void render(Window_Renderer& w_r, FPS_Manager&fps,
	c_score&score_1, c_ball& ball, c_pad& p_1, c_brique briques[]) {
	//BUT	:afficher le rendu
	//ENTREE:la fenetre, le renderer, les fps, le score, la raquette, la balle, le tableau de briques
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

	//briques
	for (int n_i = 0; n_i < (LIGNES * COLONNES); n_i++)
		if (briques[n_i].get_actif() == true)
			briques[n_i].fill_rect(w_r);

	//fps constants
	synch(fps);

	//rendu
	SDL_RenderPresent(w_r.p_renderer);
}