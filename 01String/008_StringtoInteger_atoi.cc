#include <iostream>
using namespace std;

int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        bool is_positive = true;
        string::const_iterator it = str.begin();
        while( *it == ' '){
            ++ it;
        }
        if(*it == '+')
            ++ it;
        else if(*it == '-'){
            is_positive = false;
            ++ it;
        }
        else if( 47 < *it && *it < 58){
            ans = *it - 48;
            ++ it;
        }
        else
            return 0;
        while(it != str.end()){
            if( 47 < *it && *it < 58){
                ans = ans * 10 + *it - 48;
                if(is_positive && ans > INT_MAX)
                    return INT_MAX;
                if(!is_positive && ans > INT_MIN - 1)
                    return INT_MIN;
                ++ it;
            }
            else
                return (is_positive)? ans: -ans;
        }
        return (is_positive)? ans: -ans;
    }
};

int main(){
    Solution a;
    cout << a.myAtoi("42") << endl;
    cout << a.myAtoi("   -42") << endl;
    cout << a.myAtoi("4193 with words") << endl;
    cout << a.myAtoi("words and 987") << endl;
}