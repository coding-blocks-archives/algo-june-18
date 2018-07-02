#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main(){
	unordered_map<string,int> m;

	//Insertion Ways
	m.insert(make_pair("Mango",100));
	m["Apple"] = 120;
	
	pair<string,int> p;
	p.first = "Guava";
	p.second = 70;
	m.insert(p);

	pair<string,int> p2("Kiwi",190);
	m.insert(p2);

	//Search - 2 ways
	m.erase("Kiwi");
 

	//Count, find
	if(m.count("Kiwi")==0){
		cout<<"Kiwi doesn't exist";
	}
	else{
		cout<<m["Kiwi"]<<endl;
	}
    //Find 
    auto it = m.find("Kiwi");
    if(it!=m.end()){
        cout<<it->first<<endl;
        cout<<it->second<<endl;
    }

    m.clear();
    //For each loop
    for(auto item:m){
        cout<<item.first<<endl;
        cout<<item.second<<endl;
    }
    //For each using iterators
    for(unordered_map<string,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<it->first<<endl;
        cout<<it->second<<endl;
    }

	return 0;
}