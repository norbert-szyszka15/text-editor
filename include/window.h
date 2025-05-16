#ifndef WINDOW_H
#define WINDOW_H

typedef struct {
    unsigned short width;
    unsigned short height;
} WindowSize;

WindowSize* get_window_size();

void draw_interface(WindowSize* terminal);

#endif // WINDOW_H