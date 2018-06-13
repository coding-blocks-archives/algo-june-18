#include<bits/stdc++.h>
using namespace std;

class Graph{
	public:
	unordered_map<int,list<pair<int,int> > > m;
	int V;
	Graph(int v){
		V = v;
	}

	void addEdge(int u,int v, int wt){
		m[u].push_back(make_pair(v,wt));
		m[v].push_back(make_pair(u,wt));
	}
	int dfsHelper(int s,bool *visited,int &ans){
		visited[s] = true;
		
		int subTreeSize = 1;
		int size = 0;
		for(auto neighbourPair:m[s]){
			
			int v = neighbourPair.first;
			int wt = neighbourPair.second;

			if(!visited[v]){
				size = dfsHelper(v,visited,ans);
				//Later...
				ans += 2*wt*min(size,V-size);
				subTreeSize += size;
			}
		}
		return subTreeSize;
	}

	int dfs(int s){
		int ans = 0;
		bool *visited = new bool[V+1]{0};
	 	dfsHelper(s,visited,ans);
	 	return ans;
	}
};

int main(){

	Graph g(4);
	g.addEdge(1,2,3);
	g.addEdge(2,3,2);
	g.addEdge(4,3,2);
	cout<<g.dfs(1)<<endl;
	return 0;
}