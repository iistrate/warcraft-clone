//
//  globals.h
//  warcraft
//
//  Created by Ioan Istrate on 10/26/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//

#ifndef GLOBALS_H
#define GLOBALS_H

#define P(x) std::cout << #x << "'s value is " << x << std::endl;

namespace GLOBALS {
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 960;
    const int LEVEL_WIDTH = 2400;
    const int LEVEL_HEIGHT = 1920;
}

enum TILE_TYPES {
    DEFAULT_TILE = 0
    
};

const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;

enum LAYER_TYPES {
    BACKGROUND_LAYER=1
};

struct image_type {
    int w, h, layer, cf, tf, s_x, s_y;
    const char* file_name;
    bool flipped, is_static, animated;
};

extern struct image_type image_types[];

#endif
