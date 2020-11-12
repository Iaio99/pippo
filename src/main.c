#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*
#include <svn.h>
#include <git.h>
#include <aur.h>
*/

#include "options.h"

int err;
char *path = NULL;

static void usage(char *argv[]) {
	printf("%s <option> [package]\n\n", argv[0]);
	printf("\t-a, --aur: Specifies AUR as repository");
	printf("\t-g <user>, --git <user>: Specifies the user repository on GitHub");
	printf("\t-s <user>, --svn <user>: Same as git, but using svn for the download");
	printf("\t-p <path>, --path <path>: Specifies the path where download the package");
}

static bool parse_commands(int argc, char *argv[]) {
	if (argc < 3) {
		usage(argv);
		return false;
	}

	int c;
	int option_index;

	while ((c = getopt_long(argc, argv, "g:m:a", long_options, &option_index)) != -1) {
		switch (c) {
			case 'a':
				break;
			
			case 'g':
				break;
			 
			case 's':
				break;
			
			case 'p':
				path = optarg;
				break;
			
			case 0:
			case '?':
			default:
				usage(argv);
				return false;
		}
	}

	return true;
}

int main(int argc, char *argv[]) {
	if (path == NULL) {
		path = strcat(strcat(path, getenv("HOME")), "/pippo\0");
		if ((err = mkdir(path, 0755)))	{
		}
	}
	
	if ((err = chdir(path))) {
		fprintf(stderr, "The path specified doesn't exists\n");
		exit(-1);
	}

	if (!parse_commands(argc, argv)) {
		exit(-1);
	}

	return 0;
}