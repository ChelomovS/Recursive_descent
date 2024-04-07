#include <stdio.h>
#include "recursive_descent.h"
#include "fileLib.h"

int main(const int argc, const char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "TOO FEW FILES \n");
        return 0;
    }

    FILE* filein = fopen(argv[1], "r");
    size_t file_size = GetFileSize(filein);

    char buffer[100] = "";

    fread(buffer, sizeof(char), file_size, filein);
    printf("Buffer: %s \n", buffer);
    
    printf("Result: %.3lf \n", recursive_descent(buffer));

    return 0;
}