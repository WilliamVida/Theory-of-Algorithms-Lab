#include <stdio.h>

void bin_print(int i)
{
    // Number of bits in an integer.
    int j = sizeof(int) * 8;

    // Temporary variable.
    int k;

    // Loop over the number of bits in i.
    for (j--; j >= 0; j--)
    {
        //
        k = ((1 << j) & i) ? 1 : 0;
        // Print k.
        printf("%d", k);
    }
}

// Standard main signature.
int main(int argc, char *argv[])
{
    // int i = 0xF1; // 11110001

    // printf("Dec: %d\n", i);
    // printf("Hex: %X\n", i);

    // printf("Size of i: %d\n", sizeof(i));
    // printf("Size of int: %d\n", sizeof(int));
    // printf("Size of char: %d\n", sizeof(char));

    // char c = 41;
    // printf("c in char is: %c\n", c);
    // printf("c in int is: %d\n", c);

    // int j = 1000000000;
    // printf("j in int is: %d\n", j);
    // printf("j in char is: %c\n", (char)j);
    // printf("j in int from char is: %d\n", (int)(char)j);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("1");
    // }

    // printf("\n");

    // Set i to a literal value.
    int i = 0xf1; // 0xf1; // 241

    // Whate we're printing.
    printf("Original:  ");
    // Print i in binary.
    bin_print(i);
    // End line.
    printf("\n");

    for (int j = 0; j < 40; j++)
    {
        // What the operation is.
        printf("%3d << %2d: ", i, j);
        bin_print(i << j);
        printf("\n");
    }

    // Everything is okay.
    return 0;
}
