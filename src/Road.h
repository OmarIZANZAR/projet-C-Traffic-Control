#ifndef _ROAD_H
#define _ROAD_H

#include<SDL.h>
#include<iostream>
#include<string.h>

class Road{
    public:
    Road(){};
    ~Road(){ std::cout<<"road destroyed"<<std::endl; };
    void RoadBuild(SDL_Renderer *renderer, int appwidth);
    void RoadShow(SDL_Renderer *renderer);
    void RoadDestroy();

    private:
    char roadimage[150]= "images/road components/Xcrossroads.bmp";
    SDL_Surface *road;
    SDL_Texture *texture;
    SDL_Rect cadre;
};

void Road :: RoadBuild(SDL_Renderer *renderer, int appwidth){
    this->road =SDL_LoadBMP(this->roadimage);
    this->texture = SDL_CreateTextureFromSurface(renderer,this->road);
    SDL_FreeSurface(road);
    this->cadre.w = 600;
    this->cadre.h = 600;
    this->cadre.x = appwidth - this->cadre.w;
    this->cadre.y = 0;
    SDL_QueryTexture(this->texture,NULL,NULL,&this->cadre.w,&this->cadre.h);
};

void Road :: RoadShow(SDL_Renderer *renderer){
    SDL_RenderCopy(renderer,this->texture, NULL ,&this->cadre);
};

void Road :: RoadDestroy(){
    SDL_DestroyTexture(this->texture);
};
#endif
