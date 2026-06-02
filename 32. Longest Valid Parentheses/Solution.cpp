#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        int ans =0;
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i] = (i-2>=0? dp[i-2]: 0) + 2;
                }

                else{
                    int prev = dp[i-1];
                    int j = i-prev-1;
                    if(j>=0 && s[j]=='('){
                        dp[i] = (j-1>=0 ? dp[j-1]:0) + 2+prev;
                    }
                }
            }
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};