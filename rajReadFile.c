#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool readTxtFile(const char* fileName, char** out)
{
    *out = NULL;

    FILE *file = fopen(fileName, "rt");

    if (file == NULL) return false;

    fseek(file, 0, SEEK_END);
    unsigned int size = (unsigned int)ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size <= 0) return false;
    

    *out = (char *)malloc((size + 1)*sizeof(char));
    unsigned int count = (unsigned int)fread(*out, sizeof(char), size, file);

    // WARNING: \r\n is converted to \n on reading, so,
    // read bytes count gets reduced by the number of lines
    if (count < size) *out = realloc(*out, count + 1);

    // Zero-terminate the string
    (*out)[count] = '\0';

    return true;
}

bool readBinFile(const char* fileName,  unsigned char** out)
{
    *out = NULL;


    if(fileName == NULL) return false;

    FILE *file = fopen(fileName, "rb");

    if (file == NULL) return false;

    // WARNING: On binary streams SEEK_END could not be found,
    // using fseek() and ftell() could not work in some (rare) cases
    fseek(file, 0, SEEK_END);
    unsigned int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size <= 0) return false;
    
    *out = (unsigned char *)malloc(size*sizeof(unsigned char));

    // NOTE: fread() returns number of read elements instead of bytes, so we read [1 byte, size elements]
    unsigned int count = (unsigned int)fread(*out, sizeof(unsigned char), size, file);

    if (count != size) return false; 

    fclose(file);

    return true;
}
