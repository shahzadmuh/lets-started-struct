
//
// example.c
//

#include <stdio.h>

#include "debug.h"

int main(int argc, const char * argv[]) {
    debug("I see what you did there o_O!");
//    die("OK die ramin");
    log_error("file can not found");
    log_info("OK ");
    return 0;
}
