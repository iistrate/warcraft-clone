//
//  Image.h
//  warcraft
//
//  Created by Ioan Istrate on 10/26/18.
//  Copyright © 2018 Ioan Istrate. All rights reserved.
//

#ifndef IMAGE_H
#define IMAGE_H

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
