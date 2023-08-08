#include<iostream>
#include<SDL2/SDL.h>
#include"grav.h"

void Window::init(){
    window = SDL_CreateWindow("grav", 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, 
    640, 480, 
    SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    rect.h = 5;
    rect.w = 5;
}
void Window::handleEvents(bool &run){
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT){
            run = false;
        }
    }
}

void Window::drawPlanet(double x, double y){
    rect.x = x;
    rect.y = y;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Planet::move(double* pxarr[30], double* pyarr[30], int* pmarr[30], int len){
    double c_acc;
    double ang;
    double dist_squared;
    xa = 0;
    ya = 0;
    for(int i = 0; i < len; i++){
        if(*pxarr[i] != x){
            c_acc = 0;
            ang = atan2(*pyarr[i]-y, *pxarr[i]-x);
            dist_squared = pow(*pyarr[i]-y, 2) + pow(*pxarr[i]-x, 2);
            if(dist_squared > 10){
                c_acc = *pmarr[i]/dist_squared;
            }
            xa += c_acc * cos(ang);
            ya += c_acc * sin(ang);
        }
    }
    xv += xa*dt;
    yv += ya*dt;
    if(x < 0 || x > W){
        xv *= -1;
    }
    if(y < 0 || y > H){
        yv *= -1;
    }
    
    x += xv*dt;
    y += yv*dt;

}