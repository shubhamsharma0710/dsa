#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int& x : asteroids) {
            res.push_back(x);
            int n = (int)res.size();
            while (!res.empty() && n >= 2 && (res[n - 1] < 0 && res[n - 2] > 0)) {
                int a = res[n - 1], b = res[n - 2];
                res.pop_back();
                res.pop_back();
                if (abs(a) != abs(b)) {
                    res.push_back((abs(a) > abs(b)) ? a : b);
                }
                n = (int)res.size();
            }
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = sol.asteroidCollision(asteroids);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
