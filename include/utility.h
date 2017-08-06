#ifndef __UTILITY_H
#define __UTILITY_H
#include "types.h"

BOOL fileExists(const char *file);

int getLen(int x);

BOOL fileRemove(const char *file);

BOOL dirExists(const char *dir);

char *getDate();

#endif

