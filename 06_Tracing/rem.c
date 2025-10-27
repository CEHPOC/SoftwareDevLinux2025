#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

int (*original_remove)(const char *filename) = NULL;

int remove(const char *filename){
	if (!original_remove) {
        	original_remove = dlsym(RTLD_NEXT, "remove");
    	}

	if(strstr(filename, "PROTECT")!=NULL){
		return 0;
	}
	return original_remove(filename);
}
