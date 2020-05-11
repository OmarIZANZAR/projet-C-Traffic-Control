#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctime>
#include"App.h"
#include"Road.h"
#include"RoadLight.h"
#include"CarNEWS.h"
using namespace std;

SDL_Thread *ThreadA,*ThreadN,*ThreadS,*ThreadE,*ThreadW;

static int builderN(void* arg);
static int builderE(void* arg);
static int builderW(void* arg);
static int builderS(void* arg);
static int apprunner(void* arg);

int n=0, e=0, s=0 , w=0;
CarN tomobilN[8];
CarE tomobilE[8];
CarW tomobilW[8];
CarS tomobilS[8];

char appname[]="Traffic Control";
App application = App(appname, 600 , 600);

int main(int argc , char *argv[]){
    ThreadN = SDL_CreateThread(builderN,"N",(void *)NULL);
    ThreadW = SDL_CreateThread(builderW,"W",(void *)NULL);
    ThreadE = SDL_CreateThread(builderE,"E",(void *)NULL);
    ThreadS = SDL_CreateThread(builderS,"S",(void *)NULL);
    ThreadA = SDL_CreateThread(apprunner,"Apprun",NULL);
    SDL_WaitThread(ThreadA,NULL);
    SDL_WaitThread(ThreadN,NULL);
    SDL_WaitThread(ThreadE,NULL);
    SDL_WaitThread(ThreadW,NULL);
    SDL_WaitThread(ThreadS,NULL);
    return EXIT_SUCCESS;
}

static int builderN (void* arg){
	int compteur = 10;
	while(1)
	{
		compteur ++;
		if(compteur == 12){
            tomobilN[n].CarBuild(application.GetRenderer(),application.GetAppWidth());
            n++;
            compteur=0;
        }
        if(n == 7)n=0;
		SDL_Delay(1000);
	}
	SDL_DetachThread(ThreadN);
    return 0;
}

static int builderE (void* arg){
	int compteur = 9;
	while(1)
	{
		compteur ++;
		if(compteur == 12){
            tomobilE[e].CarBuild(application.GetRenderer(),application.GetAppWidth());
            e++;
            compteur =0;
        }
        if(e == 7)e=0;
		SDL_Delay(1000);
	}
	SDL_DetachThread(ThreadE);
    return 0;
}

static int builderW (void* arg){
	int compteur = 7;
	while(1)
	{
		compteur++;
		if(compteur == 12){
            tomobilW[w].CarBuild(application.GetRenderer(),application.GetAppWidth());
            w++;
            compteur=0;
        }
        if(w == 7)w=0;
		SDL_Delay(1000);
	}
	SDL_DetachThread(ThreadW);
    return 0;
}
static int builderS (void* arg){
	int compteur = 10;
	while(1)
	{
		compteur ++;
		if(compteur == 12){
            tomobilS[s].CarBuild(application.GetRenderer(),application.GetAppWidth());
            s++;
            compteur =0;
        }
        if(s == 7)s=0;
		SDL_Delay(1000);
	}
	SDL_DetachThread(ThreadS);
    return 0;
}

static int apprunner (void* arg){
    //ROAD GENERATING:
    Road crossroad = Road();
    //ROAD LIGHTS GENERATING:
    RoadLight LightN = RoadLight('N');
    RoadLight LightE = RoadLight('E');
    RoadLight LightS = RoadLight('S');
    RoadLight LightW = RoadLight('W');

    //INITIATING APPLICATION:
    application.InitAppWindow();
    //ROAD BUILDING:
    crossroad.RoadBuild(application.GetRenderer(),application.GetAppWidth());
    //ROAD LIGHTS BUILDING:
    LightN.LightBuild(application.GetRenderer(),application.GetAppWidth());
    LightE.LightBuild(application.GetRenderer(),application.GetAppWidth());
    LightS.LightBuild(application.GetRenderer(),application.GetAppWidth());
    LightW.LightBuild(application.GetRenderer(),application.GetAppWidth());

    //APPLICATION LOOP:
    while(application.isAppRunning()){
        application.AppClearer();
        //ROAD SHOWING:
        crossroad.RoadShow(application.GetRenderer());
        //ROAD LIGHT SHOWING:
        LightN.LightShow(application.GetRenderer());
        LightE.LightShow(application.GetRenderer());
        LightS.LightShow(application.GetRenderer());
        LightW.LightShow(application.GetRenderer());
        //CARS SHOWING AND MOVING:
        for(int i(0);i < n;i++){
            tomobilN[i].CarShow(application.GetRenderer());
            tomobilN[i].move(LightN.LightStatus(),tomobilN[i-1].GetRect());
            tomobilN[i].CarDestroy(application.GetAppWidth());
        }
        for(int i(0);i < s;i++){
            tomobilS[i].CarShow(application.GetRenderer());
            tomobilS[i].move(LightS.LightStatus(),tomobilS[i-1].GetRect());
            tomobilS[i].CarDestroy(application.GetAppWidth());
        }
        for(int i(0);i < e;i++){
            tomobilE[i].CarShow(application.GetRenderer());
            tomobilE[i].move(LightE.LightStatus(),tomobilE[i-1].GetRect());
            tomobilE[i].CarDestroy(application.GetAppWidth());
        }
        for(int i(0);i < w;i++){
            tomobilW[i].CarShow(application.GetRenderer());
            tomobilW[i].move(LightW.LightStatus(),tomobilW[i-1].GetRect());
            tomobilW[i].CarDestroy(application.GetAppWidth());
        }
        application.AppUpdate();
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:application.QuitEventLoop();
                              SDL_DetachThread(ThreadA);
                              SDL_DetachThread(ThreadN);
                              SDL_DetachThread(ThreadS);
                              SDL_DetachThread(ThreadE);
                              SDL_DetachThread(ThreadW);
                              break;
                case SDL_KEYDOWN : switch(event.key.keysym.sym){
                    case SDLK_KP_2 :LightS.lightGreen();
                                    LightN.lightRed();
                                    LightW.lightRed();
                                    LightE.lightRed();continue;
                    case SDLK_KP_6 :LightE.lightGreen();
                                    LightN.lightRed();
                                    LightW.lightRed();
                                    LightS.lightRed();continue;
                    case SDLK_KP_8 :LightN.lightGreen();
                                    LightS.lightRed();
                                    LightW.lightRed();
                                    LightE.lightRed();continue;
                    case SDLK_KP_4 :LightW.lightGreen();
                                    LightN.lightRed();
                                    LightS.lightRed();
                                    LightE.lightRed();continue;
                    case SDLK_s :LightS.lightGreen();
                                    LightN.lightRed();
                                    LightW.lightRed();
                                    LightE.lightRed();continue;
                    case SDLK_d :LightE.lightGreen();
                                    LightN.lightRed();
                                    LightW.lightRed();
                                    LightS.lightRed();continue;
                    case SDLK_z :LightN.lightGreen();
                                    LightS.lightRed();
                                    LightW.lightRed();
                                    LightE.lightRed();continue;
                    case SDLK_q :LightW.lightGreen();
                                    LightN.lightRed();
                                    LightS.lightRed();
                                    LightE.lightRed();continue;
                default:break;
                }
            }
        }
    };
    LightN.LightDestroy();
    LightE.LightDestroy();
    LightW.LightDestroy();
    LightS.LightDestroy();
    application.AppQuit();
	SDL_DetachThread(ThreadA);
}
//g++ src/main.cpp -o Traffic_Control -I include -L lib -lmingw32 -lSDL2main -lSDL2
