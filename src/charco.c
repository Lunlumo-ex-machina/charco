#include "charco.h"

void print_html(uint32_t ch) {
	printf("HTML: &#%d;\n", ch);
}

void print_unicode(uint32_t ch) {
	printf("Unicode: U+%04X\n", ch);
}

void print_css(uint32_t ch) {
	printf("CSS: \\%04X\n", ch);
}

void print_utf8(uint32_t ch) {
	printf("UTF-8: %X\n", ch);
}

void print_utf16(uint32_t ch) {
	printf("UTF-16: %04X\n", ch);
}

void printf_charco(uint32_t ch) {
//	setlocale(LC_ALL, "");
//	printf("Character: %lc\n", utf8_decode(ch));
	print_utf8(ch);
	ch = utf8_decode(ch);
	print_utf16(utf16_encode(ch));
	print_unicode(ch);
	print_html(ch);
	print_css(ch);
}

void print(uint32_t ch, format_t format) {
	switch (format) {
		case HTML:
			print_html(utf8_decode(ch));
			break;
		 case CSS:
			print_css(utf8_decode(ch));
			break;
		 case UNI:
			print_unicode(utf8_decode(ch));
			break;
		case UTF8:
			print_utf8(ch);
			break;
		default:
			printf_charco(ch);
			break;
	}
}

int main(int argc, char *argv[]) {

	/* Default arguments */
	arguments_t arguments;
	arguments.ch = '\0';
	arguments.format = ALL;

	argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &arguments);

	print(arguments.ch, arguments.format);
	return 0;
}
