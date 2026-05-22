/**
 * @file memCopy2.c
 * @brief Implements a simple memory copy function
 * @author Mervin Nguyen
 * @date 2026-05-07
 * @version 1.0.0
 */

 #include <stdio.h>
 #include <stddef.h>

 void *mem_copy(const char *src, void *dest, size_t n) {
    const unsigned char *s = (const unsigned char*)src;
    unsigned char *d = (unsigned char*)dest;
    for(size_t i = 0; i < n; i++) {
        *d = *s;
        s++;
        d++;
    }
 }

 int main(void) {
    char src[10] = "ABCDEFGHI";
    char dest[10];
    mem_copy(src, dest, sizeof(src));
    printf("The resulting destination array is %s \n", dest);
    return 0;
 }