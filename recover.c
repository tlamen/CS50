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
    FILE *file = fopen(argv[1], "r");
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

    //set auxiliar variable and start do-while loop
    bool aux = true;
    do
    {
        //break if it reaches end of file
        if (feof(file))
        {
            break;
        }

        //first read if counter == 0
        if (counter == 0)
        {
            fread(block, 512, 1, file);
        }

        //check if block is the start of a jpeg file
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] > 0xdf & block [3] < 0xf0))
        {
            //name and number the picture file
            char name[7];
            if (counter < 10)
            {
                sprintf(name, "00%i.jpg", counter);
            }
            else
            {
                sprintf(name, "0%i.jpg", counter);
            }

            //write file and counter++
            FILE *picture = fopen(name, "w");
            fwrite(&block, 512, 1, picture);
            counter++;

            //prepare for while loop
            fread(block, 512, 1, file);
            bool aux2 = true;

            while (aux2)
            {
                //check if block starts a new jpeg file
                if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] > 0xdf & block [3] < 0xf0))
                {
                    fclose(picture);
                    aux2 = false;
                }
                //write block into current file
                else
                {
                    fwrite(&block, 512, 1, picture);
                    fread(block, 512, 1, file);
                }
                if (feof(file))
                {
                    aux2 = false;
                }
            }
        }
        //make certain that aux is true so do-while loop continues
        aux = true;
    }
    while (aux);
}
