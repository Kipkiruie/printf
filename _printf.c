#include "main.h"
/**
 * _printf receives the main string and all necessary parameters
 * to print formated output
 * @format: A string containing all necessary characters
 * Return: A total number of all printed chracters
 */
int _printf(const char *format, ...)
{int char_print =0;
	if (format == NULL)
                return (-1);
	 va_list arg_list;
	 va_start(list_of_args, format);
	 while(*format)
	 {
		 if (*format != '%')
		 
		{
		write(1, format, 1);
		chara_print++;
	       	}
		 else
		 {
			 format++;
			 if(*format == '\0')
				 break;
			 if (*format == '%')
			 {
			 write(1, format, 1);
			 chara_print++;
			 }
			 else if (*format == 'c')
			 {
			 char c = va_arg(list_of_args, int);
			 write(1, &c, 1);
			 chara_print++;
			 }
			 else if (*format == 's')
			 {
			 char *str = va_arg(list_of_args, char*);
			 int str_len = 0;
			 while(str[str_len] = '\0')
				 str_len++;
			 write(1, str, str_len);
			 chara_print += str_len;
			 }
		 }
		 format++;
	 }
	 va_end(list_of_args);
	 return chara_print;
}
	int main(){
		_printf("Elisha\n");
		_printf("%c\n", 'v');
		_printf("%s\n", "string")
		_printf("%%\n");
		return 0;
}
