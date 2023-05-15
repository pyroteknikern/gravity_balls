#include<iostream>
#include<SDL2/SDL.h>
#include"grav.h"

int main(){

    bool run = true;
    Window window;

    Planet planet1;
    planet1.x = 100;
    planet1.y = 100;

    Planet planet2;
    planet2.x = 200;
    planet2.y = 200;

    Planet planet_arr[] = {planet1, planet2};
    int planet_arr_len = sizeof(planet_arr) / sizeof(Planet);
    long long* x_vals_ptr_list[30];
    long long* y_vals_ptr_list[30];
    for(int i = 0; i < planet_arr_len; i++){
        x_vals_ptr_list[i] = &planet_arr[i].x;
        y_vals_ptr_list[i] = &planet_arr[i].y;
    }

    window.init();

    while(run){
        SDL_RenderClear(window.renderer);
        window.handleEvents(run);
        for(int i = 0; i < planet_arr_len; i++){
            planet_arr[i].move(x_vals_ptr_list, y_vals_ptr_list, planet_arr_len);
        }


        SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
        SDL_RenderPresent(window.renderer);
        SDL_Delay(100);

    }
    SDL_DestroyWindow(window.window);
    SDL_Quit();

    return 1;
}