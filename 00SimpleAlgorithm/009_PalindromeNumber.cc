#include <iostream>
#include <sstream>
using namespace std;
/*
    0 ms 100.0%
    LC 50 power(x, n) x is double from -100 to 100
    n is integer from INT32_MIN to INT32_MAX
    重点：
        【界定】边界条件，通过所有的test cases !!!
        防止【overflow】，需要其他类型的【int -> long】
        学习如何自主【选择】 test cases
        数据类型会影响速度，例如用long时为0 ms，用long long 为 4ms
    难度：简单
*/

int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    bool isPalindrome(int x) {
        stringstream s;
        s << x;
        string str = s.str();
        int left = 0, right = str.length() - 1;
        while (right > left){
            if(str[left] == str[right]){
                ++left, --right;
            }
            else
                return false;
        }
        return true;
    }
};

int main(){
    Solution a;
    cout << a.isPalindrome(121) << '\n';
    cout << a.isPalindrome(-121) << '\n';
    cout << a.isPalindrome(10) << '\n';
}