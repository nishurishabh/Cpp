//  https://www.techiedelight.com/bipartite-graph/
#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int N;
        vector<vector<int>> adj;

        Graph(int n)
        {
            adj.resize(n);
            N=n;
        }
        void addEdge(pair<int,int> p)
        {
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }
};

bool isBipartite(Graph g, int startingVertex)
{
    vector<int> color(g.N, 0);
    queue<int> q;
    color[startingVertex]=1;
    q.push(startingVertex);

    while(!q.empty())
    {
        int temp = q.front();
        cout<< temp <<" ";
        q.pop();
        for(auto x: g.adj[temp])
        {
            if(color[x] == 0)
            {
                color[x]=(color[temp] == 1)?2:1;
                q.push(x);
            } 
            else
            {
                if(color[x] == color[temp])
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    Graph g(6);
    vector<pair<int,int>> edges{{0,3}, {0,4}, {0,5}, {1,3}, {1,4}, {1,5}, {2,3}, {2,4}, {2,5}};
    for(auto x: edges)
    {
        g.addEdge(x);
    }

    if(isBipartite(g,0)) cout<<endl<< "This is a Bipartite Graph";
    else cout << endl<< "This is not a Bipartite Graph";
}

// Graph
// Number of Nodes: 6
// Edges: {0,3}, {0,4}, {0,5}, {1,3}, {1,4}, {1,5}, {2,3}, {2,4}, {2,5}