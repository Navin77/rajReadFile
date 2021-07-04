#pragma once
#include <stdbool.h>

/**
 * use perror on failure to print err msg for eg: perror("")
 * @param fileName file to read
 * @param out pointer to char where readed contents are written
 * @return true on success, false on failure
 **/
bool readTxtFile(const char *fileName, char **out);

/**
 * use perror on failure to print err msg for eg: perror("")
 * @param fileName file to read
 * @param out it will have readed contents
 * @return true on success, false on failure
 **/
bool readBinFile(const char *fileName, unsigned char **out);