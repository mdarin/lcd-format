// format va_list function template realisation
// version: 0.1
// date: 21:52 13.02.2014
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>



//classic putc fucntion
void lcd_putc(char c);

//classic puts function
void lcd_puts(char* s);

// format function
void lcd_format(char* format, ...);
void uart_format(char* format, ...);

void tpl_format(char* format, ...);

int main(void)
{
	printf("Hello, World!\n");
	tpl_format("smi\ath\t\t barywell\v rock\n%%per%%cent%%\n%d\n%x\n%X\n\b\r\r%f\n%s rest text...\n", 123, 10, 11, 7.777, "my test string");
	return 0;
}


void lcd_putc(char c)
{
	//putc(stdout, c);
	return;
}

void lcd_puts(char* s)
{
	//puts(s);
	return;
}

/*
Структура управляющей последовательности
Управляющая последовательность имеет вид:
%[флаги][ширина][.точность][размер]тип
*/
void lcd_format(char* format, ...)
{
	return;
}


void uart_format(char* format, ...)
{

	return;
}

/*
	template formated output compatible with standard printf function
	on curret version realised just %specifier grammar feachers sub set.
	Avalible specifiers: d, i, u, o, x, X, c, s, %
	v.0.1
	date: 16:22 14.02.2014
*/
void tpl_format(char* format, ...)
{
	va_list list;
	int n;
	double f;
	char c;
	char* s;

	//char flags;// = - + (space) # 0
	//char width;// = (number) *
	//char precision;// = .(number) .*
	//char length;// = hh h l ll j z t L
	char specifier;// = d i o x X f F e E g G a A c s p n %

	va_start(list, format);
	int i;
	for (i = 0; format[i]; i++) {
		switch (format[i]) {
		//escape sequence
		case '\n': // line feed
				printf("[LF]");
				break;
		case '\t': // horizontal tab
				printf("[HT]");
				break;
		case '\b': // backspace
				printf("[BS]");
				break;
		case '\r': // carriage retreat
				printf("[CR]");
				break;
		case '\v': // vertical tab
				printf("[VT]");
				break;
		case '\a': // beep
				printf("[BP]");
				break;
		// specifier
		case '%': // specifier identifier
			specifier = format[i+1];
			switch (specifier) {
			case '%':
				printf("[%%]");
				i++;
				break;
			case 'd': // signed decimal integer
			case 'i':
				n = va_arg(list, int);
				printf("[%d]", n);
				i++;
				break;
			case 'x': // unsigne hexademical integer
				n = va_arg(list, unsigned char);
				printf("[%x]", n);
				i++;
				break;
			case 'X': // unsigne hexademical integer(uppercase)
				n = va_arg(list, unsigned char);
				printf("[%X]", n);
				i++;
				break;
			case 'c': // character
				c = va_arg(list, char);
				printf("[%c]", c);
				i++;
				break;
			case 'u': // usigned decimal integer
				n = va_arg(list, unsigned int);
				printf("[%u]", n);
				i++;
				break;
			case 'o': // unsigned octal
				n = va_arg(list, unsigned int);
				printf("[%o]", n);
				i++;
				break;
			case 'f': // decimal floating point, lowercase
			case 'F': // decimal floating point, uppercase
				f = va_arg(list, double);
				printf("[%f]", f);
				i++;
				break;
			case 's': // string of characters
				s = va_arg(list, char*);
				printf("[%s]", s);
				i++;
				break;
			//... etc
			}
			break;
		default: // put a character
			printf("%c", format[i]);
			break;
		} // eof switch
	} // eof for
	va_end(list);
	return;
}// eof func format
