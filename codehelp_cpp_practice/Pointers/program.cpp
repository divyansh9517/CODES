#include <stdio.h>
int main() {
char str1[6] = "Hello";
char str2[6] = "World";
str1[0] = 'h';
str2[0] = 'w';
printf("%s %s", str1, str2);
return 0;
}
