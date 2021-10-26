#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"


//CONSTANTES
//dimensions ecran
#define WIDTH 1000
#define HEIGHT 680

//texte
#define FONT_SIZE 32
#define POLICE "../Simply Rounded.ttf"

//score
#define LIVES 3

//raquette
#define PAD_SPEED 9
#define PAD_HEIGHT 12
#define PAD_IMG "../img/barre.png"

//balle
#define BALL_SPEED 16
#define BALL_SIZE 16
#define BALL_IMG "../img/balle.png"

//briques
#define LIGNES 5
#define COLONNES 6
#define SPC 10

//autres
#define PI 3.14159265358979323846


//CLASSES
class c_rect;
class c_pad;
class c_ball;
class c_score;
class c_brique;

//enum class Controles { up = 1, down, left, right, idle = 0 };


//STRUCTURES
//fenetre et rendu
typedef struct Window_Renderer {
	SDL_Renderer* p_renderer;
	SDL_Window* p_window;
	SDL_Color couleur;
}Window_Renderer;

//controles
typedef enum Controles {
	up = 1,
	down,
	left,
	right,
	idle = 0
}Controles;


typedef struct FPS_Manager {
	int n_frame_count, n_last_frame, last_time;
	//static int last_time;
}FPS_Manager;



//PROTOTYPE
//initialisation
void init(Window_Renderer& w_r, c_score& score_1,
	c_pad& p_1, c_ball& ball, c_brique briques[],
	FPS_Manager& fps, int&is_service, bool& is_running, int&n_briques);

void init_SDL(Window_Renderer& w_r);
void init_pads(Window_Renderer& w_r, c_pad&p_1);
void init_ball(Window_Renderer& w_r, c_ball& ball, c_pad&pad_1);
void init_score(Window_Renderer& w_r, c_score& score_1);
void init_briques(c_brique briques[]);

//event handler
void event_handler(bool& is_running, int& is_service,
	c_pad& p_1, c_ball& ball, c_score& score_1, c_brique briques[],
	int&n_briques, FPS_Manager& fps);

void reset(c_score& score, int& is_service, c_pad& pad, int&n_briques, c_brique briques[]);

void service(int& is_service, c_pad& p_1, c_ball& ball);

void input(bool& is_running, c_pad& p_1, int&is_service);

void collisions(c_pad& p_1, c_ball& ball, c_score& score_1, 
	c_brique briques[], int& is_service, int& n_briques);
void collision_pad(c_pad& pad, c_ball& ball, int dir);
void collision_brique(c_brique& brique, c_ball& ball);

void fps_counter(FPS_Manager& fps);


//update
void update(Window_Renderer& w_r, c_score& score_1, 
	c_ball& ball, c_pad& p_1, int&is_service);

void deplace_pad(c_pad& pad);


//render
void render(Window_Renderer& w_r, FPS_Manager&fps, c_score& score_1,
	c_ball& ball, c_pad& p_1, c_brique briques[]);

void synch(FPS_Manager&fps);


//fermeture
void quit(Window_Renderer& w_r, c_score score_1, c_brique briques[]);

//autres


	//BUT	:
	//ENTREE:
	//SORTIE: