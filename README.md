# rajReadFile
C library to read all the contents of text file and binary file.
## Installation
1. download this source code.
2. open the terminal and go to directory where you downloaded.
3. run ``` sudo ./install.sh ```

## Usage
To read a text file
```c
// compile: gcc thisfile.c -lrajReadFile

#include <rajReadFile.h>
#include <stdbool.h>

int main()
{
 
 char* textData;

 bool isRead = readTxtFile("filename", &textData);

 if(isRead == false)
 {
  perror("");
  return 1;
 }

 //do something with readed data
}
```
To read binary file
```c
// compile: gcc thisfile.c -lrajReadFile

#include <rajReadFile.h>
#include <stdbool.h>

int main()
{
 
 unsigned char* binData;

 bool isRead = readTxtFile("filename", &binData);

 if(isRead == false)
 {
  perror("");
  return 1;
 }

 //do something with readed data
}
```