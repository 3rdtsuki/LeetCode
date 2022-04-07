class Solution {
public:
	bool visited[10][10];
	//当前搜索到board[i][j]，已经搜索（不包含当前点）的长度为len，返回该点是否在正确路径上。
	//最终返回的是进程栈底的bool值给exist()函数 
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int len){
        if(len==word.length()){
        	return true;
		}
		//如果越界，或者字符不匹配，或者已经访问过该点，就false 
		if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || 
        	board[i][j]!=word[len]|| visited[i][j]){
			return false;
		}
		
		visited[i][j]=true;//标记为访问过 
		//继续向上下左右搜索，只要有一个方向正确，当前点就正确 
		if( dfs(board,word,i-1,j,len+1) || dfs(board,word,i+1,j,len+1) ||
			dfs(board,word,i,j+1,len+1) || dfs(board,word,i,j-1,len+1) ){
            return true;
        }
        visited[i][j]=false;
		return false;//回溯后，不走这个点，返回false 
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
