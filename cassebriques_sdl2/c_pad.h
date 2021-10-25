#pragma once

#include "define.h"
#include "c_rect.h"

class c_pad : public c_rect {
private:
	Controles controles;

public:
	//constructeur
	c_pad() {
		controles = idle;
	}

	//constructeur de copies
	c_pad(c_pad& p) {
		this->controles = p.controles;
	}

	//destructeur
	~c_pad() {
		std::cout << "destructeur c_pad" << std::endl;
	}

	//ACCESSEURS
	Controles get_controles()const {
		return controles;
	}

	//MUTATEURS
	void set_controles(Controles controles) {
		this->controles = controles;
	}

	//OPERATEURS
	c_pad operator=(c_pad& p) {
		//c_rect
		set_rect_sdl(p.get_rect());

		set_text_sdl(p.get_text());
		set_coul_sdl(p.get_color());

		set_coord_i_coord(p.get_coord_i());

		//c_pad
		set_rect_sdl(p.get_rect());

		set_coord_i_coord(p.get_coord_i());

		controles = p.controles;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const c_pad& p) {
		os << "PAD dim: " << p.get_rect().h << "x" << p.get_rect().w
			<< " pos: (" << p.get_rect().x << "," << p.get_rect().y
			<< ") init pos: (" << p.get_x_i() << "," << p.get_y_i()
			<< ")" << std::endl;

		return os;
	}

	//autres
	void affiche() {
		//BUT	:afficher des info sur l'objet
		//ENTREE:/
		//SORTIE:/
		std::cout << "PAD dim: " << get_rect().h << "x" << get_rect().w
			<< " pos: (" << get_rect().x << "," << get_rect().y
			<< ") init pos: (" << get_x_i() << "," << get_y_i()
			<< ")" << std::endl;
	}

	void boundary() {
		//BUT	:limiter les déplacements de l'objet aux bords de l'écran
		//ENTREE:/
		//SORTIE:/
		if (get_rect().y < 0)
			set_rect_pos_y(0);
		
		if (get_rect().y + get_rect().h > HEIGHT)
			set_rect_pos_y(HEIGHT - get_rect().h);

		if (get_rect().x < 0)
			set_rect_pos_x(0);

		if (get_rect().x + get_rect().w > WIDTH)
			set_rect_pos_x(WIDTH - get_rect().w);
	}
};



