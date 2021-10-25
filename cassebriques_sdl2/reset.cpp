#include "define.h"

#include "c_rect.h"
#include "c_rect.cpp"

#include "c_ball.h"
#include "c_pad.h"
#include "c_score.h"


void reset(c_score& score, int&is_service, c_pad&pad) {

	score.set_score(LIVES);

	pad.set_rect_pos(pad.get_x_i(), pad.get_y_i());

	is_service = 1;
}