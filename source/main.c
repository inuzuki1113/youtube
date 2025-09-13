#include <3ds.h>
#include "ui.h"
#include "video.h"
#include "network.h"

int main() {
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL);

    uiInit();
    videoInit();
    networkInit();

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        // 下画面UI更新（検索・リスト操作）
        uiUpdate();

        // 上画面動画再生（ストリーミング）
        videoUpdate();

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();

        if (kDown & KEY_START) break;
    }

    networkExit();
    videoExit();
    uiExit();
    gfxExit();
    return 0;
}
