#include <stio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // Initialize the character count

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            count++;
        } else {
            format++; // Move past the '%'
            if (*format == 'c') {
                // Handle the 'c' specifier
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                // Handle the 's' specifier
                char *s = va_arg(args, char *);
                while (*s) {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                // Handle the '%%' specifier
                putchar('%');
                count++;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    char str[] = "Hello, World!";
    int count = _printf("Printing a character: %c\n", 'A');
    count += _printf("Printing a string: %s\n", str);
    count += _printf("Printing a percent sign: %%\n");
    printf("Total characters printed: %d\n", count);
    return 0;
}
