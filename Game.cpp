//
//  Game.cpp
//  warcraft
//
//  Created by Ioan Istrate on 10/28/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//

#include "Game.h"


void Game::run() {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        //hint to enable vsync?
        SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); //linear scaling
        
        const char* window_title = "LEVEL 1";
        pwindow = SDL_CreateWindow(window_title, 0, 0, GLOBALS::SCREEN_WIDTH, GLOBALS::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (pwindow) {
            prenderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawColor(prenderer, 0xFF, 0x00, 0x00, 0xDD);
            //SDL_StartTextInput(); //accept key commands
        }
        else {
            std::cout << "Window failed to load\n";
        }
        
        //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest"); set before pixel art texture
    }
    else {
        std::cout << "SDL failed to initialize" << std::endl;
    }
    
    std::vector< Image* > images;
    //    Image(int x, int y, int w, int h, int layer, bool animated, bool flipped, bool is_static, int cf, int tf, int s_x, int s_y, const char* file_name):
    images.push_back(new Image(0, 0, 32, 32, 1, 0, 0, 0, 1, 1, 200, 8, "/Users/ioan1/warcraft/warcraft/assets/daemon.png"));
    images.push_back(new Image(100, 100, 380, 380, 1, 0, 0, 0, 1, 1, 0, 0, "/Users/ioan1/warcraft/warcraft/assets/micke_door.png"));

    while(running) {
        std::cout << "frame " << current_frame++ << "\n";
        
        
        //clear window
        SDL_RenderClear(prenderer);
        //set color bg to white
        SDL_SetRenderDrawColor(prenderer, 255, 255, 255, 255);

        //sort by layers
        
        //draw
        
        
        P("drawing");
        texture_manager->draw(prenderer, images);
        
        //render window
        SDL_RenderPresent(prenderer);
        sleep(1);
    }
    std::cout << "Game loop initiated\n";
}

Game::~Game() {
    SDL_Quit();
    SDL_DestroyWindow(pwindow);
    SDL_DestroyRenderer(prenderer);
    
}
