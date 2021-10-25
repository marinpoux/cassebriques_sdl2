#pragma once

#include "define.h"


class c_rect {
public:
	typedef struct Coord {
		float x, y;
	}Coord;

	//CONSTRUCTEUR
	c_rect() {
		rect = { 0,0,0,0 };

		p_text = nullptr;

		coul = { 0,0,0,0 };

		coord_i = { 0,0 };
	}

	//CONSTRUCTEUR DE COPIE
	c_rect(c_rect& r) {
		this->rect = r.rect;
		this->p_text = r.p_text;
		this->coul = r.coul;
		this->coord_i = r.coord_i;
	}

	//DESTRUCTEUR
	~c_rect() {
		if (this->p_text)
			SDL_DestroyTexture(this->p_text);

		std::cout << "destructeur c_rect" << std::endl;
	}


	//METHODES
	void affiche()const;

	void fill_rect(Window_Renderer&w_r)const;
	void render_text(Window_Renderer&w_r)const;


	//ACCESSEURS
	//rectangle
	SDL_Rect get_rect()const;
	SDL_Rect* get_rect_p();
	//float get_rect_h()const;
	//float get_rect_w()const;
	//float get_rect_x()const;
	//float get_rect_y()const;

	//texture
	SDL_Texture* get_text()const;

	//couleur
	SDL_Color get_color()const;
	//int get_alpha()const;

	//position initiale
	Coord get_coord_i()const;
	float get_x_i()const;
	float get_y_i()const;


	//MUTATEURS
	//rectangle
	void set_rect_sdl(SDL_Rect rect);
	void set_rect(float h, float w, float x, float y);
	void set_rect_dim(float h, float w);
	void set_rect_pos(float x, float y);
	void set_rect_pos_x(float x);
	void set_rect_pos_y(float y);

	//texture
	void set_text_sdl(SDL_Texture *p_text);
	void set_text(const char* img, SDL_Renderer *p_r);

	//couleur
	void set_coul_sdl(SDL_Color coul);
	void set_coul(int r, int v, int b, int a);
	void set_alpha(int a);

	//position initiale
	void set_coord_i_coord(Coord coord_i);
	void set_coord_i(float x_i, float y_i);
	void set_x_i(float x_i);
	void set_y_i(float y_i);

	
	//OPERATEURS
	//opérateur de sortie
	friend std::ostream& operator<<(std::ostream &os, const c_rect& r) {
		os << "RECT dim: " << r.rect.h << "x" << r.rect.w
			<< " pos: (" << r.rect.x << "," << r.rect.y
			<< ") init pos: (" << r.coord_i.x << "," << r.coord_i.y
			<< ")" << std::endl;

		return os;
	}
	 
	//opérateur =
	c_rect operator=(const c_rect& r) {
		rect = r.rect;

		p_text = r.p_text;
		coul = r.coul;

		coord_i = r.coord_i;

		return *this;
	}

private:
	SDL_Rect rect;
	//SDL_Surface *p_img;	--> utiliser un objet temp puis SDL_FreeSurface()
	SDL_Texture* p_text;
	SDL_Color coul;

	Coord coord_i;		//positions initiales --> valeurs calculées à l'initialisation
};
