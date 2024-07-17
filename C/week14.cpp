#include <iostream>
#include <string.h>

using namespace std;

class Person;

class Car{
public:
	//constructors
	Car();
	Car(string maker, string car_model, int year, string car_color);

	//member functions
	void start_engine();
	void stop_engine();
	void speed_up(int speed_increase);
	void slow_down(int speed_decrease);
	void display();
	void set_owner(Person *new_owner);

private:
	//data members
	string make;
	string model;
	int year;
	string color; 
	int speed;
	bool is_engine_running;
	Person *owner;
};

Car::Car(){
	make = "";
	model = "";
	year = 0;
	color = "";
	is_engine_running = false;
	speed = 0;
	owner = NULL;
}

Car::Car(string maker, string car_model, int car_year, string car_color){
	make = maker;
	model = car_model;
	year = car_year;
	color = car_color;
	is_engine_running = false;
	speed = 0;
	owner = NULL;
}

void Car::start_engine(){
	if(is_engine_running == false)
		is_engine_running = true;
}

void Car::stop_engine(){
	if(is_engine_running)
		is_engine_running = false;
}

void Car::speed_up(int speed_increase){
	if(is_engine_running){
		speed += speed_increase;
	}else{
		cout<<"Engine is not running!"<<endl;
	}
}

void Car::slow_down(int speed_decrease){
	if(is_engine_running){
		speed -= speed_decrease;
		if(speed < 0){
			speed = 0;
		}
	}else{
		cout<<"Engine is not running!"<<endl;
	}
}

void Car::display(){
	cout<<"Speed: "<<speed<<endl;
	cout<<"Make: "<<make<<" Model: "<<model<<" Year: "<<year<<endl;
	cout<<"Color: "<<color<<endl;
	cout<<"Engine status: ";
	if(is_engine_running){
		cout<<"On"<<endl;
	}else{
		cout<<"Off"<<endl;
	}
}

void Car::set_owner(Person *new_owner){
	owner = new_owner;
}

class Person{
public:
  Person(string person_name, int person_age, string make, string model, int year,string car_color);
	Person(string person_name, int person_age);
	void display();
	void buy_car(Car *new_car);
	Car* sell_car();
private:
	string name;
	int age;
	Car *car;
};

Person::Person(string person_name, int person_age, string make, string model, int year,string car_color){
	name = person_name;
	age = person_age;
	car = new Car(make, model, year, color);
	color = car_color;
}

Person::Person(string person_name, int person_age){
	name = person_name;
	age = person_age;
	car = NULL;
}

void Person::display(){
	cout<<"Name: "<<name<<" Age: " << age <<endl;
	if(car != NULL){
		car->display();
	}
}

void Person::buy_car(Car *new_car){
	car = new_car;
}

Car* Person::sell_car(){
	Car *sold_car = car;
	car = NULL;
	return sold_car;
}

int main(){
	Car corolla("Toyota", "Corolla", 2024, "blue");
	corolla.display();

	Car civic("Honda", "Civic", 2020, "black");
	civic.display();

	corolla.start_engine();
	corolla.speed_up(50);
	corolla.display();

	corolla.slow_down(80);
	corolla.stop_engine();
	corolla.display();

	Person ali("Ali", 42);
	ali.display();
	ali.buy_car(&corolla);
	corolla.set_owner(&ali);
	ali.display();

	Person ayse("Ayse", 30);
	ayse.display();
	ayse.buy_car(ali.sell_car());
	corolla.set_owner(&ayse);
	ali.display();
	ayse.display();
}