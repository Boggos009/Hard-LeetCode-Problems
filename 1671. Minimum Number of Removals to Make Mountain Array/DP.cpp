#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> DPLEFT(n), DPRIGHT(n);

        for(int i = n - 1; i >= 0; i--){
            int maxi = 0;

            for(int j = i + 1; j < n; j++){
                if(nums[i] > nums[j]){
                    maxi = max(maxi, DPLEFT[j]);
                }
            }

            DPLEFT[i] = maxi + 1;
        }

        for(int i = 0; i < n; i++){
            int maxi = 0;

            for(int j = i - 1; j >= 0; j--){
                if(nums[i] > nums[j]){
                    maxi = max(maxi, DPRIGHT[j]);
                }
            }

            DPRIGHT[i] = maxi + 1;
        }

        int maxMountain = 0;

        for(int i = 0; i < n; i++){
            if(DPRIGHT[i] > 1 && DPLEFT[i] > 1){
                maxMountain = max(maxMountain,
                                  DPRIGHT[i] + DPLEFT[i] - 1);
            }
        }

        return n - maxMountain;
    }
};