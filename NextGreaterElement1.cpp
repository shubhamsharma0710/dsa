#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> son(n);
        
        for(int i = 0; i < n; i++) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            bool found = false;
            
            for(auto j = it + 1; j != nums2.end(); j++) {
                if(*j > nums1[i]) {
                    son[i] = *j;
                    found = true;
                    break;
                }
            }
            
            if(!found) {
                son[i] = -1;
            }
        }
        
        return son;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    cout << "Next Greater Elements: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
