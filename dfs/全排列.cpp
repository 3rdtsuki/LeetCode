#include <iostream> 
#include <vector> 
#include <queue>
using namespace std;
bool flag[200];
int v[200];
int n;
void dfs(int cnt){
    if(cnt==n){
        for(int i=0;i<n;++i){
            cout<<v[i]<<' ';
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=1;i<=n;++i){
            if(flag[i]==0){
                flag[i]=1;
                v[cnt]=i;
                dfs(cnt+1);
                flag[i]=0;
            }
        }
    }
}
int main(){
    cin>>n;
    dfs(0);
}
/*
when flag[i]=1, we put i into v, then it backs to choose v[cnt+1] whose flag equals to zero.
after we finish an n size array, we must return flag[i] to zero to be focus on the last crossing
*/
