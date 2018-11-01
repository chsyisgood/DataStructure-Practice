#include <iostream>
#include <sstream>
using namespace std;
/*
    0 ms 100.0%
    LC 50 power(x, n) x is double from -100 to 100
    n is integer from INT32_MIN to INT32_MAX

    学习：
    1. 【界定】边界条件，通过所有的test cases !!!
    2. 防止【overflow】，需要其他类型的【int -> long】，学习如何自主【选择】 test cases

    算法：简单
    1. 算法就是改编自power(x,n)，复杂度是 O(logN)

    重点：
    1. 先判断 n 是否超出边界，是则直接return；当n为负数时，做出相应的变化 -> 变成正数的情况
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