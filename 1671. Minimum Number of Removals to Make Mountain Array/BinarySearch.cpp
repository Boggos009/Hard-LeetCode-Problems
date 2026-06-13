#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> DPRIGHT(n), DPLEFT(n);
        vector<int> temp;

        for(int i = 0; i < n; i++){
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);

            int pos = it - temp.begin();

            if(it == temp.end()){
                temp.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }

            DPRIGHT[i] = pos + 1;
        }

        temp.clear();

        for(int i = n - 1; i >= 0; i--){
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);

            int pos = it - temp.begin();

            if(it == temp.end()){
                temp.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }

            DPLEFT[i] = pos + 1;
        }

        int maxMountain = 0;

        for(int i = 0; i < n; i++){
            if(DPRIGHT[i] > 1 && DPLEFT[i] > 1){
                maxMountain = max(maxMountain,DPRIGHT[i] + DPLEFT[i] - 1);
            }
        }

        return n - maxMountain;
    }
};