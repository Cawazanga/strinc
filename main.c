/*
 * File for tests library
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stringc {
    char *data;
    size_t size;
} stringc;

void cpString(stringc str1, stringc *str2);
stringc nString(const char* str);
const char* cString(stringc str);
stringc nnString(const char* str, size_t size);


stringc nString(const char* str) {
    stringc returnstr;
    returnstr.size = strlen(str);
    returnstr.data = malloc(returnstr.size);
    strcpy(returnstr.data, str);
    return returnstr;
}

stringc nnString(const char* str, size_t size) { 
    stringc returnstr;
    returnstr.size = size;
    returnstr.data = malloc(returnstr.size);
    strcpy(returnstr.data, str);
    return returnstr;
}

const char* cString(stringc str) {
//    stringc nst = nnString(str.data, str.size+2);
//    nst.data[str.size] = '\0';
    return str.data;
}
void cpString(stringc str1, stringc *str2) {
    str2->size = str1.size;
    strcpy(str2->data, str1.data);
}
int main(void) {
    stringc MyStr;
    MyStr = nString("Hello, world");
    printf("%s\n", cString(MyStr));
    return 0;
}
