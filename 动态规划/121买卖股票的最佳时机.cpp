class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn=0xffff;
        int dp[100005];//dp[i]��ʾi֮ǰ������ֵ
        dp[0]=0;
        for(int i=1;i<prices.size();++i){
            minn=min(minn,prices[i-1]);//�ҵ�ǰi-1����Сֵ
            dp[i]=max(dp[i-1],prices[i]-minn);
        }
        return dp[prices.size()-1];
    }
};
