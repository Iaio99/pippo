#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "path.h"

bool exists(char *folder) {
    opendir(folder);
    
    if (errno == ENOENT) {
        return false;
    }
    return true;
}
