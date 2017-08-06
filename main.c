#include "sha1.h"
#include "base64.h"
#include <assert.h>
#include "random.h"
#include "utility.h"


int main(int argc, char *argv[]) {
  
    char * result;
    char buffer[28];
    /*sha1_s sha1 = bscrypt_sha1_init();
    bscrypt_sha1_write(&sha1, "Hello", 43);
    result = bscrypt_sha1_result(&sha1);
    assert(result == (char *)sha1.digest.str);   
    */
    bscrypt_base64_encode(buffer, "Hello", 20);
    printf("Base64 : %s\n",buffer);

    //printf("Random : %u\n", bscrypt_rand32());
    

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
