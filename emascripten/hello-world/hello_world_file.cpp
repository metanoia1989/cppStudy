#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file = fopen("hello_world_file.txt", "rb"); 
    if (!file) 
    {
        printf("cannot open file\n");
        return 1;
    }    
    
    while (!feof(file))
    {
        char c= fgetc(file);     
        if (c != EOF)
        {
            putchar(c);
        }
    }
    
    fclose(file);

    return 0;
}
