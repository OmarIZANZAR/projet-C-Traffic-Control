#ifndef _APP_H
#define _APP_H

#include<SDL.h>
#include<iostream>
using namespace std;

class App{
    public:
    App(char name[50],int width,int height);
    ~App();
    SDL_bool isAppRunning();
    SDL_Renderer *GetRenderer();
    void InitAppWindow();
    void AppClearer();
    void AppUpdate();
    void QuitEventLoop();
    void AppQuit();
    int GetAppWidth();

    private:
    char name[50];
    int width, height;
    SDL_bool AppRunning = SDL_FALSE;
    SDL_Window *AppWindow = NULL;
    SDL_Renderer *AppRenderer = NULL;
};

App::App(char name[50],int width,int height){
    strcpy( this->name , name);
    this->width = width;
    this->height = height;
};

SDL_bool App::isAppRunning(){
    return this->AppRunning ;
};


void App::InitAppWindow(){
    SDL_Init(SDL_INIT_EVERYTHING);
    this->AppWindow = SDL_CreateWindow(this->name,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,this->width,this->height,0);
    this->AppRunning = SDL_TRUE;
    this->AppRenderer = SDL_CreateRenderer(AppWindow,-1,SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(AppRenderer,255,255,255,255);
    SDL_RenderClear(AppRenderer);
};

SDL_Renderer* App::GetRenderer(){
    return this->AppRenderer;
};

int App :: GetAppWidth(){
    return this->width;
};

void App::AppClearer(){
    SDL_RenderClear(this->AppRenderer);
};

void App::AppUpdate(){
    SDL_RenderPresent(this->AppRenderer);
};

void App::QuitEventLoop(){
    this->AppRunning = SDL_FALSE;
};

void App::AppQuit(){
    this->AppRunning = SDL_FALSE;
    SDL_DestroyRenderer(this->AppRenderer);
    SDL_DestroyWindow(this->AppWindow);
    SDL_Quit();
};

App::~App(){
    cout<<"App: "<<this->name<<" destroyed"<<endl;
};

#endif