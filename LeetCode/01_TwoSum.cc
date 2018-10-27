#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> HashMap;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++)
            HashMap.insert(i, nums[i]);
        for(int i = 0; i < nums.size(); i++)
            if(HashMap.find(target - nums[i]) != HashMap.end()){
                for(std::unordered_map<int, int>::iterator it = HashMap.begin();it != HashMap.end(); it++){
                    cout << it->first << " ";
                }
            }
        return ans;
    }
};



int main(){
    vector<int> nums = {1, 3, 5, 7, 2, 4, 6, 8, 12, 15};
    int target = 12;
    Solution a;
    a.twoSum(nums,target);
}

