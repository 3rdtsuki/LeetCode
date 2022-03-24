    class Solution {
        /**
         * @param s:current string
         * @param lCnt:count of left brackets
         * @param rCnt:count of right brackets
         */
        void dfs(List<String>res,int n,String s,int lCnt,int rCnt){
            if(lCnt>n || rCnt>n ||lCnt<rCnt){//左括号的数量中途必须大于等于右括号数量
                return;
            }
            if(lCnt==n && rCnt==n){
                res.add(s);
            }
            dfs(res,n,s+'(',lCnt+1,rCnt);
            dfs(res,n,s+')',lCnt,rCnt+1);
        }
        public List<String> generateParenthesis(int n) {
            List<String>res=new ArrayList<>();
            dfs(res,n,"",0,0);
            return res;
        }
    }
