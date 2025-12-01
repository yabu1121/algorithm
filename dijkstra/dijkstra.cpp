#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

/*
 * n: 頂点数
 * s: 始点
 * adj: 重み付き隣接リスト (pair<行き先, 重み>)
 * dist: 最短距離を記録する配列（結果はここに格納される）
 */
void dijkstra(int n, int s, vector<vector<pair<int, int>>> &adj, vector<long long> &dist) {
    for (int i = 0; i < n; i++) {
        dist.at(i) = INF;
    }
    
    dist.at(s) = 0;

    // 3. 優先度付きキュー (昇順: 小さい値が先頭に来る設定)
    // pair<距離, 頂点> を入れます
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        // 一番距離が短い頂点を取り出す
        long long d = pq.top().first; // 現在の距離
        int u = pq.top().second;      // 現在の頂点
        pq.pop();

        // 【重要】もし記録されている最短距離より大きければスキップ
        // (より短いルートで既に処理済みの可能性があるため)
        if (d > dist.at(u)) continue;

        // 隣接する頂点を探索
        for (auto edge : adj[u]) {
            int v = edge.first;       // 行き先
            int weight = edge.second; // 重み

            // 「現在の頂点までの距離 + 重み」が「行先の現在の最短距離」より短ければ更新
            if (dist.at(u) + weight < dist.at(v)) {
                dist.at(v) = dist.at(u) + weight;
                pq.push({dist.at(v), v}); // 更新したらキューに入れる
            }
        }
    }
}

int main(){
    int n, s, m;
    cin >> n >> s >> m;
    
    // 変更点1: 重み付きグラフにするため pair<行き先, 重み> を持つ
    vector<vector<pair<int, int>>> adj(n);
    
    vector<long long> dist(n);

    // 重み付き隣接の作成
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    
    dijkstra(n, s, adj, dist);

    for(int i = 0; i < n; i++){
        if(dist[i] != INF){
            cout << "頂点 " << i << ": 最短コスト " << dist[i] << endl;
        }else{
            cout << "頂点 " << i << ": 到達不可" << endl;
        }
    }
    return 0;
}