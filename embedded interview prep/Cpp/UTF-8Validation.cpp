/**
 * @file UTF-8Validation.cpp
 * @brief Validate whether an integer array encodes a legal UTF-8 byte sequence.
 *
 * UTF-8 uses the following leading-byte patterns:
 * - 1 byte: 0xxxxxxx
 * - 2 bytes: 110xxxxx 10xxxxxx
 * - 3 bytes: 1110xxxx 10xxxxxx 10xxxxxx
 * - 4 bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 * @author Mervin Nguyen
 * @date 2026-05-23
 * @version 1.0.0
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Determine whether the provided bytes form a valid UTF-8 encoding.
 *
 * @param data Sequence of integer byte values.
 * @return true if the sequence is valid UTF-8, otherwise false.
 */
bool valid_utf8(const vector<int> &data) {
    int num_bytes = 0;

    for (int byte : data) {
        if (num_bytes == 0) {
            if ((byte >> 5) == 0b110) {
                num_bytes = 1;
            } else if ((byte >> 4) == 0b1110) {
                num_bytes = 2;
            } else if ((byte >> 3) == 0b11110) {
                num_bytes = 3;
            } else if ((byte >> 7) != 0) {
                return false;
            }
        } else {
            if ((byte >> 6) != 0b10) {
                return false;
            }
            num_bytes--;
        }
    }

    return num_bytes == 0;
}

 int main(void) {
    struct Test {
        vector<int> in;
        bool expect;
    };

    vector<Test> tests = {
        {{197, 130, 1}, true},
        {{235, 140, 4}, false},
        {{0}, true},
        {{255}, false},
        {{240, 162, 138, 147}, true},
    };

    for (auto &t : tests) {
        bool out = valid_utf8(t.in);
        cout << "Input: [";
        for (size_t i = 0; i < t.in.size(); i++) {
            cout << t.in[i] << (i + 1 < t.in.size() ? ", " : "");
        }
        cout << "] -> " << (out ? "true" : "false")
             << " (expected " << (t.expect ? "true" : "false") << ")"
             << (out == t.expect ? " PASS" : " FAIL") << '\n';
    }

    return 0;
 }