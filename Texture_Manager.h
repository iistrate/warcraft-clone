//
//  Texture_Manager.h
//  warcraft
//
//  Created by Ioan Istrate on 10/26/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <vector>
#include <iostream>
#include <string>

#include "globals.h"
#include "Image.h"

class Texture_Manager {
  
    SDL_Rect dst_Rect;
    SDL_Rect src_Rect;
    SDL_Texture* ptexture;
    
    SDL_Surface* ptext_surface;
    TTF_Font* pfont;
    const char *text;
    std::string command;
    int font_width;
    
    Uint32 FPS;
    
    int camera_x;
    int camera_y;
    int camera_speed;
    
    int level_width;
    int level_height;
    
    int screen_width;
    int screen_height;
    
public:
    Texture_Manager();
    ~Texture_Manager();
    
    void draw(SDL_Renderer* renderer, std::vector < Image* > images, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void draw_image(SDL_Renderer* renderer, Image* Image);
    
};


#endif
