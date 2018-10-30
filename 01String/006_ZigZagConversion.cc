#include <iostream>
using namespace std;

int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    string convert(string s, int numRows) {
        string a[numRows];
        string ans;
        int len = s.length(); int i = 0, flag = 1, count = 0;
        int num = numRows - 1; bool b = (num > 0);
        if(!b) return s;
        while( count < len){
            a[i] += s[count];
            if(i % num == 0 && count != 0)
                flag = -flag;
            ++count;
            i += flag;
        }
        for(int j = 0; j < numRows; j++)
            ans += a[j];
        return ans;
    }
};

int main(){
    Solution a;
    cout << a.convert("PAYPALISHIRING", 3) << endl;
    cout << a.convert("PAYPALISHIRING", 4) << endl;
}