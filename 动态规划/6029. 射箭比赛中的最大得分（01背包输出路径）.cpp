class Solution {
	public:
		vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
			int dp[12][numArrows+1];//dp[i][j]代表第i回合获得的最大分数，并且此时花费箭数为j
			bool path[12][numArrows+1];//记录路径
			memset(dp,0,sizeof(dp));
			memset(path,false,sizeof(path));

			int j;
			for(j=numArrows; j>=0; --j) {
				dp[0][j]=0;
			}
			for(int i=1; i<12; ++i) {
				for(j=0; j<=numArrows; ++j) {
					dp[i][j]=dp[i-1][j];
					//要么射，要么放弃
					if(j-aliceArrows[i]-1>=0) {
						if(dp[i][j]<dp[i-1][j-aliceArrows[i]-1]+i) {
							dp[i][j]=dp[i-1][j-aliceArrows[i]-1]+i;
							path[i][j]=true;
						}
					}
				}
			}
			cout<<dp[11][numArrows];

			//输出路径 
			j=numArrows;
			int result[12];
			for(int i=11; i>=0; --i) {
				if(path[i][j]) {
					result[i]=aliceArrows[i]+1;
					j-=aliceArrows[i]+1;
				} else {
					result[i]=0;
				}
			}
			result[0]=j;//记得用完剩余的箭 
			vector<int>res;
			for(int i=0; i<12; ++i) {
				res.push_back(result[i]);
			}
			return res;
		}
};
