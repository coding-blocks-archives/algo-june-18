#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){

	Hashtable<int> h(17);
	h.insert("Mango",120);
	h.insert("Guava",30);
	h.insert("Apple",180);
	h.insert("Pineapple",75);
	h.insert("Litchi",110);

	//int *price = h.search("Guava");
	//cout<<(*price);

	h["Kiwi"] = 190;
	h["Kiwi"] += 20;
	cout<<h["Kiwi"]<<endl;

	h.print();

	return 0;
}