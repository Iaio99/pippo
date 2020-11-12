#pragma once
#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <getopt.h>

static struct option long_options[] = {
	{"aur",		no_argument,		0, 'a'},
	{"git",		required_argument,	0, 'g'},
	{"svn",		required_argument,	0, 's'},
	{"path",	required_argument,	0, 'p'},
	{0,			0,		0, 0}
};

#endif
