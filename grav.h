#ifndef grav_h
#define grav_h
#include<iostream>
#include<SDL2/SDL.h>

class Planet{
    public:
    long long x;
    long long y;
    long long xv;
    long long yv;
    long long xa;
    long long ya;
    int mass;
    int radius;
    void move(long long*[30], long long*[30], int);
};


class Window{
    public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    SDL_Rect rect;
    void init();
    void handleEvents(bool&);
    void drawPlanet(long long, long long);
};

#endif