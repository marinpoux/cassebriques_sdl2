#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"

void input(bool&is_running, c_pad&p_1, int&is_service) {
	//BUT	:lire les entrées au clavier
	//ENTREE:un booleen, les deux raquettes
	//SORTIE:/

	SDL_Event e;	//evenement

	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT)
			is_running = false;

	if (keystates[SDL_SCANCODE_ESCAPE])
		is_running = false;

	if (keystates[SDL_SCANCODE_SPACE] && (is_service == 1))
		is_service = 2;

	//controles joueur 1
	if (keystates[SDL_SCANCODE_LEFT])
		p_1.set_controles(left);
	else if (keystates[SDL_SCANCODE_RIGHT])
		p_1.set_controles(right);
	else
		p_1.set_controles(idle);
}