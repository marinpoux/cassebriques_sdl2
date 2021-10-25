#include "define.h"

#include "c_rect.h"

//METHODES
inline void c_rect::affiche()const {
	//BUT	: afficher les info de l'objet
	//ENTREE:
	//SORTIE:
	std::cout << "RECT dim: " << rect.h << "x" << rect.w
		<< " pos: (" << rect.x << "," << rect.y
		<< ") init pos: (" << coord_i.x << "," << coord_i.y
		<< ")" << coul.r << std::endl;
}

inline void c_rect::fill_rect(Window_Renderer& w_r)const {
//BUT	:remplir le rectangle
//ENTREE:l'objet fenetre+rendu
//SORTIE:/
	SDL_SetRenderDrawColor(w_r.p_renderer, coul.r, coul.g, coul.b, coul.a);
	SDL_RenderFillRect(w_r.p_renderer, &rect);
}

inline void c_rect::render_text(Window_Renderer& w_r)const {
//BUT	:afficher la texture
//ENTREE:l'objet fenetre+rendu
//SORTIE:/
	SDL_RenderCopy(w_r.p_renderer, p_text, NULL, &rect);
}


//ACCESSEURS
//rectangle
inline SDL_Rect c_rect::get_rect()const {
	//BUT	:acceder au rectange
	//ENTREE:/
	//SORTIE:l'objet SDL_rect

	return rect;
}

inline SDL_Rect* c_rect::get_rect_p() {
	//BUT	:accéder au pointeur du rectangle
	//ENTREE:/
	//SORTIE:un pointeur *SDL_Rect

	return &rect;
}

//texture
inline SDL_Texture* c_rect::get_text()const {
	//BUT	:accéder à la texture
	//ENTREE:/
	//SORTIE:*SDL_Texture

	return p_text;
}

//couleur
inline SDL_Color c_rect::get_color()const {
	//BUT	:accéder à la couleur
	//ENTREE:/
	//SORTIE:SDL_Color

	return coul;
}

//position initiale
inline c_rect::Coord c_rect::get_coord_i()const {
	//BUT	:accéder aux coordonnées initiales
	//ENTREE:/
	//SORTIE:un objet Coord
	return coord_i;
}

inline float c_rect::get_x_i()const {
	//BUT	:accéder au x initial
	//ENTREE:/
	//SORTIE:un réel

	return coord_i.x;
}

inline float c_rect::get_y_i()const {
	//BUT	:accéder au y initial
	//ENTREE:/
	//SORTIE:un réel

	return coord_i.y;
}


//MUTATEURS
//rectangle
inline void c_rect::set_rect_sdl(SDL_Rect rect) {
	//BUT	:modifier le rectangle
	//ENTREE:SDL_Rect
	//SORTIE:/

	this->rect = rect;
}

inline void c_rect::set_rect(float h, float w, float x, float y) {
	//BUT	:modifier le rcetangle
	//ENTREE:4 réels
	//SORTIE:/

	rect.h = h;
	rect.w = w;
	rect.x = x;
	rect.y = y;
}

inline void c_rect::set_rect_dim(float h, float w) {
	//BUT	:modifier les dimensions du rectangle
	//ENTREE:2 réels
	//SORTIE:/

	rect.h = h;
	rect.w = w;
}

inline void c_rect::set_rect_pos(float x, float y) {
	//BUT	:modifier la position du rectangle
	//ENTREE:2 réels
	//SORTIE:/

	rect.x = x;
	rect.y = y;
}

inline void c_rect::set_rect_pos_x(float x) {
	//BUT	:modifier la position x du rectangle
	//ENTREE:1 réel
	//SORTIE:/

	rect.x = x;
}

inline void c_rect::set_rect_pos_y(float y) {
	//BUT	:modifier la position y du rectangle
	//ENTREE:1 rée/l
	//SORTIE:

	rect.y = y;
}

//texture
inline void c_rect::set_text_sdl(SDL_Texture* p_text) {
	//BUT	:modifier la texture
	//ENTREE:*SDL_texture
	//SORTIE:/

	this->p_text = p_text;
}

inline void c_rect::set_text(const char* img, SDL_Renderer *p_r) {
	//BUT	:modifier la texture
	//ENTREE:le chemin relatif depuis la solution, le renderer
	//SORTIE:/

	SDL_Surface* p_img = IMG_Load(img);

	this->p_text = SDL_CreateTextureFromSurface(p_r, p_img);

	SDL_FreeSurface(p_img);
}

//couleur
inline void c_rect::set_coul_sdl(SDL_Color coul) {
	//BUT	:modifier la couleur
	//ENTREE:SDL_Color
	//SORTIE:/

	this->coul = coul;
}

inline void c_rect::set_coul(int r, int v, int b, int a) {
	//BUT	:modifier la couler
	//ENTREE:4 entiers
	//SORTIE:/
	SDL_Color c_temp;

	c_temp.a = a;
	c_temp.r = r;
	c_temp.g = v;
	c_temp.b = b;

	coul = c_temp;
}

inline void c_rect::set_alpha(int a) {
	//BUT	:modifier la transparence de la couleu1 entierr
	//ENTREE:/
	//SORTIE:

	coul.a = a;
}

//position initiale
inline void c_rect::set_coord_i_coord(Coord coord_i) {
	//BUT	:modifier la position initiale
	//ENTREE:un objet Coord
	//SORTIE:/

	this->coord_i = coord_i;
}

inline void c_rect::set_coord_i(float x_i, float y_i) {
	//BUT	:modifier la position initiale
	//ENTREE:2 réels
	//SORTIE:/

	coord_i.x = x_i;
	coord_i.y = y_i;
}

inline void c_rect::set_x_i(float x_i) {
	//BUT	:modifier la position x initiale
	//ENTREE:1 réel
	//SORTIE:/

	coord_i.x = x_i;
}


inline void c_rect::set_y_i(float y_i) {
	//BUT	:modifier la position y initiale
	//ENTREE:1 réel
	//SORTIE:/

	coord_i.y = y_i;
}
