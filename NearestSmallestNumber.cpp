#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> prevsmaller(vector<int>& A) {
    vector<int> sol(A.size(), -1);
    stack<int> st;
    
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        sol[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    
    return sol;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> result = prevsmaller(A);
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
