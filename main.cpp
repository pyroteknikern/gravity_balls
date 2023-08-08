#include<iostream>
#include<SDL2/SDL.h>
#include"grav.h"

void Planet::test(){
    std::cout << &x << " address for x in planet class" << std::endl;
}

void generate_planets(unsigned int n, Planet **planet_arr, Window &window){
    srand((unsigned) time(NULL));
    int vel = 3;
    int mass = 30;
    for(int i = 0; i < n; i++){
        planet_arr[i]->x = rand() % window.W;
        planet_arr[i]->y  = rand() % window.H;
        planet_arr[i]->xv = (rand() % vel)-vel/2;
        planet_arr[i]->yv  = (rand() % vel)-vel/2;
        planet_arr[i]->mass = (rand() % mass);
    }
}

int main(){



    bool run = true;
    Window window;

    int planet_arr_len = 30;

    Planet planets[planet_arr_len];
    Planet *planet_arr[planet_arr_len];
    for(int i = 0; i < planet_arr_len; i++){
        planet_arr[i] = &planets[i];
    }
    generate_planets(planet_arr_len, planet_arr, window);


    double* x_vals_ptr_list[30];
    double* y_vals_ptr_list[30];
    int* m_vals_ptr_list[30];
    for(int i = 0; i < planet_arr_len; i++){
        x_vals_ptr_list[i] = &planet_arr[i]->x;
        y_vals_ptr_list[i] = &planet_arr[i]->y;
        m_vals_ptr_list[i] = &planet_arr[i]->mass;
    }
    window.init();

    int counter = 0;
    while(run){
        counter++;
        for(int i = 0; i < planet_arr_len; i++){
            planet_arr[i]->move(x_vals_ptr_list, y_vals_ptr_list, m_vals_ptr_list, planet_arr_len);
        }
        if(counter == 1000){
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