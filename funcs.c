#include <stdio.h>
#include <inttypes.h>

#define WORD uint32_t
#define PF PRIX32

WORD Ch(WORD x, WORD y, WORD z)
{
    return (x & y) ^ (~x & z);
}

WORD Maj(WORD x, WORD y, WORD z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

WORD shr(WORD x, WORD n)
{
    return (x >> n);
}

WORD rotr(WORD x, WORD n)
{
    return (x >> n) | (x << 32 - n);
}

WORD sigmaUpper0(WORD x)
{
    return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

WORD sigmaUpper1(WORD x)
{
    return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

WORD sigmaLower0(WORD x)
{
    return (rotr(x, 7) ^ rotr(x, 18) ^ rotr(x, 3));
}

WORD sigmaLower1(WORD x)
{
    return (rotr(x, 17) ^ rotr(x, 19) ^ rotr(x, 10));
}

int main(int argc, char *argv[])
{
    WORD x = 0x0F0F0F0F;
    WORD y = 0x0A0A0A0A;
    WORD z = 0xB0B0B0B0;

    WORD ans = Ch(x, y, z);

    printf("Ch(%08" PF ", %08" PF ", %08" PF ") = %08" PF "\n", x, y, z, ans);
    printf("%" PRIX32 "\n", shr(x, 10));
    printf("%" PRIX32 "\n", rotr(x, 10));
    printf("%" PRIX32 "\n", sigmaUpper0(x));
    printf("%" PRIX32 "\n", sigmaUpper1(x));
    printf("%" PRIX32 "\n", sigmaLower0(x));
    printf("%" PRIX32 "\n", sigmaLower1(x));

    return 0;
}
