//use circular array{arr[]={1,2,3,4} then for NGE array become {1,2,3,4,1,2,3,4}  }
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        stack<int> st;
        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                if(st.empty()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push(nums[i % n]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1};
    vector<int> result = solution.nextGreaterElements(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
