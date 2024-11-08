#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& arr) {
        int lmax=0, rmax=0, total=0, n=arr.size();
        int l=0, r=n-1;
        while(l<=r){ 
            if(arr[l]<=arr[r]){
                if(lmax>arr[l]){
                    total+=lmax-arr[l];
                } else{
                    lmax=arr[l];
                }
                l++;
            } else{
                if(rmax>arr[r]){
                    total+= rmax-arr[r];
                }else{
                    rmax=arr[r];
                }
                r--;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = sol.trap(arr);
    cout << "Output: " << result << endl; 
    return 0;
}
