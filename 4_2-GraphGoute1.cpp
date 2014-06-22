// check there are routes between two nodes of a directed graph

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 4;
bool g[maxn][maxn], visited[maxn];
queue<int> q;

void init(){
    memset(g, false, sizeof(g));
    memset(visited, false, sizeof(visited));
}
bool route(int src, int dst){
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t == dst) return true;
        for(int i=0; i<maxn; ++i)
            if(g[t][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
    }
    return false;
}
int main(){
    
    init();
    for (int i = 0; i < maxn; ++i)
    {
        for (int j = 0; j < maxn; ++j) {
            g[i][j] = 1;
        }
  
    }
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout<<route(0, 2)<<endl;
    return 0;
}

