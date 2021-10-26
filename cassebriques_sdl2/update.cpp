#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"

void update(Window_Renderer& w_r, c_score& score_1, c_ball& ball, c_pad& p_1, int&is_service) {
	//BUT	:mettre à jour le jeu
	//ENTREE:la fenetre, le rendu, le score, la balle, la raquette, un entier
	//SORTIE:/

	//màj texte score en fonction de valeur du score
	score_1.set_txt_score();

	//déplacer la balle
	if(is_service == 0)
		ball.deplace_ball();

	//màj positions raquettes
	deplace_pad(p_1);
}


void deplace_pad(c_pad& pad) {
	//BUT	:déplacement d'une raquette en fonction des entrées enregistrées
	//ENTREE:
	//SORTIE:
	switch (pad.get_controles()) {
	case left:
		pad.set_rect_pos_x(pad.get_rect().x - PAD_SPEED);
		break;
	case right:
		pad.set_rect_pos_x(pad.get_rect().x + PAD_SPEED);
		break;
	case idle:
		pad.set_rect_pos_x(pad.get_rect().x);
		break;
	default:
		pad.set_rect_pos_x(pad.get_rect().x);
		break;
	}
}