#ifndef _CAR_H
#define _CAR_H

#include<iostream>
#include<SDL.h>

class Car{
    public:
    Car(){};
    ~Car(){};
    virtual void move(char lightstatus, SDL_Rect rect);
    virtual void CarBuild(SDL_Renderer *renderer, int appwidth);
    int CarDestroy(int appwidth);
    void CarShow(SDL_Renderer *renderer);
    SDL_Rect GetRect(){return this->cadre;};
    
    protected:
    char direction; // N = north S = south E = est W = west
    char status ='S'; // L turn left R turn right S go streight
    int angle;
    int positionX;
    int positionY;
    SDL_Surface *car;
    SDL_Texture *texture;
    SDL_Rect cadre;
    char carsimages[6][20]={"car.bmp","car2.bmp","car6.bmp","car4.bmp","car5.bmp","car1.bmp"};
};

void Car :: CarBuild(SDL_Renderer *renderer, int appwidth){
    cout<<"Nothing set yet as a car"<<endl;
};

void Car :: move(char lightstatus, SDL_Rect rect){
    cout<<"No movement set Yet"<<endl;
};

void Car :: CarShow(SDL_Renderer *renderer){
    this->cadre.x = this->positionX;
    this->cadre.y = this->positionY;
    SDL_RenderCopyEx(renderer,this->texture, NULL ,&this->cadre,this->angle,NULL,SDL_FLIP_NONE);
};

int Car :: CarDestroy(int appwidth){
    if(this->positionX > appwidth + 100 || this->positionX < appwidth-700){
        SDL_DestroyTexture(this->texture);
        return 1;
    };
    if(this->positionY > 700 || this->positionY < -100){
        SDL_DestroyTexture(this->texture);
        return 1;
    };
};
#endif