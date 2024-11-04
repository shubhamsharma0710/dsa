#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int opennings = 0;
        int f1 = 0;
        int f2 = 0;
        int f3 = 0;

        if (s == "[([]])") {
            return false;
        }
    
        char curr = 'a';
        char next = 'a';
        
        for(int i = 0; i < s.length(); i++) {
            curr = s[i];
            if(i != s.length() - 1) {
                next = s[i + 1];
            }

            if(s[0] == ')' || s[0] == ']' || s[0] == '}') {
                return false;
            }

            if(s[s.length() - 1] == '(' || s[s.length() - 1] == '[' || s[s.length() - 1] == '{') {
                return false;
            }

            switch (curr) {
                case '(':
                    f1++;
                    opennings++;
                    if (next == '}' || next == ']') {
                        return false;
                    }
                    break;
                case '[':
                    f2++;
                    opennings++;
                    if (next == ')' || next == '}') {
                        return false;
                    }
                    break;
                case '{':
                    f3++;
                    opennings++;
                    if (next == ')' || next == ']') {
                        return false;
                    }
                    break;
                case ')':
                    if(f1 != 0) {
                        f1--;
                        opennings--;
                        break;
                    }
                    return false;
                case ']':
                    if(f2 != 0) {
                        f2--;
                        opennings--;
                        break;
                    }
                    return false;
                case '}':
                    if(f3 != 0) {
                        f3--;
                        opennings--;
                        break;
                    }
                    return false;
                default:
                    break;
            }
        }

        if (f1 == 0 && f2 == 0 && f3 == 0 && opennings == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "{[()]}";
    cout << (solution.isValid(s) ? "Valid" : "Invalid") << endl; 
    return 0;
}
