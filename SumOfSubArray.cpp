#include <vector>
#include <stack>
#include <iostream>

using namespace std;

using ll = long long;
const int MOD = 1e9+7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> st;

        for (int i = 0; i < length; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        for (int i = length - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        ll sum = 0;
        for (int i = 0; i < length; i++) {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    int result = sol.sumSubarrayMins(arr);
    cout << "Output: " << result << endl;  
    return 0;
}
