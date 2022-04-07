class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn=0xffff;
        int dp[100005];//dp[i]表示i之前的最大差值
        dp[0]=0;
        for(int i=1;i<prices.size();++i){
            minn=min(minn,prices[i-1]);//找到前i-1中最小值
            dp[i]=max(dp[i-1],prices[i]-minn);
        }
        return dp[prices.size()-1];
    }
};
