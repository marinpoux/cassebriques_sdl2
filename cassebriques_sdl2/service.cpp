#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"


void service(int& is_service, c_pad& p_1, c_ball& ball) {
	//BUT	:mettre en place le service
	//ENTREE:2 booleens, les 2 raquettes, la balle
	//SORTIE:/

	if (is_service == 1) {
		ball.set_vel_x(0);
		ball.set_vel_y(0);
	}
	else if (is_service == 2) {
		ball.set_vel_y(-BALL_SPEED);
		is_service = 0;
	}
	
	ball.set_rect_pos_y(ball.get_y_i());
	ball.set_rect_pos_x(p_1.get_rect().x + (p_1.get_rect().w / 2) - BALL_SIZE/2);
}