/**
 * @file ConvertANumbertoHexadecimal.c
 * @brief Given a 32-bit integer "num", return a string representing its hexadecimal representation. For negative integers, two's complement method is used.
          All the letters in the answer string should be lowercase characters, and there should not be any leading zeros int eh answer except for the zero itself.

          Note: You are not allowed to use any built-in libary method to directly solve this problem.
 * @author Mervin Nguyen
 * @date 2026-05-19
 * @version 1.0.0
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string>

 using namespace std;

 /**
  * @brief Converts a 32-bit integer to its lowercase hexadecimal string representation.
  *        Negative values are handled via two's complement (cast to unsigned int).
  * @param num The integer to convert.
  * @return A string containing the hex representation with no leading zeros (except "0" itself).
  */
 string to_hex(int num) {
    if (num == 0) return "0";

    const char hex[] = "0123456789abcdef";
    unsigned int n = (unsigned int)num;  // two's complement handled automatically
    char buf[9];
    int i = 0;

    while (n) {
        buf[i++] = hex[n & 0xF];
        n >>= 4;
    }
    buf[i] = '\0';

    for (int l = 0, r = i - 1; l < r; l++, r--) {
        char tmp = buf[l]; buf[l] = buf[r]; buf[r] = tmp;
    }

    return string(buf);
 }

 int main(void) {
    printf("%s\n", to_hex(26).c_str());   // "1a"
    printf("%s\n", to_hex(-1).c_str());   // "ffffffff"
    printf("%s\n", to_hex(0).c_str());    // "0"
    return 0;
 }