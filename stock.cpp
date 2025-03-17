class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.empty()) return 0;
    
            int n = prices.size();
            vector<int> dp0(n, 0), dp1(n, 0), dp2(n, 0);  
            
            dp1[0] = -prices[0]; 
            
            for (int i = 1; i < n; i++) {
                dp0[i] = max(dp0[i-1], dp2[i-1]); 
                dp1[i] = max(dp1[i-1], dp0[i-1] - prices[i]); 
                dp2[i] = dp1[i-1] + prices[i]; 
            }
            
            return max(dp0[n-1], dp2[n-1]); 
        }
    };
    