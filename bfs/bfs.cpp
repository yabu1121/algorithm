#include <bits/stdc++.h>
using namespace std;


void bfs(int n, int s, vector<vector<int>> &adj, vector<bool> &visited) {
  for (int i = 0; i < n; i++) {
    visited.at(i) = false;
  }

  visited.at(s) = true;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v : adj[u]) {
      if (visited.at(v) == false) {
        visited.at(v) = true;
        Q.push(v);
      }
    }
  }
}

int main(){
  int n; // 頂点数
  int s; // 始点
  int m; // 辺の数
  cin >> n >> s >> m;     
  vector<vector<int>> adj(n); // 隣接リスト
  vector<bool>visited(n);   // 訪問済みフラグ配列
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    // u と v がつながっている場合（無向グラフの例）
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }        
  bfs(n, s, adj, visited);

  for(int i = 0; i < n; i++){
    if(visited[i]){
      cout << "頂点 " << i << ": 到達可能" << endl;
    }else{
      cout << "頂点 " << i << ": 到達不可" << endl;
    }
  }
  return 0;
}