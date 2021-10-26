#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"
#include "c_brique.h"

void init(Window_Renderer& w_r, c_score& score_1, c_pad& p_1, c_ball& ball, c_brique briques[],
	FPS_Manager& fps, int& is_service, bool& is_running, int&n_briques) {
	//BUT	: initialiser toutes les instances
	//ENTREE: la fenetre, le rendu, le tableau des scores, la raquette, la balle, le tableau de briques,
	//			le gestionnaire des fps, 1 booleen 2 entiers
	//SORTIE: /

	w_r.couleur = { 200,100,100,255 };

	init_SDL(w_r);

	init_score(w_r, score_1);

	init_pads(w_r, p_1);

	init_ball(w_r, ball, p_1);

	init_briques(briques);

	fps = { 0,0,0 };
	//fps.last_time = 0;

	is_service = 1;
	n_briques = LIGNES * COLONNES;
	is_running = true;
}


void init_SDL(Window_Renderer& w_r) {
	//BUT	: initialiser la sdl
	//ENTREE: la fenetre et le renderer
	//SORTIE: /
 
	//erreurs
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cout << "Failed at SDL_Init()" << std::endl;

	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &w_r.p_window, &w_r.p_renderer) < 0)
		std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;

	if (IMG_Init(IMG_INIT_PNG) < 0)
		std::cout << "Failed at IMG_Init()" << std::endl;

	//titrer la fenetre
	SDL_SetWindowTitle(w_r.p_window, "CASSE-BRIQUES");

	//cacher le curseur de la souris
	SDL_ShowCursor(0);

	//initialisation de la bibliothèque ttf
	if (TTF_Init() < 0)
		std::cout << "Failed at TTF_Init()" << std::endl;
}


void init_score(Window_Renderer& w_r, c_score& score_1) {
	//BUT	:	initialiser les scores
	//ENTREE:	le tableau de score
	//SORTIE:	/
 
	//SCORE_1
	//police
	score_1.set_font(POLICE, FONT_SIZE);
	score_1.set_font_coul(255,255,255,255);

	if (score_1.get_font() == nullptr) {
		fprintf(stderr, "error: p_font not found\n");
		exit(EXIT_FAILURE);
	}

	//score
	score_1.set_score(3);

	//texture et dimensions
	score_1.set_text_dim(w_r);

	//position
	score_1.set_rect_pos(BALL_SIZE, HEIGHT - PAD_HEIGHT*3);
}


void init_pads(Window_Renderer& w_r, c_pad& p_1) {
	//BUT	: initialiser la raquette
	//ENTREE: la fenetre, le renderer, le joueur
	//SORTIE: /

	//P1
	//dimensions
	p_1.set_rect_dim(PAD_HEIGHT, WIDTH/4);

	//sprite
	p_1.set_text(PAD_IMG, w_r.p_renderer);

	if (p_1.get_text() == nullptr) {
		fprintf(stderr, "error: p_1.p_text not found\n");
		exit(EXIT_FAILURE);
	}

	//determination position initiale
	p_1.set_x_i(WIDTH / 2 - p_1.get_rect().w / 2);
	p_1.set_y_i(HEIGHT - 3*PAD_HEIGHT);

	p_1.set_rect_pos(p_1.get_x_i(), p_1.get_y_i());
}


void init_ball(Window_Renderer& w_r, c_ball& ball, c_pad& p_1) {
	//BUT	: initialiser la balle
	//ENTREE: la fenetre, le renderer, balle, la raquette
	//SORTIE: /

	//dimensions
	ball.set_rect_dim(BALL_SIZE, BALL_SIZE);

	//sprite
	ball.set_text(BALL_IMG, w_r.p_renderer);

	if (ball.get_text() == nullptr) {
		fprintf(stderr, "error: ball.p_text not found\n");
		exit(EXIT_FAILURE);
	}

	//position y initiale
	ball.set_y_i(p_1.get_y_i() -  2 * BALL_SIZE);

	//velocité initialisée à la construction
}


void init_briques(c_brique briques[]) {
	//BUT	:initialiser le tableau de briques
	//ENTREE:tableau de briques
	//SORTIE:/

	int hauteur = 20;
	int largeur = (WIDTH - (SPC * COLONNES)) / COLONNES;

	for (int n_i = 0; n_i < (LIGNES * COLONNES); n_i++) {

		briques[n_i].set_rect_dim(hauteur, largeur);

		briques[n_i].set_rect_pos_x((((n_i % LIGNES) + 1) * SPC) + ((n_i % COLONNES) * largeur) - (SPC / 2));
		briques[n_i].set_rect_pos_y(hauteur * 3 + (((n_i % LIGNES) + 1) * SPC)
			+ ((n_i % LIGNES) * hauteur) - (SPC / 2));

		briques[n_i].set_coul(255, 255, 255, 255);

		briques[n_i].set_actif(true);
	}
}