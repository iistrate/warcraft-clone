//
//  Texture_Manager.cpp
//  warcraft
//
//  Created by Ioan Istrate on 10/26/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//

#include "Texture_Manager.h"

//TODO remove magic numbers
Texture_Manager::Texture_Manager(): ptexture(0), ptext_surface(0), pfont(0), camera_x(0), camera_y(0), level_height(GLOBALS::LEVEL_HEIGHT), level_width(GLOBALS::LEVEL_WIDTH), screen_width(GLOBALS::SCREEN_WIDTH), screen_height(GLOBALS::SCREEN_HEIGHT)
{
    //
}

void Texture_Manager::draw(SDL_Renderer *renderer, std::vector<Image *> images, SDL_RendererFlip flip) {
    int camera_modifier_x = (-1)* camera_x;
    int camera_modifier_y = (-1)* camera_y;
    
    int origin_x = 0;
    int origin_y = 0;
    int current_frame = 1;
    int total_frames = 2;
    bool is_animated = false;
    bool is_flipped = false;
    
    const char* file_name = "";
    
    for (std::vector< Image >::size_type i = 0; i != images.size(); i++) {
        if (file_name != images[i]->get_file_name()) {
            file_name = images[i]->get_file_name();
            ptexture = IMG_LoadTexture(renderer, file_name);
        }
        is_animated = images[i]->get_is_animated();
        is_flipped = images[i]->get_is_flipped();
        current_frame = images[i]->get_frame();
        total_frames = images[i]->get_total_frames();
        
        if (is_flipped) flip = SDL_FLIP_HORIZONTAL;
        else flip = SDL_FLIP_NONE;
        
        src_Rect.w = dst_Rect.w = images[i]->get_width();
        src_Rect.h = dst_Rect.h = images[i]->get_height();
        
        src_Rect.x = images[i]->get_is_animated() ? images[i]->get_sprite_x() + (current_frame * src_Rect.w) : images[i]->get_sprite_x();
        src_Rect.y = images[i]->get_sprite_y();
        
        origin_x = images[i]->get_x();
        origin_y = images[i]->get_y();
        
        dst_Rect.x = images[i]->get_is_static() ? origin_x : origin_x + camera_modifier_x;
        dst_Rect.y = images[i]->get_is_static() ? origin_y : origin_y + camera_modifier_y;
        
        //actual drawing
        SDL_RenderCopyEx(renderer, ptexture, &src_Rect, &dst_Rect, NULL, NULL, flip);
        
        if(is_animated) {
            //next frame is
            current_frame = current_frame + 1 == total_frames ? 1 : current_frame + 1;
            //set frame
            images[i]->set_current_frame(current_frame);
            images[i]->set_animate(false);
        }
    }
    SDL_DestroyTexture(ptexture);
    ptexture = NULL;
}

