#pragma once

#include "define.h"
#include "c_rect.h"

class c_score : public c_rect {
private:
	TTF_Font* p_font;			//police
	SDL_Color font_coul;		//couleur du texte

	int n_score;		//score du joueur
	//Coord pos;			//position du score

	std::string t_score;		//texte affiché

public:
	//constructeur
	c_score() {
		p_font = nullptr;
		font_coul = { 0,0,0,0 };

		n_score = 0;
		
		//pos = { 0,0 };

		t_score = " ";
	}

	//destructeur
	~c_score() {
		/*if (p_font != nullptr)
			TTF_CloseFont(p_font);*/

		std::cout << "destructeur c_score" << std::endl;
	}


	//ACCESSEURS
	TTF_Font* get_font()const {
		return p_font;
	}

	SDL_Color get_font_coul()const {
		return font_coul;
	}

	int get_score()const {
		return n_score;
	}

	std::string get_score_txt() {
		return t_score;
	}


	//MUTATEURS
	//police
	void set_font_ttf(TTF_Font* p_font) {
		//BUT	:modifier la police de texte
		//ENTREE:TTF_Font*
		//SORTIE:/
		this->p_font = p_font;
	}

	void set_font(const char* police, int taille) {
		//BUT	:modofier la police de texte
		//ENTREE:le chemin depuis la solution, un entier
		//SORTIE:/
		this->p_font = TTF_OpenFont(police, taille);
	}

	void set_font_coul_sdl(SDL_Color coul) {
		//BUT	:modifier la couleur du texte
		//ENTREE:SDL_Color
		//SORTIE:/
		font_coul = coul;
	}

	void set_font_coul(int r, int v, int b, int a) {
		//BUT	:mofifier la couleur du texte
		//ENTREE:4 entiers
		//SORTIE:/
		SDL_Color c_temp;

		c_temp.a = a;
		c_temp.r = r;
		c_temp.g = v;
		c_temp.b = b;

		font_coul = c_temp;
	}

	//valeur score
	void set_score(int score) {
		//BUT	:modifier la valeur numérique du score
		//ENTREE:un entier
		//SORTIE:/
		n_score = score;
	}
	
	void add_score() {
		n_score++;
	}

	void sub_score() {
		n_score--;
	}

	//texte score
	void set_txt(std::string txt) {
		//BUT	:modifier le texte
		//ENTREE:une chaine de caracteres
		//SORTIE:/
		t_score = txt;
	}

	void set_txt_score() {
		//BUT	:attribuer à t_score, le score n_score
		//ENTREE:/
		//SORTIE:/
		t_score = "Life : " + std::to_string(n_score);
	}


	//OPERATEURS
	c_score operator=(c_score& s) {
		//c_rect
		set_rect_sdl(s.get_rect());

		set_text_sdl(s.get_text());
		set_coul_sdl(s.get_color());

		set_coord_i_coord(s.get_coord_i());

		//c_score
		p_font = s.p_font;
		font_coul = s.font_coul;

		n_score = s.n_score;

		//pos = s.pos;

		t_score = s.t_score;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, c_score& s) {
		os << "RECT dim: " << s.get_rect().h << "x" << s.get_rect().w
			<< " pos: (" << s.get_rect().x << "," << s.get_rect().y
			<< ") init pos: (" << s.get_coord_i().x << "," << s.get_coord_i().y
			<< ")" << std::endl;

		return os;
	}


	//AUTRES
	void set_text_dim(Window_Renderer& w_r) {
		//BUT	:créer une texture à partir du texte
		//ENTREE:l'objet fenetre+renderer
		//SORTIE:/
		SDL_Surface* p_surface;

		const char* t = t_score.c_str();

		p_surface = TTF_RenderText_Solid(p_font, t, font_coul);

		set_text_sdl(SDL_CreateTextureFromSurface(w_r.p_renderer, p_surface));

		set_rect_dim(p_surface->h, p_surface->w);

		SDL_FreeSurface(p_surface);
		SDL_RenderCopy(w_r.p_renderer, get_text(), NULL, get_rect_p());
	}
};