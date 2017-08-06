#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#include <sys/stat.h>
#include <stdbool.h>
#include "types.h"
#include <sys/unistd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include "jalali.h"
#include "string.h"
#include "stdlib.h"
#include "bytes.h"
#include <stdio.h>

#define MAX_STRING 13
char PERSIANDATE[MAX_STRING];
int lenHelper(unsigned x);
char day[3];
#define KB 1024
#define MB 1024 * KB
#define GB 1024 * MB


/* get length int value
 * @return value.length 
 * 
 */

int getLen(int x) {
    return x < 0 ? lenHelper(-x)+1 : lenHelper(x);
}

int lenHelper(unsigned x) {
    if(x>=1000000000) return 10;
    if(x>=100000000) return 9;
    if(x>=10000000) return 8;
    if(x>=1000000) return 7;
    if(x>=100000) return 6;
    if(x>=10000) return 5;
    if(x>=1000) return 4;
    if(x>=100) return 3;
    if(x>=10) return 2;
    return 1;
}

/**
 * Check if a file exists
 * @return true if and only if the file exists, false else
 */
BOOL fileExists(const char* file) {
    struct stat buf;
    if (stat(file, &buf) == 0)
        return TRUE;
    return FALSE;
}


/* Delete file if file exists
 * @return TRUE
 *
 */

BOOL fileRemove(const char *file){
    
    if(fileExists(file)){
       unlink(file);
       return TRUE;
    }   
    return FALSE;
}

/*
 * Return the filesize of `filename` or -1.
 */
size_t
file_size(const char *filename) {
  struct stat s;
  if (stat(filename, &s) < 0) return -1;
  return s.st_size;
}


/* Check directory  if directory exists
 * return TRUE
 */

BOOL dirExists(const char *dir){

    if (dir == '\0')
        return FALSE;
    DIR *openingdir = opendir(dir);
    if (openingdir){
        closedir(openingdir);
        return TRUE;
    }
    else if (ENOENT == errno)
    {
        return FALSE;
    }
    else
    {
        return FALSE;
    }
}
/* Get persian date
 * @return char *
 */
char *getDate(){
    
    int y, m, d;
    time_t bin_time;
    struct tm *br_time;
    char c = (char) d;

    time(&bin_time);
    br_time = localtime(&bin_time);

    gregorian_to_jalali(&y, &m, &d,1900+br_time->tm_year,1+br_time->tm_mon,br_time->tm_mday);
    
    if (getLen(d) == 1)
        snprintf(day,3,"0%d",(int)d); 
    else
        snprintf(day, 3, "%d",(int)d);
    
    snprintf(PERSIANDATE, MAX_STRING, "%d/%s/%s", y,j_month_number[m],day);
    return PERSIANDATE;
}

/* compare chars 
 * size strlen(char *)
 * if false return -1
 */

int comp_char(char *a, char *b, size_t size)
{
    size_t i;
	for (i = 0; i < size; i++)
		if (a[i] == b[i])
			return i;
	return -1;
}

/*
 * Convert the given `str` to byte count.
 */

long long
string_to_bytes(const char *str) {
  long long val = strtoll(str, NULL, 10);
  if (!val) return -1;
  if (strstr(str, "kb")) return val * KB;
  if (strstr(str, "mb")) return val * MB;
  if (strstr(str, "gb")) return val * GB;
  return val;
}

/*
 * Convert the given `bytes` to a string. This
 * value must be `free()`d by the user.
 */

char *
bytes_to_string(long long bytes) {
  long div = 1;
  char *str, *fmt;
  if (bytes < KB) { fmt = "%lldb"; }
  else if (bytes < MB) { fmt = "%lldkb"; div = KB; }
  else if (bytes < GB) { fmt = "%lldmb"; div = MB; }
  else { fmt = "%lldgb"; div = GB; }
  asprintf(&str, fmt, bytes / div);
  return str;
}
#endif

