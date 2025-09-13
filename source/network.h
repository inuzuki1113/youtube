#ifndef NETWORK_H
#define NETWORK_H

void networkInit();
void networkExit();
int searchNicoVideos(const char* keyword, char videoURLs[][256], char titles[][128], int maxCount);

#endif
