#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#include "window.h"


WindowSize* get_window_size() {
    struct winsize terminal_size;
    if (ioctl(0, TIOCGWINSZ, &terminal_size) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }
    
    WindowSize* size = (WindowSize*)malloc(sizeof(WindowSize));
    if (!size) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    size->width = terminal_size.ws_col;
    size->height = terminal_size.ws_row;
    return size;
}


void draw_interface(WindowSize* terminal) {
    int limit = (terminal->height - 1) * terminal->width;
    for (int i = 0; i < limit; i++) {
        putchar(' ');
    }

    for (int i = 0; i < terminal->width; i++) {
        putchar('-');
    }

    // Print terminal size --- x --- 
    if (terminal->width > 100 && terminal->height > 100) {
        printf("%*d x %d\n", terminal->width - 5, terminal->width, terminal->height);
    }
    // Print terminal size --- x -- or -- x --- 
    if ((terminal->width > 100 && terminal->height < 100) || (terminal->width < 100 && terminal->height > 100)) {
        printf("%*d x %d\n", terminal->width - 4, terminal->width, terminal->height);
    }
    // Print terminal size -- x --
    if (terminal->width < 100 && terminal->height < 100) {
        printf("%*d x %d\n", terminal->width - 6, terminal->width, terminal->height);
    }

    printf("\n");
}