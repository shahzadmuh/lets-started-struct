#include <assert.h>
#include "utility.h"


int main(int argc, char *argv[]) {
  
    if (fileExists("src/main.c"))
        printf("exist file \n");
    if (fileRemove("")){
        printf("Delete file \n");
    }
    if (dirExists("")){
        printf("exist dir\n");
    }
        
    printf(" Date : %s\n",getDate());
    return 1;
}
