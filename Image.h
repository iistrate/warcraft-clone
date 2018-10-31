//
//  Image.h
//  warcraft
//
//  Created by Ioan Istrate on 10/26/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//

#ifndef IMAGE_H
#define IMAGE_H

#include "globals.h"

class Image {
    //screen location
    int x;
    int y;
    
    int width;
    int height;
    
    int layer;
    bool is_animated;
    bool is_flipped;
    bool is_static;
    int current_frame;
    int total_frames;
    
    
    //image location in sprite
    int sprite_x;
    int sprite_y;
    
    const char *file_name;
    
    
public:
    Image(int x, int y, struct image_type image_t):
          x(x), y(y), width(image_t.w), height(image_t.h), layer(image_t.layer), is_animated(image_t.animated), is_flipped(image_t.flipped),
          is_static(image_t.is_static), current_frame(image_t.cf), total_frames(image_t.tf), sprite_x(image_t.s_x), sprite_y(image_t.s_y), file_name(image_t.file_name)
    {}
    Image(int x, int y, int w, int h, int layer, bool animated, bool flipped, bool is_static, int cf, int tf, int s_x, int s_y, const char* file_name):
              x(x), y(y), width(w), height(h), layer(layer), is_animated(animated), is_flipped(flipped), is_static(is_static), current_frame(cf), total_frames(tf), sprite_x(s_x), sprite_y(s_y), file_name(file_name)
    {}

    ~Image() {}
    
    const char* get_file_name() {
        return file_name;
    }
    bool get_is_animated() {
        return is_animated;
    }
    bool get_is_flipped() {
        return is_flipped;
    }
    int get_frame() {
        return current_frame;
    }
    int get_total_frames()  {
        return total_frames;
    }
    int get_width() {
        return width;
    }
    int get_height() {
        return height;
    }
    int get_sprite_x() {
        return sprite_x;
    }
    int get_sprite_y() {
        return sprite_y;
    }
    bool get_is_static() {
        return is_static;
    }
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    
    void set_current_frame(int frame_num) {
        current_frame = frame_num;
    }
    void set_animate(bool animate) {
        is_animated = animate;
    }
};

#endif
