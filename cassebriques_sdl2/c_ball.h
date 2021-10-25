#pragma once

#include "define.h"
#include "c_rect.h"

class c_ball : public c_rect {
private: 
	float f_vel_x, f_vel_y;		//vélocité de la balle sur x et y

public:
	//constructeur
	c_ball() {
		f_vel_x = 0;
		f_vel_y = 0;
	}

	//constructeur de copies
	c_ball(c_ball& b) {
		this->f_vel_x = b.f_vel_x;
		this->f_vel_y = b.f_vel_y;
	}

	//destruteur
	~c_ball() {
		std::cout << "destructeur c_ball" << std::endl;
	}

	//ACCESSEURS
	float get_vel_x()const {
		return f_vel_x;
	}

	float get_vel_y()const {
		return f_vel_y;
	}

	//MUTATEURS
	void set_vel_x(float f_vel_x) {
		this->f_vel_x = f_vel_x;
	}

	void set_vel_y(float f_vel_y) {
		this->f_vel_y = f_vel_y;
	}

	//OPERATEURS
	c_ball operator=(c_ball& b) {
		//c_rect
		set_rect_sdl(b.get_rect());

		set_text_sdl(b.get_text());
		set_coul_sdl(b.get_color());

		set_coord_i_coord(b.get_coord_i());

		//c_ball
		set_rect(b.get_rect().h, b.get_rect().w, b.get_rect().x, b.get_rect().y);

		set_x_i(b.get_x_i());
		set_y_i(b.get_y_i());

		f_vel_x = b.f_vel_x;
		f_vel_y = b.f_vel_y;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const c_ball& b) {
		os << "BALL dim: " << b.get_rect().h << "x" << b.get_rect().w
			<< " pos: (" << b.get_rect().x << "," << b.get_rect().y
			<< ") init pos: (" << b.get_x_i() << "," << b.get_y_i()
			<< ") vel x: " << b.f_vel_x << " vel y: " << b.f_vel_y
			<< ")" << std::endl;

		return os;
	}

	//autres
	void affiche() {
		//BUT	:afficher des info sur l'objet
		//ENTREE:/
		//SORTIE:/
		std::cout << "BALL dim: " << get_rect().h << "x" << get_rect().w
			<< " pos: (" << get_rect().x << "," << get_rect().y
			<< ") init pos: (" << get_x_i() << "," << get_y_i()
			<< ") vel x: " << f_vel_x << " vel y: " << f_vel_y
			<< std::endl;
	}

	void deplace_ball() {
		//BUT	:faire se déplacer la balle
		//ENTREE:/
		//SORTIE:/
		set_rect_pos(get_rect().x + f_vel_x, get_rect().y + f_vel_y);
	}

	void bounce() {
		//BUT	:faire rebondir la balle sur les bords de l'écran
		//ENTREE:/
		//SORTIE:/
		if (get_rect().y<0 || get_rect().y + BALL_SIZE > HEIGHT)
			set_vel_y(- get_vel_y());

		if (get_rect().x<0 || get_rect().x + BALL_SIZE > WIDTH)
			set_vel_x(-get_vel_x());
	}
};