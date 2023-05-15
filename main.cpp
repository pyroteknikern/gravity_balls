#include<iostream>
#include<SDL2/SDL.h>
#include"grav.h"

void Planet::test(){
    std::cout << &x << " address for x in planet class" << std::endl;
}

int main(){



    bool run = true;
    Window window;

    Planet planet1;
    planet1.x = 100;
    planet1.y = 100;
    planet1.xv = 0;
    planet1.yv = 0.2;
    planet1.mass = 10;

    Planet planet2;
    planet2.x = 200;
    planet2.y = 200;
    planet2.xv = 0;
    planet2.yv = -0.3;
    planet2.mass = 10;

    Planet planet3;
    planet3.x = 400;
    planet3.y = 200;
    planet3.xv = 0;
    planet3.yv = 0.1;
    planet3.mass = 10;

    Planet planet_arr[] = {planet1, planet2, planet3};
    int planet_arr_len = sizeof(planet_arr) / sizeof(Planet);
    double* x_vals_ptr_list[30];
    double* y_vals_ptr_list[30];
    int* m_vals_ptr_list[30];
    for(int i = 0; i < planet_arr_len; i++){
        x_vals_ptr_list[i] = &planet_arr[i].x;
        y_vals_ptr_list[i] = &planet_arr[i].y;
        m_vals_ptr_list[i] = &planet_arr[i].mass;
    }


    window.init();

    int counter = 0;
    while(run){
        counter++;
        for(int i = 0; i < planet_arr_len; i++){
            planet_arr[i].move(x_vals_ptr_list, y_vals_ptr_list, m_vals_ptr_list, planet_arr_len);
        }
        if(counter == 100){
            SDL_RenderClear(window.renderer);
            window.handleEvents(run);
            for(int i = 0; i < planet_arr_len; i++){
                window.drawPlanet(*x_vals_ptr_list[i], *y_vals_ptr_list[i]);
            }
            SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
            SDL_RenderPresent(window.renderer);
            counter = 0;
        }
    }
    SDL_DestroyWindow(window.window);
    SDL_Quit();

    return 1;
}