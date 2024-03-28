#include <iostream>
#include <vector>

bool isMatch(std::string s, std::string p) {
    int m = s.size();
    int n = p.size();
    
    // Create a 2D dp array to store matching results
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    
    // Empty string and pattern matches
    dp[0][0] = true;
    
    // Handle patterns like "a*b*" where '*' matches zero or more of the preceding element
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }
    
    // Dynamic programming to fill the dp array
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // '*' matches zero or more of the preceding element
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    std::string s = "adceb";
    std::string p = "*a*b";
    
    if (isMatch(s, p)) {
        std::cout << "String matches the pattern." << std::endl;
    } else {
        std::cout << "String does not match the pattern." << std::endl;
    }
    
    return 0;
}

