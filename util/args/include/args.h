#ifndef ARGS_H
#define ARGS_H

#include <argp.h> // Arguments parser
#include <string.h> // strcmp
#include <stdint.h> // int types

typedef enum {
	ALL,
	UTF8,
	UTF16,
	HTML,
	CSS,
	UNI
} format_t;

typedef struct {
	format_t format;
	uint32_t ch;
} arguments_t;

const static char doc[] = "Charco\n"
						  "Usage:\n"
						  "  charco [-f]\n"
						  "\n"
						  "Options:\n"
						  "\v"
						  "Examples:\n"
						  "  charco ñ // Prints utf-8, utf-16, unicode, html and css code\n"
						  "charco -f html あ // Prints only html code\n"
						  "\n"
						  "Formats avaliable: utf8, utf16, unicode, html and css.\n"
						  "\n"
						  "MIT License Copyright (c) 2021 Lunlumo";
const static char arg_doc[] = "[OPTIONS...]";
const struct argp_option options[] = {
	{"help",   'h', 0,        0, "Display the help page.", -1},
	{"usage",  'u', 0,        0, "Display usage.", -1},
	{"format", 'f', "FORMAT", 0, "Select the format output."},
	{0}
};

error_t parse_opt(int key, char *arg, struct argp_state *state);

static struct argp argp = {options, parse_opt, arg_doc, doc};

uint32_t str_to_uint(const char *str, int len);

#endif // ARGS_H
