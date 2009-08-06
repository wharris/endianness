#include <stdlib.h>
#include <stdio.h>

typedef enum {
    BIG,
    LITTLE
} endianness;

endianness
get_endianness()
{
    int* a;
    a = malloc(sizeof(int));
    *a = 1;
    endianness result;
    char first_byte = *(char*) a;
    if (first_byte == (*a) & 0xff) {
        result = LITTLE;
    } else {
        result = BIG;
    }
    
    free(a);
    return result;
}

int
main(void)
{
    switch (get_endianness()) {
    case BIG:
        return printf("Big\n");
    case LITTLE:
        return printf("Little\n");
    default:
        printf("Unknown");
        return 1;
    }
}
