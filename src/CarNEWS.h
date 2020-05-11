#ifndef _CARNEWS_H
#define _CARNEWS_H

#include<ctime>
#include"Car.h"

int slw = 2;

//DIRECTION NORTH CARS:
class CarN : public Car{
    public:
    CarN();
    ~CarN(){};
    void move(char lightstatus, SDL_Rect rect);
    void CarBuild(SDL_Renderer *renderer, int appwidth);

};
CarN :: CarN() : Car() {
    this->direction = 'N';
};
void CarN :: CarBuild(SDL_Renderer *renderer , int appwidth){
    char path[150]="cars images/cars N/";
    srand(time(NULL)+68000785000);
    int i = rand()%5;
    strcat(path,this->carsimages[i]);
    this->car = SDL_LoadBMP(path);
    this->texture = SDL_CreateTextureFromSurface(renderer,this->car);
    SDL_FreeSurface(car);
    char carStatus[4]={'S','R','L'};
    int j = rand()%2;
    this->status = carStatus[j];
    this->cadre.w = 25;
    this->cadre.h = 70;
    this->angle = 0;
    this->positionX = appwidth - 340;
    this->positionY = -70;
    SDL_QueryTexture(this->texture,NULL,NULL,&this->cadre.w,&this->cadre.h);
};
void CarN :: move(char lightstatus, SDL_Rect rect){
    if( !(lightstatus == 'R' && this->positionY == 166) ){
        if(!SDL_HasIntersection(&this->cadre , &rect )){
            switch(this->status){
                case 'R':
                if(this->positionY < 250){this->positionY++;SDL_Delay(slw);};
                if(this->positionY == 249 )this->angle = 90;
                if(this->angle == 90){this->positionX--;SDL_Delay(slw);};
                break;
                case 'L':
                if(this->positionY < 300){this->positionY++;SDL_Delay(slw);};
                if(this->positionY == 299 )this->angle = -90;
                if(this->angle == -90){this->positionX++;SDL_Delay(slw);};
                break;
                case 'S':this->positionY++;SDL_Delay(slw);break;
                default:;break;
            }
        }
    }
};

//DIRECTION SOUTH CARS:
class CarS : public Car{
    public:
    CarS();
    ~CarS(){};
    void move(char lightstatus, SDL_Rect rect);
    void CarBuild(SDL_Renderer *renderer , int appwidth);

};
CarS :: CarS() : Car() {
    this->direction = 'S';
};
void CarS :: CarBuild(SDL_Renderer *renderer , int appwidth){
    char path[150]="cars images/cars S/";
    srand(time(NULL));
    int i = rand()%5;
    strcat(path,this->carsimages[i]);
    this->car = SDL_LoadBMP(path);
    this->texture = SDL_CreateTextureFromSurface(renderer,this->car);
    SDL_FreeSurface(car);
    char carStatus[4]={'S','R','L'};
    int j = rand()%2;
    this->status = carStatus[j];
    this->cadre.w = 25;
    this->cadre.h = 70;
    this->angle = 0;
    this->positionX = appwidth - 285;
    this->positionY = 600;
    SDL_QueryTexture(this->texture,NULL,NULL,&this->cadre.w,&this->cadre.h);
};
void CarS :: move(char lightstatus , SDL_Rect rect){
    if( !(lightstatus == 'R' && this->positionY == 380) ){
        if(!SDL_HasIntersection(&this->cadre , &rect )){
            switch(this->status){
                case 'R':
                if(this->positionY > 300){this->positionY--;SDL_Delay(slw);};
                if(this->positionY == 301 ) this->angle = 90;
                if(this->angle == 90){this->positionX++;SDL_Delay(slw);};
                break;
                case 'L':
                if(this->positionY > 250){this->positionY--;SDL_Delay(slw);};
                if(this->positionY == 251 )this->angle = -90;
                if(this->angle == -90){this->positionX--;SDL_Delay(slw);};
                break;
                case 'S':this->positionY--;SDL_Delay(slw);break;
            }
        }
    }
};


//DIRECTION EST CARS:
class CarE : public Car{
    public:
    CarE();
    ~CarE(){};
    void move(char lightstatus, SDL_Rect rect);
    void CarBuild(SDL_Renderer *renderer , int appwidth);
};
CarE :: CarE() : Car() {
    this->direction = 'E';
};
void CarE :: CarBuild(SDL_Renderer *renderer , int appwidth){
    char path[150]="cars images/cars E/";
    srand(time(NULL)+110000000000000);
    int i = rand()%5;
    strcat(path,this->carsimages[i]);
    this->car = SDL_LoadBMP(path);
    this->texture = SDL_CreateTextureFromSurface(renderer,this->car);
    SDL_FreeSurface(car);
    char carStatus[3]={'R','L','S'};
    int j = rand()%2;
    this->status = carStatus[j];
    this->cadre.w = 70;
    this->cadre.h = 25;
    this->angle = 0;
    this->positionX = appwidth;
    this->positionY = 260;
    SDL_QueryTexture(this->texture,NULL,NULL,&this->cadre.w,&this->cadre.h);
};
void CarE :: move(char lightstatus, SDL_Rect rect){
    if( !(lightstatus == 'R' && this->positionX == 380) ){
        if(!SDL_HasIntersection(&this->cadre , &rect )){
            switch(this->status){
                case 'R':
                if(this->positionX > 300){this->positionX--;SDL_Delay(slw);};
                if(this->positionX == 304 )this->angle = +90;
                if(this->angle == +90)this->positionY--;SDL_Delay(slw);
                break;
                case 'L':
                if(this->positionX > 250){this->positionX--;SDL_Delay(slw);};
                if(this->positionX == 254 ){this->angle = -90;};
                if(this->angle == -90){this->positionY++;SDL_Delay(slw);};
                break;
                case 'S':this->positionX--;SDL_Delay(slw);break;
                default:;break;
            }
        }
    }
};


//DIRECTION WEST CARS:
class CarW : public Car{
    public:
    CarW();
    ~CarW(){};
    void move(char lightstatus, SDL_Rect rect);
    void CarBuild(SDL_Renderer *renderer , int appwidth);
};
CarW :: CarW() : Car() {
    this->direction = 'W';
};
void CarW :: CarBuild(SDL_Renderer *renderer , int appwidth){
    char path[150]="cars images/cars W/";
    srand(time(NULL)+450000);
    int i = rand()%5;
    strcat(path,this->carsimages[i]);
    this->car = SDL_LoadBMP(path);
    this->texture = SDL_CreateTextureFromSurface(renderer,this->car);
    SDL_FreeSurface(car);
    char carStatus[3]={'S','R','L'};
    int j = rand()%2;
    this->status = carStatus[j];
    this->cadre.w = 70;
    this->cadre.h = 25;
    this->angle = 0;
    this->positionX = appwidth - 600;
    this->positionY = 315;
    SDL_QueryTexture(this->texture,NULL,NULL,&this->cadre.w,&this->cadre.h);
};
void CarW :: move(char lightstatus, SDL_Rect rect){
    if (!(lightstatus == 'R' && this->positionX == 167) ){
        if(!SDL_HasIntersection(&this->cadre , &rect )){
            switch(this->status){
                case 'R':
                if(this->positionX < 250){this->positionX++;SDL_Delay(slw);};
                if(this->positionX == 248 )this->angle = 90;
                if(this->angle == 90){this->positionY++;SDL_Delay(slw);};
                break;
                case 'L':
                if(this->positionX < 295){this->positionX++;SDL_Delay(slw);};
                if(this->positionX == 292 )this->angle = -90;
                if(this->angle == -90){this->positionY--;SDL_Delay(slw);};
                break;
                case 'S':this->positionX++;SDL_Delay(slw);break;
                default:;break;
            }
        }
    }
};
#endif
