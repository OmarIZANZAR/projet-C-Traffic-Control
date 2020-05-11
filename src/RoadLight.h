#ifndef _ROADLIGHT_H
#define _ROADLIGHT_H

#include<iostream>
#include<SDL.h>
#include<string.h>

class RoadLight{
    public:
    RoadLight(char direction);
    ~RoadLight(){std::cout<<"road light: "<<this->direction<<" destroyed"<<std::endl;};
    void LightBuild(SDL_Renderer *renderer,int appwidth);
    void LightShow(SDL_Renderer *renderer);
    void LightDestroy();
    void lightGreen();
    void lightRed();
    void lightYellow();
    char LightStatus();

    private:
    char direction; // N = north S = south E = est W = west
    char status = 'A'; //R = red Y = yellow G = green A = all
    int angle;
    SDL_Surface *roadlight;
    SDL_Texture *texture;
    SDL_Rect cadre;
    char lightimage[4][15] = {"RYG.bmp","red.bmp","yellow.bmp","green.bmp"};
};

RoadLight::RoadLight(char direction){
    this->direction = direction;
};

void RoadLight :: LightBuild(SDL_Renderer *renderer,int appwidth){
    char path[150]="images/Road lights/";
    strcat(path,this->lightimage[0]);
    this->roadlight = SDL_LoadBMP(path);
    this->texture = SDL_CreateTextureFromSurface(renderer,this->roadlight);
    SDL_FreeSurface(roadlight);
    this->cadre.w = 20;
    this->cadre.h = 50;
    switch(this->direction){
        case 'S':
        this->angle = 0;this->cadre.x = appwidth-240;this->cadre.y = 360;break;
        case 'N':
        this->angle = 0;this->cadre.x = appwidth-380;this->cadre.y = 190;break;
        case 'E':
        this->angle = -90;this->cadre.x = appwidth-225;this->cadre.y = 205;break;
        case 'W':
        this->angle = 90;this->cadre.x = appwidth-395;this->cadre.y = 345;break;
    }
    SDL_QueryTexture(this->texture,NULL,NULL,&this->cadre.w,&this->cadre.h);
};

void RoadLight :: LightShow(SDL_Renderer *renderer){
    char path[150]="images/Road lights/";
    switch(this->status){
        case 'R':strcat(path,this->lightimage[1]);break;
        case 'Y':strcat(path,this->lightimage[2]);break;
        case 'G':strcat(path,this->lightimage[3]);break;
        default:strcat(path,this->lightimage[0]);break;
    }
    this->roadlight = SDL_LoadBMP(path);
    this->texture = SDL_CreateTextureFromSurface(renderer,this->roadlight);
    SDL_FreeSurface(roadlight);
    SDL_RenderCopyEx(renderer,this->texture, NULL ,&this->cadre,this->angle,NULL,SDL_FLIP_NONE);
};

void RoadLight :: LightDestroy(){ SDL_DestroyTexture(this->texture); };

//LIGHT COLOR CONTROL:
void RoadLight :: lightGreen(){ this->status = 'G'; };
void RoadLight :: lightRed(){ this->status = 'R'; };
void RoadLight :: lightYellow(){ this->status = 'Y'; };

//CONTROLLING LIGHT:
char RoadLight :: LightStatus(){return this->status;};

#endif
