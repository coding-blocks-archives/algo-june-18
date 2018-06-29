#include<iostream>
#include<queue>
using namespace std;

class UberCar{
	public:
		string driver;
		string model;
		int x,y;

	
		UberCar(string d,string m,int x,int y){
			driver = d;
			model = m;
			this->x = x;
			this->y = y;
		}

		void print(){
			cout<<driver<<endl;
			cout<<model<<endl;
			cout<<x<<","<<y<<endl;		
		}
		void operator+(UberCar x){
			cout<<driver<<" and "<<x.driver<<" are driving "<<model<<" and "<<x.model<<endl;
		}
		void operator[](string s){
			cout<<driver<<s<<endl;
		}
		void operator()(string s){
			cout<<x<<","<<y<<" to "<<s<<endl;
		}
		int dist(){
			return x*x + y*y;
		}

		
};


class myCompare{
		public:
			bool operator()(UberCar &c1,UberCar &c2){
				return c1.dist()>c2.dist();
			}
};

ostream& operator<<(ostream &os,UberCar &x){
		x.print();
		return os;
}

int main(){

		UberCar c("Dhruv","Swift",10,20);
		UberCar d("Prateek","SwiftDzire",30,40);
		UberCar e("Xyz","Nano",11,12);
		//c + d;
		c[" is amazing driver"];
		//Functional Object (Functor)
		d("Kohat");

		//Heap of Cars
		priority_queue<UberCar,vector<UberCar>,myCompare> h;
		h.push(c);
		h.push(d);
		h.push(e);

		while(not h.empty()){
			UberCar t = h.top();
			cout<<t<<endl;
			h.pop();
		}

		return 0;
}