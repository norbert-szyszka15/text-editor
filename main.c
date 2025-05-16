#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "window.h"

int main(int argc, char *argv[]) {
    // allocates memory for WindowSize struct
    WindowSize* w = get_window_size();
    draw_interface(w);

    // printf("%*d x %d\n", w->width - 10, 100, 100);

    // frees memory allocated for WindowSize struct
    free(w);
    return 0;
} 