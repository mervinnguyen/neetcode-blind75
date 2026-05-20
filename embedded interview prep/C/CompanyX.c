/**
 * @file CompanyX.c
 * @brief Find the first non-repeating character in a string.
 *
 * This small utility demonstrates a simple algorithm to locate the first
 * character in a C-string that does not repeat elsewhere in the string.
 *
 * Example: input "embedded" -> returns index 2 ('m').
 */

#include <stddef.h>
#include <stdio.h>
#include <limits.h>

/**
 * @brief Find the index of the first unique character in a string.
 *
 * Scans the provided null-terminated string and returns the zero-based index
 * of the first character that appears only once. The function treats the
 * input as a sequence of bytes and uses a frequency table indexed by byte
 * value.
 *
 * @param string Pointer to a null-terminated input string. If NULL, the
 *               function returns -1.
 * @return Index of the first non-repeating character, or -1 if none found
 *         or if `string` is NULL.
 */
int first_unique_character(const char *string) {
    if (string == NULL) {
        return -1;
    }
    size_t count[UCHAR_MAX + 1] = {0};

    for (const unsigned char *p = (const unsigned char *)string; *p != '\0'; ++p) {
        const unsigned char c = *p;
        count[c]++;
    }

    for (const unsigned char *p = (const unsigned char *)string; *p != '\0'; ++p) {
        const unsigned char c = *p;
        if (count[c] == 1) {
            return (int)(p - (const unsigned char *)string);
        }
    }
    return -1;
}

int main(void) {
    const char *input = "embedded";
    int index = first_unique_character(input);

    if (index >= 0) {
        printf("The first unique character is '%c' at index %d\n", input[index], index);
    } else {
        printf("No unique character found.\n");
    }

    return 0;
}

