#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << spanner.next(price) << " ";
    }
    cout << endl; 
    return 0;
}
