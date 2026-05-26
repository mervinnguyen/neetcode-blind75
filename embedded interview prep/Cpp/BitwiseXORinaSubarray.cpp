/**
 * @file BitwiseXORinaSubarray.cpp
 * @brief Compute XOR of subarrays for given queries using prefix-XOR technique.
 *
 * Example:
 *  arr = {1,3,4,8}
 *  queries = {{0,1},{1,2},{0,3}}
 *  output = {2,7,14}
 *
 * Complexity: O(n + q) time, O(n) extra space.
 *
 * Author: Mervin Nguyen
 * Date: 2026-05-26
 */

 #include <iostream>
 #include <vector>
 #include <bits/stdc++.h>

 using namespace std;

/**
 * @brief Answer XOR queries over inclusive subarray ranges.
 *
 * @param arr Input array of integers
 * @param queries Vector of queries; each query must be a 2-element vector {l, r}
 * @return Vector of XOR results, one per query
 *
 * Uses prefix XORs where pref[i] = arr[0] ^ ... ^ arr[i-1].
 * The XOR of range [l, r] is pref[r+1] ^ pref[l].
 */
vector<int> xor_queries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] ^ arr[i];
    }
    vector<int> ans;
    ans.reserve(queries.size());
    for(const auto &q : queries) {
        int l = q[0], r = q[1];
        ans.push_back(pref[r + 1] ^ pref[l]);
    }
    return ans;
 }
 
int main(void) {
   vector<int> arr1 = {1, 3, 4, 8};
   vector<vector<int>> q1 = {{0,1}, {1,2}, {0,3}};
   auto r1 = xor_queries(arr1, q1);
   cout << "Example 1: ";
   for (int v : r1) cout << v << ' ';
   cout << '\n';

   vector<int> arr2 = {4, 8, 2, 10};
   vector<vector<int>> q2 = {{2,3}, {1,3}};
   auto r2 = xor_queries(arr2, q2);
   cout << "Example 2: ";
   for (int v : r2) cout << v << ' ';
   cout << '\n';

   return 0;
}