#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//#include "compile.h"
#include "options.h"
#include "path.h"
//#include "repo.h"

char *path = NULL;

static void usage(char *argv[]) {
	printf("%s <option> [package]\n\n", argv[0]);
	printf("\t-a, --aur: Specifies AUR as repository\n");
	printf("\t-g <user>, --git <user>: Specifies the user repository on GitHub\n");
	printf("\t-s <user>, --svn <user>: Same as git, but using svn for the download\n");
	printf("\t-p <path>, --path <path>: Specifies the path where download the package\n");
}


static bool parse_commands(int argc, char *argv[]) {
	if (argc < 3) {
		usage(argv);
		return false;
	}

	int c;
	int option_index;

	while ((c = getopt_long(argc, argv, "p:a:g:s", long_options, &option_index)) != -1) {
		switch (c) {
			case 'p':
				path = optarg;

				if (!exists(path)) {
					fprintf(stderr, "The path specified doesn't exists\n");
					exit(-1);
				}			
			
			case 'a':
				break;
			
			case 'g':
				break;
			 
			case 's':
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
		chdir(getenv("HOME"));
		
		if (!exists("pippo")) {
			mkdir("pippo", 0755);
		}
	}

	if (!parse_commands(argc, argv)) {
		exit(-1);
	}

	return 0;
}
