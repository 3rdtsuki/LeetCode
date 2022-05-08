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
