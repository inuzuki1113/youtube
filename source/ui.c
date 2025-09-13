#include "ui.h"
#include <sf2d.h>
#include <stdio.h>

char videoTitles[10][128];
int videoCount = 0;
int currentIndex = 0;

void uiInit() {
    sf2d_init();
}

void uiExit() {
    sf2d_fini();
}

void uiUpdate() {
    sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
    sf2d_draw_rectangle(0,0,400,240, C_BLACK);

    for (int i=0; i<videoCount; i++) {
        if (i == currentIndex)
            sf2d_draw_rectangle(0, i*20, 400, 20, C_BLUE);
        sf2d_draw_text(10, i*20, C_WHITE, videoTitles[i]);
    }

    sf2d_end_frame();
}
