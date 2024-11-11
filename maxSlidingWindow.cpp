#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int i = 0 , j = 0 ;
       priority_queue<pair<int,int>> q;
       vector<int> ans;

       while(j < nums.size()){
           q.push({nums[j], j});
           
           if(j - i + 1 < k) {
               j++;
           }
           else if(j - i + 1 == k && !q.empty()) {
               while(!q.empty() && j - q.top().second + 1 > k){
                   q.pop();
               }
               ans.push_back(q.top().first);
               j++;
               i++;
           }
       } 
       return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Output: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl; 

    return 0;
}
