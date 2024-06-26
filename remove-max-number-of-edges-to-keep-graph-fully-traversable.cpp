//remove-max-number-of-edges-to-keep-graph-fully-traversable
/*Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.*/

class DSU{
public:
    int n;
    vector<int> parent;
    vector<int> sz;
    int max_sz;
    
    DSU(int n){
        this->n = n;
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        sz = vector<int>(n, 1);
        max_sz = 1;
    }
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    int unite(int x, int y){
        if(x > y) swap(x, y);
        //merge the later to the earlier
        
        int py = find(y);
        int px = find(x);
        
        if(px == py)
            return -1;
        
        parent[py] = px;
        sz[px] += sz[py];
        max_sz = max(max_sz, sz[px]);
        
        return 0;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), 
            [](vector<int>& e1, vector<int>& e2){return e1[0] > e2[0];});
        
        DSU dsu1(n), dsu2(n);
        int discarded = 0;
        
        for(vector<int>& edge : edges){
            // cout << edge[0] << ", " << edge[1] << ", " << edge[2] << endl;
            switch(edge[0]){
                case 1:
                    if(dsu1.unite(edge[1]-1, edge[2]-1)){
                        ++discarded;
                        // cout << "discard" << endl;
                    }
                    // cout << "dsu1 max size: " << dsu1.max_sz << endl;
                    break;
                case 2:
                    if(dsu2.unite(edge[1]-1, edge[2]-1)){
                        ++discarded;
                        // cout << "discard" << endl;
                    }
                    // cout << "dsu2 max size: " << dsu2.max_sz << endl;
                    break;
                case 3:
                    int ret = dsu1.unite(edge[1]-1, edge[2]-1);
                    dsu2.unite(edge[1]-1, edge[2]-1);
                    
                    if(ret){
                        //they are originally in the same union
                        //since dsu1 is the same as dsu2 when processing type 3,
                        //so only need to check dsu1
                        ++discarded;
                        // cout << "discard" << endl;
                    }
                    // cout << "max size: " << dsu1.max_sz << endl;
            }
        }
        
        if(dsu1.max_sz != n || dsu2.max_sz != n){
            //the graph is not fully connected
            return -1;
        }
        
        return discarded;
    }
};
