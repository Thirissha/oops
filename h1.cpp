#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    // Ensure nums1 is the smaller array
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int left = 0, right = m, halfLen = (m + n + 1) / 2;
    while (left <= right) {
        int i = (left + right) / 2;
        int j = halfLen - i;
        
        if (i < m && nums2[j - 1] > nums1[i]) {
            left = i + 1;
        } else if (i > 0 && nums1[i - 1] > nums2[j]) {
            right = i - 1;
        } else {
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
            }
            
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }
            
            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = std::min(nums1[i], nums2[j]);
            }
            
            return (maxLeft + minRight) / 2.0;
        }
    }
    
    return 0.0;
}

int main() {
    std::vector<int> num1 = {1, 3};
    std::vector<int> num2 = {2};
    
    double median = findMedianSortedArrays(num1, num2);
    
    std::cout << "Median: " << median << std::endl;
    
    return 0;
}
