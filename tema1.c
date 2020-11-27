#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int write_stdout(const char *token, int length) {
	int rc;
	int bytes_written = 0;
	do {
		rc = write(1, token + bytes_written, length - bytes_written);
		if (rc < 0)
			return rc;

		bytes_written += rc;
	} while (bytes_written < length);

	return bytes_written;
}


/*  my_itoa function transform int to String */
char* my_itoa(char *output_buff, int num){
    long long number = num;
    int position = 0;
    if(number < 0){
        output_buff[position++] = '-';
        number *= -1;
    } else if(number == 0)
        output_buff[position++] = '0';
    long long aux = number, h = 1;
    while(aux) {
        h *= 10;
        aux /= 10;
    }
    h /= 10;
    while(h) {
        output_buff[position++] = number / h % 10 + '0';
        h /= 10;
    }
    output_buff[position]='\0';
    return output_buff;
}



/* Transform unsiged int to String */
char *UnitTrans(unsigned int num){
      char *unit_decimal = (char *)malloc(100 * sizeof(char));
      char *unitde = (char *)malloc(100 * sizeof(char));
      int a = 100;
      int b = 0;
      do{
            unit_decimal[--a] = num % 10 + '0';
            num /= 10;
      }while(num != 0);
      int i;
      for ( i = a; i <= 99; i++)
          unitde[b++] = unit_decimal[i];
      unitde[b] = '\0';
      return unitde;
}


/* Transform Decemal in Hexa */
char *hexadecemal(unsigned int num) {
    long int  quotient ;
    int   var ;
    char *hexanum_decimal = (char *)malloc(100 * sizeof(char));
    char *hexanum = (char *)malloc(100 * sizeof(char));
    quotient = num ;
    int a = 100;
    int b = 0;
    while( quotient != 0 ) {
        var = quotient % 16 ;
        if( var < 10 )
            var +=  '0' ;
        else
            var += 'a'- 10 ;

        hexanum_decimal[ --a]= var ;
        quotient = quotient / 16;
    }
    int i;
    for (i = a; i <= 99; i++)
        hexanum[b++] = hexanum_decimal[i];

    hexanum[b] = '\0';
    return hexanum;
}

/* Function help Iocla_print to print int */
int printInt(int n) {
	char* str = (char*)malloc(100 * sizeof(char));
	str =  my_itoa(str, n);
	int length = strlen(str);
    	write_stdout(str , length);
    	return length;
}

/* Function help Iocla_print to print  unsigned int */
int printUint(unsigned int n) {
	char* str = (char*)malloc(100 * sizeof(char));
	str =  UnitTrans(n);
	int length = strlen(str);
    write_stdout(str , length);
    return length;
}

/* Function help Iocla_print to print Hexadecemal */
int printHexa(unsigned int n) {
    char *hexa = hexadecemal(n);
    int len = strlen(hexa);
    write_stdout(hexa, len);
    return len;
}


int iocla_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int index = 0; 
    int maxLen = 0;
    int i = 0;
    char* buffer = (char*)calloc(1,strlen(format));
    while ( i < strlen(format)) {
        if (format[i] != '%') {
                buffer[index] = format[i];
                index++;
        } 
        else {
                ++i;
                char info = format[i];
                int len;
                write_stdout(buffer, index);

                if(info == 'u') {
                     len = printUint(va_arg(args, unsigned int));
                }
                else if(info == 'd') {
                     len = printInt(va_arg(args, int));
                } 
                else if(info == 'c') {
                    char c = (char)va_arg(args, int);
                    char str[2];
                    str[0] = c;
                    str[1] = '\0';
                    len =   write_stdout(str, 1);
                }
                else if(info == 's') {
                    char *string = va_arg(args, char*);
                    len = write_stdout(string, strlen(string));
                }
                else if(info == 'x') {
                     len = printHexa(va_arg(args, unsigned int));
                 }
                else if(info == '%') {
                    char c = '%';
                    char str[2];
                    str[0] = c;
                    str[1] = '\0';
                    len =   write_stdout(str, 1);
                }
                 maxLen =  maxLen + index;
                 maxLen =  maxLen +  len;
                 index = 0;
        }
        i++;
    }
    maxLen =  maxLen + index;
    write_stdout(buffer, index);
    free(buffer);
    return maxLen;
}

int main(void){
    iocla_printf("%u ", -10);
    return 0;
}