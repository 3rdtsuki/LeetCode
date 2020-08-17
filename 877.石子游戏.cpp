经典的博弈论动态规划问题，这种轮流取石子的题可以用dp当做两人得分的差来解决，最后差>0则胜利。
另外，迭代过程是从里向外扩散的，dp[i][j]是在dp[i+1][j-1]的基础上，对两侧做出选择得到的得分，因为得分的过程和石子剩余正好是相反的。
还需要更多思考。
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //dp[i][j]代表Alex在面对i~j时接下来的最优解和上一步Lee的差
        for(int step=1;step<n;++step){
            for(int i=0;i<n-step;++i){
                int j=i+step;
                dp[i][j]=max(piles[j]-dp[i][j-1],piles[i]-dp[i+1][j]);
            }
        }

        return dp[0][n-1]>0;
    }
};
