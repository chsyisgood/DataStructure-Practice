#include <iostream>
#include <cstring>
using namespace std;

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
    string stack = "0"; int count = 0; int len = s.length();
    for(int i = 0; i < len; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            switch(s[i]){
                case '(': {stack += ')'; ++count; break; }
                case '{': {stack += '}'; ++count; break; }
                case '[': {stack += ']'; ++count; break; }
            }
        }
        else{
            if(count > 0 && s[i] == stack[count]){
                --count;
                stack.pop_back();
                if(count == 0) stack = "0";
            }
            else
                return false;
        }
    }
    return (count == 0)? true: false;
    }
};

int main(){
    Solution sol;
    cout << sol.isValid("") << endl;
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("(([]){})") << endl;
}