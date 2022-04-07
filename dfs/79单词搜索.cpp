class Solution {
public:
	bool visited[10][10];
	//��ǰ������board[i][j]���Ѿ���������������ǰ�㣩�ĳ���Ϊlen�����ظõ��Ƿ�����ȷ·���ϡ�
	//���շ��ص��ǽ���ջ�׵�boolֵ��exist()���� 
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int len){
        if(len==word.length()){
        	return true;
		}
		//���Խ�磬�����ַ���ƥ�䣬�����Ѿ����ʹ��õ㣬��false 
		if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || 
        	board[i][j]!=word[len]|| visited[i][j]){
			return false;
		}
		
		visited[i][j]=true;//���Ϊ���ʹ� 
		//��������������������ֻҪ��һ��������ȷ����ǰ�����ȷ 
		if( dfs(board,word,i-1,j,len+1) || dfs(board,word,i+1,j,len+1) ||
			dfs(board,word,i,j+1,len+1) || dfs(board,word,i,j-1,len+1) ){
            return true;
        }
        visited[i][j]=false;
		return false;//���ݺ󣬲�������㣬����false 
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
