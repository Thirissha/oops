#include <iostream>
#include <unordered_map>

std::string minWindow(std::string s, std::string p) {
    if (s.empty() || p.empty() || s.length() < p.length()) {
        return "";
    }

    std::unordered_map<char, int> target, window;
    for (char c : p) {
        target[c]++;
    }

    int required = target.size();
    int formed = 0;
    int left = 0, right = 0;
    int minLen = INT_MAX;
    int minLeft = 0;

    while (right < s.length()) {
        char c = s[right];
        window[c]++;

        if (target.count(c) && window[c] == target[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }

            char leftChar = s[left];
            window[leftChar]--;
            if (target.count(leftChar) && window[leftChar] < target[leftChar]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string p = "ABC";

    std::string result = minWindow(s, p);
    if (!result.empty()) {
        std::cout << "Shortest substring containing all characters of p: " << result << std::endl;
    } else {
        std::cout << "No such substring exists." << std::endl;
    }

    return 0;
}
