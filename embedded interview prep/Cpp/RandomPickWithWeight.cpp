/**
 * @file RandomPickWithWeight.cpp
 * @brief Given an array of positive integer w, implement pickIndex() that randomly picks an index in proportion to its weight.
 * @author Mervin Nguyen
 * @date 2026-05-27
 * @version 1.0.0
 */

 #include <iostream>
 #include <vector>
 #include <random>
 #include <algorithm>
 #include <numeric>

using namespace std;

// Global prefix sums and RNG for pick_index()
static vector<long long> pref;
static long long total = 0;
static mt19937 rng(random_device{}());

/**
 * @brief Pick an index in proportion to previously-initialized weights.
 *
 * Precondition: `pref` must contain cumulative sums where pref[i]
 * is the sum of weights up to and including index i.
 *
 * @return chosen index in range [0, pref.size()-1]
 */
int pick_index() {
        if (pref.empty()) return -1;
        uniform_int_distribution<long long> dist(1, total);
        long long target = dist(rng);
        auto it = lower_bound(pref.begin(), pref.end(), target);
        return static_cast<int>(it - pref.begin());
}

int main(void) {
        // Example 1: w = {1,3} -> index 0 with prob ~0.25, index 1 with prob ~0.75
        vector<int> w = {1, 3};
        pref.clear(); total = 0;
        for (int x : w) {
                total += x;
                pref.push_back(total);
        }
        const int TRIALS = 20000;
        vector<int> counts(w.size(), 0);
        for (int i = 0; i < TRIALS; ++i) {
                int idx = pick_index();
                if (idx >= 0) ++counts[idx];
        }
        cout << "Weights: ";
        for (int x : w) cout << x << ' ';
        cout << '\n';
        cout << "Counts after " << TRIALS << " trials:\n";
        for (size_t i = 0; i < counts.size(); ++i) {
                cout << "index " << i << ": " << counts[i]
                         << " (" << (100.0 * counts[i] / TRIALS) << "%)\n";
        }
        return 0;
}
