#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //checking errors
    if (argc != 2)
    {
        printf("Usage: ./recover Image\n");
        return 1;
    }

    //opening file
    FILE* file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Couldn't read file\n");
        return 1;
    }

    // declaring a block of 8 bits of Type BYTE and having 512 blocks
    typedef uint8_t BYTE;
    BYTE block[512];

    //counter
    int counter = 0;

    bool aux = true;
    while (aux)
    {
        //break if it reaches end of file
        if (feof(file))
        {
            break;
        }

        if (counter == 0)
        {
            fread(block, 512, 1, file);
        }

        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] > 0xdf & block [3] < 0xf0))
        {

            char name[7];
            sprintf(name, "00%i.jpg", counter);

            FILE* picture = fopen(name, "w");
            fwrite(&block, 512, 1, picture);
            counter++;

            fread(block, 512, 1, file);
            bool aux2 = true;

            while (aux2)
            {
                if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] > 0xdf & block [3] < 0xf0))
                {
                    fclose(picture);
                    break;
                }
                else
                {
                    fwrite(&block, 512, 1, picture);
                    fread(block, 512, 1, file);
                }
                if (feof(file))
                {
                    break;
                }
            }
        }
    }
}
