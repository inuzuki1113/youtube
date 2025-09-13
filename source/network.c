#include "network.h"
#include <3ds.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void networkInit() {
    httpcInit(0);
}

void networkExit() {
    httpcExit();
}

// ニコニコ軽量HTML検索取得（簡易版）
int searchNicoVideos(const char* keyword, char videoURLs[][256], char titles[][128], int maxCount) {
    char url[512];
    snprintf(url, sizeof(url), "https://sp.nicovideo.jp/search/%s", keyword);

    httpcContext context;
    httpcOpenContext(&context, HTTP_METHOD_GET, url, 1);
    httpcBeginRequest(&context);

    u32 statuscode = 0;
    httpcGetResponseStatusCode(&context, &statuscode);
    if (statuscode != 200) {
        httpcCloseContext(&context);
        return 0;
    }

    u32 size = 0;
    httpcGetDownloadSizeState(&context, &size);
    char* buffer = malloc(size + 1);
    memset(buffer, 0, size + 1);
    httpcReceiveData(&context, buffer, size, NULL);

    int count = 0;
    char* p = buffer;
    while (count < maxCount && (p = strstr(p, "<a href=\"/watch/")) != NULL) {
        p += 9; // /watch/ まで進める
        strncpy(videoURLs[count], "/watch/", 7);
        int i = 7;
        while (*p != '"' && i < 255) videoURLs[count][i++] = *p++;
        videoURLs[count][i] = 0;

        strcpy(titles[count], "動画タイトル");

        count++;
    }

    free(buffer);
    httpcCloseContext(&context);
    return count;
}
