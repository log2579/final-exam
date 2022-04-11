#include <bits/stdc++.h>
using namespace std;
class Vehicles{
	int wheels;
	double weight;
	public:
		Vehicles(){
			
		}
		void input(){
			cout<<"Nhap Wheels: ";
			cin>>wheels;
			cout<<"Nhap Weight: ";
			cin>>weight;
		}
		virtual void output(){
			cout<<"\nWheels: "<<wheels;
			cout<<"\nWeight: "<<weight;
		}
		void setWheels(int wheels){
			this->wheels = wheels;
		}
		int getWheels(){
			return wheels;
		}
		double getWeight(){
			return weight;
		}
		~Vehicles(){
			
		}
};

class Car:public Vehicles{
	int passenger_load;
	public:
		Car(){
			
		}
		void setPassengerLoad(int passLoad){
			this->passenger_load = passLoad;
		}
		int getPassengerLoad(){
			return passenger_load;
		}
		void input(){
			Vehicles::input();
			cout<<"Nhap passenger load: ";
			cin>>passenger_load;
		}
		virtual void output(){
			cout<<"\nType: Car";
			Vehicles::output();
			cout<<"\nPassenger load: "<<passenger_load;
		}
		~Car(){
			
		}
};

class Truck:public Vehicles{
	double pay_load;
	public:
		Truck(){
			
		}
		void setPayLoad(double payLoad){
			this->pay_load = payLoad;
		}
		double getPayLoad(){
			return pay_load;
		}
		void input(){
			Vehicles::input();
			cout<<"Nhap pay load: ";
			cin>>pay_load;
		}
		virtual void output(){
			cout<<"\nType: Truck";
			Vehicles::output();
			cout<<"\nPay load: "<<pay_load;
		}
		~Truck(){
			
		}
};

class ListVehicles{
	int n;
	Vehicles **p;
	public:
		ListVehicles(){
			
		}
		void input(){
			cout<<"Nhap so luong: ";
			cin>>n;
			p = new Vehicles *[n];
			for(int i=0;i<n;i++){
				int temp;
				cout<<"\nNhap xe thu "<<i<<": ";
				cout<<"\nNhap Car(1) hay Truck(<>1): ";
				cin>>temp;
				if(temp == 1){
					Car *c = new Car();
					c->input();
					p[i] = c;
				}
				else{
					Truck *t = new Truck();
					t->input();
					p[i] = t;
				}
			}
		}
		virtual void output(){
			for(int i=0;i<n;i++){
				p[i]->output();
				cout<<"\n--------------------------------";
			}
		}
		void sort(){
			cout<<"\nSort Descendin: ";
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(p[i]->getWeight()<p[j]->getWeight()){
						swap(p[i],p[j]);
					}
				}
			}
		}
		void decrease(){
			Car x;
			for(int i=0;i<n;i++){
				if(typeid(*p[i]).name() == typeid(x).name()){
					Car *c = static_cast<Car*>(p[i]);
					if(c->getPassengerLoad() <= 2){
						c->setPassengerLoad(0);
					}
					else{
						c->setPassengerLoad(c->getPassengerLoad()-2);
					}
				}
				else{
					Truck *t = static_cast<Truck*>(p[i]);
					if(t->getPayLoad() <= 50){
						t->setPayLoad(0);
					}
					else{
						t->setPayLoad(t->getPayLoad()-50);
					}
				}
			}
		}
		int count(){
			int temp = 0;
			for(int i=0;i<n;i++){
				if(p[i]->getWheels() >= 7){
					temp++;
				}
			}
			return temp;
		}
		~ListVehicles(){
			delete[] *p;
		}
};
int main(){
	ListVehicles v;
	cout<<"input: "<<endl;
	v.input();
	cout<<"output: "<<endl;
	v.output();
	v.sort();
	v.output();
	cout<<"\nCount the number of vehicles that have more than 7 wheels:";
	cout<<v.count()<<endl;
	cout<<"Decrease the number of passenger_load down two people if the vehicle is a Car and pay_load down 50 kg if the vehicle is a Truck:";
	v.decrease();
	v.output();
}

