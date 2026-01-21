#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
char buffer[80];
do {
printf( "Please enter your login: " );
scanf( "%s", buffer);
} while( strcmp( buffer, "james") != 0 );
printf( "Hello Mr Bond\n" );
return 0;
}