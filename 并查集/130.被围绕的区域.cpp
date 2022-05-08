class UnionFind{
public:
	int *root;
	UnionFind(int n){
		root=new int[n];
		for(int i=0;i<n;++i){
			root[i]=i;
		}
	}
	int find(int i){
		while(i!=root[i]){
			i=root[i];
		}
		return i;
	}
	void unions(int i,int j){
        int x=find(i);
        int y=find(j);
		if(x!=y){
			root[x]=y;
		}
	}
	bool isUnioned(int i,int j){
		return find(i)==find(j);
	}
};
class Solution {
public:
    int n;
    int no(int i,int j){
        return i*n+j;//行号*列数+列号
    }
    //每个o如果能连到边界就改成x
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        n=board[0].size();
        UnionFind uf(m*n+1);
        int father=m*n;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O'){
                    if(i==0 || i==m-1 || j==0 || j==n-1){
                        uf.unions(no(i,j),father);//边界归为father
                    }
                    else{
                        if(board[i-1][j]=='O'){//注意，每个O要和上下左右的O都合并！
                            uf.unions(no(i,j),no(i-1,j));
                        }
                        if(board[i][j-1]=='O'){
                            uf.unions(no(i,j),no(i,j-1));
                        }
                        if(board[i+1][j]=='O'){
                            uf.unions(no(i,j),no(i+1,j));
                        }
                        if(board[i][j+1]=='O'){
                            uf.unions(no(i,j),no(i,j+1));
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O' && !uf.isUnioned(no(i,j),father)){
                    board[i][j]='X';
                }
            }
        }
    }
};
