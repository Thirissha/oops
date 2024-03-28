#include <iostream>
#include <stack>

int longestValidParentheses(std::string s) {
    int maxLen = 0;
    std::stack<int> stk;
    stk.push(-1); // Push -1 to mark the start of the string

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stk.push(i);
        } else { // s[i] == ')'
            stk.pop();
            if (!stk.empty()) {
                maxLen = std::max(maxLen, i - stk.top());
            } else {
                stk.push(i); // Push the current index to mark the end of the invalid substring
            }
        }
    }

    return maxLen;
}

int main() {
    std::string s = "(()())";
    std::cout << "Length of the longest valid parentheses substring: " << longestValidParentheses(s) << std::endl;
    return 0;
}
