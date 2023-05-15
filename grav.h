#ifndef grav_h
#define grav_h
#include<iostream>
#include<SDL2/SDL.h>

class Planet{
    float dt = 0.001;
    public:
    double x;
    double y;
    double xv;
    double yv;
    double xa;
    double ya;
    int H = 480;
    int W = 640;;
    int mass;
    int radius;
    void test();
    void move(double*[30], double*[30], int*[30], int);
};


class Window{
    public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    SDL_Rect rect;
    void init();
    void handleEvents(bool&);
    void drawPlanet(double, double);
};

#endif