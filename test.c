#include <stdio.h>
#include <stdlib.h>

char *ctoa(char c) {
    char *buffer = malloc(2);
    buffer[0] = c;
    buffer[1] = '\0';
    return buffer;
}
char atoc(const char *str) {
    if (str[0] == '\0') {
        fprintf(stderr, "Eroare la convertirea stringului '%s' intr-un caracter\n", str);
        return '\0';
    } else {
        return str[0];
    }
}

int main() {
    char c = 'a';
    char *str = ctoa(c);
    printf("Char convertit in string: %s\n", str);
    char carac = atoc(str);
   printf("Char convertit din string: %c\n", carac);
    
    return 0;
}

