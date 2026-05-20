/**
 * @file NumberComplement.cpp
 * @brief Given a positive integer, return its complement by flipping all bits in its binary representation.
 * @author Mervin Nguyen
 * @date 2026-05-20
 * @version 1.0.0
 */ 

 /*
 Example 1:
 Input : num = 5
 Output: 2
 Explanation: 5 in binary is 101, its complement is 010 = 2.
 */

 /*
 Example 2:
 Input : num = 1
 Output : 0
 Explanation : 1 in binary is 1, its complement is 0.
 */

 /*
 Approach:
    1) Convert the integer to a binary number
    2) Convert binary number to a string
    3) Iterate using a for loop starting from the first index, flip each bit using NOT mask (~)
    4) Convert the resulting string -> binary -> int
 */
 #include <iostream>
 #include <vector>

 using namespace std;

 int number_complement(int num) {
   if (num == 0) return 1;
   int mask = 1;
   while (mask < num) {
      mask = (mask << 1) | 1;
   }
   return num ^ mask;
 }

 int main(void) {
   struct Test { int in; int expect; };
   vector<Test> tests = { {5, 2}, {1, 0}, {10, 5} };
   for (auto &t : tests) {
      int out = number_complement(t.in);
      cout << "Input: " << t.in << " -> Output: " << out << " (expected " << t.expect << ")\n";
   }
   return 0;
}