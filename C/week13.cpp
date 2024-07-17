#include <iostream>

using namespace std;

class Register {
	public:
		//constructors
		Register();
		Register(double price, int count);
		//member functions
		void add_item(double item_price);
		double get_total_price() const;
		int get_item_count() const;
		void clear();
		void add_multiple_items(double unit_price, int count);

	private:
		//data members
		double total_price;
		int item_count;
};

Register::Register(){
	clear();
	cout<<"C1: A new register obj. created" << endl;
}

Register::Register(double price, int count)
{
		total_price = price;
		item_count = count;
		cout<<"C2: A new register obj. created" << endl;
}


int Register::get_item_count() const{
	return item_count;
}
void Register::add_multiple_items(double unit_price, int count){
	for(int i = 0; i < count; i++) {
		add_item(unit_price);
	}
}

void Register::add_item(double item_price){
	total_price += item_price;
	item_count++;
}

double Register::get_total_price() const{
	return total_price;
}

void Register::clear(){
	total_price = 0;
	item_count = 0;
}

int main() {
	//create register objects
	Register reg1;
	Register reg2(10.5, 3);
	//Register reg3;

	reg1.clear();
	reg1.add_item(3.5);
	reg1.add_item(4.1);
	reg1.add_item(2.5);

	reg2.clear();
	reg2.add_item(4);

	cout<<reg1.get_total_price()<<endl;
	reg1.add_multiple_items(2, 5);
	cout<<reg1.get_total_price()<<endl;
	//cout<<reg1.total_price<<endl; // this is illegal

	cout<<reg2.get_total_price()<<endl;
	return 0;
}