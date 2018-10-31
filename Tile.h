//
//  Tile.h
//  warcraft
//
//  Created by Ioan Istrate on 10/30/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//

#ifndef TILE_H
#define TILE_H

#include "Image.h"

class Tile {
    Image* image;
    
    int width;
    int height;
    int x;
    int y;
    
    bool blocking;
    bool special;
    
public:
    Tile(Image* img, int w, int h, int x, int y, bool blocking, bool special):image(img), width(w), height(h), x(x), y(y), blocking(blocking), special(special) {
    }
    ~Tile() {
        delete image;
    }
    Image* get_image() {
        return image;
    }
    bool is_special() {
        return special;
    }
    bool is_blocking() {
        return blocking;
    }
    void set_special(bool b) {
        special = b;
    }
    void set_blocking(bool b) {
        blocking = b;
    }
};


#endif
