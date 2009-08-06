/*
* endianness - print the processor's endianness.
* Copyright (C) 2009 Will Harris
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
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
