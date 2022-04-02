class Solution {
    public int minDistance(String word1, String word2) {
        int n1=word1.length(),n2=word2.length();
        if(n1==0)return n2;
        if(n2==0)return n1;
        int[][] dp=new int[n1+1][n2+1];
        for(int i=0;i<=n1;++i){
            dp[i][0]=i;
        }
        for(int j=0;j<=n2;++j){
            dp[0][j]=j;
        }
        for(int i=1;i<=n1;++i){
            for(int j=1;j<=n2;++j){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                /*四种情况：
                s[i]==r[j]:dp[i-1][j-1]
                将s[i]替换成r[j]，于是s[i]和r[j]抵消，相当于比较s[0,i-1]和r[0,j-1]：dp[i-1][j-1]+1
                删除s[i]，比较s[0,i-1]和r[0,j]：dp[i-1][j]+1
                s中插入r[j]，比较s[0,i]和r[0,j-1]：dp[i][j-1]+1
                */
                dp[i][j]=Math.min(dp[i][j],Math.min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
        return dp[n1][n2];
    }
}