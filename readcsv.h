#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 100
#define HEADER_H
#define LINENUM 401
#define COLNUM 4
#ifdef HEADER_H
char header[MAXLEN];

#endif // HEADER_H

int readData(const char *filePath, const char *dlim, char *res[][COLNUM]);
