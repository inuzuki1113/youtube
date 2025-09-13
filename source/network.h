#ifndef NETWORK_H
#define NETWORK_H

void networkInit();
void networkExit();

// 最大 maxCount 件まで取得
int searchNicoVideos(const char* keyword, char videoURLs[][256], char titles[][128], int maxCount);

#endif
