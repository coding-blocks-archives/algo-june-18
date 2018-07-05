#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<pair<int,int > > *l;

public:
	Graph(int V){
		this->V = V;
		l = new list<pair<int,int> >[V];
	}

	void addEdge(int u,int v,int wt,bool bidir=true){
		l[u].push_back(make_pair(v,wt));
		if(bidir){
			l[v].push_back(make_pair(u,wt));
		}
	}
	//Subtree size
	int dfsVisit(int s,bool *visited,int &cost){
		visited[s] = true;
		int cnt = 1;

		for(auto childPair:l[s]){

			int child = childPair.first;
			int wt = childPair.second;
			if(!visited[child]){
				int SubtreeSize = dfsVisit(child,visited,cost);
				cnt += SubtreeSize;
				int x = SubtreeSize;
				int y = V - x;
				cost += 2*min(x,y)*wt;
			}
		}

		return cnt;

	}

	int dfs(int src){
		bool *visited = new bool[V+1]{0};
		int cost = 0;
		dfsVisit(src,visited,cost);
		return cost;	
	}


};

int main(){

	Graph g(4);
	g.addEdge(0,1,3);
	g.addEdge(1,2,2);
	g.addEdge(2,3,2);

	cout<<g.dfs(0)<<endl;

	return 0;
}