#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

//CB IDE - 15890

class Graph{

	unordered_map<char,list<char> > m;
public:
	void addEdge(char u,char v,bool bidir=true){
		m[u].push_back(v);
		
		if(bidir){
			m[v].push_back(u);
		}
	}
	void dfsVisit(char s,unordered_map<char,bool> &visited){
		visited[s] = true;
		cout<<s<<" ";
		
		for(auto child:m[s]){
			if(!visited[child]){
				dfsVisit(child,visited);
			}
		}
		return;
	}
	void dfs(char s){
		unordered_map<char,bool> visited;
		dfsVisit(s,visited);
	}
	bool isCylicHelper(char s,unordered_map<char,bool> &visited,unordered_map<char,char> &parent){
		visited[s] = true;

		for(auto child:m[s]){
			if(visited[child] and child!=parent[s]){
				return true;
			}
			else if(!visited[child]){
				parent[child] =  s;
				bool aageCycleMilaKya = isCylicHelper(child,visited,parent);
                if(aageCycleMilaKya){
                    return true;
                }
			}
		}
		return false;
	}

	bool isCylic(char s){
		unordered_map<char,bool> visited;
		unordered_map<char,char> parent;
		parent[s] = '\0';

		return isCylicHelper(s,visited,parent); 
	}
};

int main(){

	Graph g;
	g.addEdge('A','B');
	g.addEdge('B','E');
	g.addEdge('C','B');
	g.addEdge('C','E');
	g.addEdge('C','D');
    g.addEdge('A','F');

	g.dfs('A');

	if(g.isCylic('A')){
		cout<<"Cyclic";
	}
	else{
		cout<<"Not cyclic";
	}



	return 0;
}