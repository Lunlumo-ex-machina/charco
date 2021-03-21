#include "args.h"

uint32_t str_to_uint(const char *str, int len) {
	uint32_t result = 0;
	for (int i = 0; i < len; i++) {
		result |= (str[i] & 0xFF) << (8 * ((len-i)-1));
	}
	return result;
}

int ch_len(unsigned char ch) {
	ch &= 0xFF;
	if (((ch > 0x7F) && (ch < 0xC2)) || (ch > 0xF4)) {
		return -1;
	}
	if (ch < 0x80) {
		return 1;
	} else if (ch < 0xE0) {
		return 2;
	} else if (ch < 0xF0) {
		return 3;
	} else {
		return 4;
	}
}

error_t parse_opt(int key, char *arg, struct argp_state *state) {
	arguments_t *arguments = state->input;
	switch (key) {
		case 'h':
			argp_state_help(state, stdout, ARGP_HELP_LONG | ARGP_HELP_DOC | ARGP_HELP_BUG_ADDR | ARGP_HELP_EXIT_OK);
			break;
		case 'u':
			argp_usage(state);
			break;
		case 'f':
			if (!strcmp("html", arg)) {
				arguments->format = HTML;
			} else if (!strcmp("css", arg)) {
				arguments->format = CSS;
			} else if (!strcmp("unicode", arg)) {
				arguments->format = UNI;
			} else if (!strcmp("all", arg)) {
				arguments->format = ALL;
			} else if (!strcmp("utf8", arg)) {
				arguments->format = UTF8;
			} else if (!strcmp("utf16", arg)) {
				arguments->format = UTF16;
			} else {
				argp_usage(state);
			}
			break;
		case ARGP_KEY_ARG:
			if (state->arg_num > 0) {
				argp_usage(state);
			}
			arguments->ch = str_to_uint(arg, ch_len(arg[0]));
			break;
		case ARGP_KEY_NO_ARGS:
			argp_usage(state);
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}
