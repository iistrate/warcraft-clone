//
//  World.h
//  warcraft
//
//  Created by Ioan Istrate on 10/30/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//


#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Image.h"
#include "Tile.h"
#include "globals.h"

class World {
    std::vector < std::vector < Tile* > > tiles;
    
    int width;
    int height;
    const char* name;
    
public:
    World(int w, int h): width(w), height(h) {
        //calculate number of per w tiles
        const int num_tiles_width = width / TILE_WIDTH;
        //calculate number of per h tiles
        const int num_tiles_height = height / TILE_HEIGHT;
        
        const char* name = "Swamp World";
        
        for (int y = 0; y < num_tiles_height; y++) {
            //Tile(Image* img, int w, int h, int x, int y, bool blocking, bool special):image(img), width(w), height(h), x(x), y(y), blocking(blocking), special(special)
            tiles.push_back(std::vector < Tile* >());
            for (int x = 0; x < num_tiles_width; x++) {
                Image* tile_image = new Image(x, y, image_types[DEFAULT_TILE]);
                tiles[y].push_back(new Tile(tile_image, TILE_WIDTH, TILE_HEIGHT, x, y, false, false));
            }
        }
    }
    ~World() {
        //delete tiles[];
    }
    std::vector < std::vector < Tile* > >* get_tiles() {
        return &tiles;
    }
    std::vector < Image* > get_tile_images() {
        //calculate number of per w tiles
        const int num_tiles_width = width / TILE_WIDTH;
        //calculate number of per h tiles
        const int num_tiles_height = height / TILE_HEIGHT;
        
        std::vector < Image* > img;
        
        for (int y = 0; y < num_tiles_height; y++) {
            for (int x = 0; x < num_tiles_width; x++) {
                img.push_back(tiles[y][x]->get_image());
            }
        }
        return img;
    }
    
    
};


#endif
