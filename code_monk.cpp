#include<cstring>
#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
vector<int> list[1001];
bool visited[1001];
int risk[1001];
ll dfs(int x)
{  int min;
    visited[x]=true;
    min=risk[x];
    for(int j=0;j<list[x].size();j++)
    {
        if(!visited[list[x][j]]){
           if(min>dfs(list[x][j]))
           min=dfs(list[x][j]);
    }
}
return min;
}
int main()
{
 
    int n,k,a,b,i;
    long long ans;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>risk[i];
        memset(visited,0,n+1);
        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>a>>b;
            list[a].push_back(b);
            list[b].push_back(a);
        }
        for(i=1,ans=0;i<=n;i++)
        {
        if(!visited[i]){
          ans+=dfs(i);
          
        }
        }
        cout<<ans<<endl;
        return 0;
}
