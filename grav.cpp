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

void Window::drawPlanet(long long x, long long y){
    rect.x = x;
    rect.y = y;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Planet::move(long long* pxarr[30], long long* pyarr[30], int len){
    for(int i = 0; i < len; i++){
        
    }
}
