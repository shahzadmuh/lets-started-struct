#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libb64/b64.h"
#include "unlikely.h"
#include "types.h"


int
main (void) {
  unsigned char *str = "Hello";
  char *enc = b64_encode(str, strlen(str));
  BOOL a = false;
  if (likely(a))
      printf("hahah haha \n");

  printf("%s\n", enc);

  char *dec = b64_decode(enc, strlen(enc));

  printf("%s\n", dec);
  free(enc);
  free(dec);
  return 0;
}
