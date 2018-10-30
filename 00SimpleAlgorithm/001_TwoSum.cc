#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> Map;
        for(int i = 0; i < nums.size(); i++){
            if(Map.count(target - nums[i]) > 0)
                return vector<int>(2) = { Map[target - nums[i]] , i};
            Map[nums[i]] = i;
        }
        throw ("Not found exception");
    }
};