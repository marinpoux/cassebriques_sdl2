#pragma once

#include "define.h"
#include "c_rect.h"

class c_brique : public c_rect {

private:
	bool is_actif;		//devient false si touché

public:
	//constructeur
	c_brique() {
		is_actif = true;
	}

	//constructeur de copies
	c_brique(c_brique& b) {
		this->is_actif = b.is_actif;
	}

	//destruteur
	~c_brique() {
		std::cout << "destructeur c_brique" << std::endl;
	}

	//ACCESSEURS
	float get_actif()const {
		return is_actif;
	}

	//MUTATEURS
	void set_actif(bool is_actif) {
		this->is_actif = is_actif;
	}

	//OPERATEURS
	c_brique operator=(c_brique& b) {
		//c_rect
		set_rect_sdl(b.get_rect());

		set_text_sdl(b.get_text());
		set_coul_sdl(b.get_color());

		set_coord_i_coord(b.get_coord_i());

		//c_brique
		set_rect(b.get_rect().h, b.get_rect().w, b.get_rect().x, b.get_rect().y);

		set_x_i(b.get_x_i());
		set_y_i(b.get_y_i());

		is_actif = b.is_actif;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const c_brique& b) {
		os << "BRIQUE dim: " << b.get_rect().h << "x" << b.get_rect().w
			<< " pos: (" << b.get_rect().x << "," << b.get_rect().y
			<< ") init pos: (" << b.get_x_i() << "," << b.get_y_i()
			<< ") is actif: " << b.is_actif
			<< std::endl;

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
			<< ") is actif: " << get_actif()
			<< std::endl;
	}





};