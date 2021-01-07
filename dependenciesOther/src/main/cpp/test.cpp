#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int test_function(){
#ifdef SWITCH
    printf("%s", "has defined SWITCH");
#else
    printf1("%s", "hasn't defined SWITCH");
#endif
}