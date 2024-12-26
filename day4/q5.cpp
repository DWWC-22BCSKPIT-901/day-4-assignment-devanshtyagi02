#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::gcd

using namespace std;

vector<int> gcdPairs(const vector<int>& nums, const vector<int>& queries) {
    vector<int> gcdPairs;

    int n = nums.size();
    // Generate all unique GCD pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            gcdPairs.push_back(gcdPairs(nums[i], nums[j]));
        }
    }

    // Sort the GCD pairs
    sort(gcdPairs.begin(), gcdPairs.end());

    vector<int> result;
    for (int query : queries) {
        if (query < gcdPairs.size()) {
            result.push_back(gcdPairs[query]);
        } else {
            result.push_back(-1); // Return -1 for out-of-bounds queries
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {2, 3, 4};
    vector<int> queries1 = {0, 2, 2};
    vector<int> result1 = gcdPairs(nums1, queries1);

    cout << "Result for Test Case 1: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> nums2 = {4, 4, 2, 1};
    vector<int> queries2 = {5, 3, 1, 0};
    vector<int> result2 = gcdPairs(nums2, queries2);

    cout << "Result for Test Case 2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
