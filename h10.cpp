#include <iostream>
#include <vector>

int trap(std::vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    std::vector<int> leftMax(n), rightMax(n);

    // Calculate the maximum height to the left of each bar
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], height[i]);
    }

    // Calculate the maximum height to the right of each bar
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], height[i]);
    }

    int waterTrapped = 0;

    // Calculate the amount of water trapped at each position
    for (int i = 0; i < n; ++i) {
        int minHeight = std::min(leftMax[i], rightMax[i]);
        waterTrapped += std::max(minHeight - height[i], 0);
    }

    return waterTrapped;
}

int main() {
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << "Amount of water trapped after raining: " << trap(height) << std::endl;
    return 0;
}
