#include <iostream>

using namespace std;

class Register 
{
  public:
      // member func
      void add_item(double item_price);
      // accessors
      double get_total_price() const; // hicbir sey modify etmiyoruz.
      int get_item_count() const;

      void clear();
      void add_multiple_items(double unit_price, int count);

   private:
      // data members
      double total_price ;
      int item_count;   

};
// accessors
int Register:: get_item_count() const {
    return item_count;
}
double Register:: get_total_price() const{
  return total_price;
}

void Register:: add_multiple_items(double unit_price, int count){
  for(int i = 0; i< count; i++){
    total_price += unit_price;
    item_count++;
  }
} 

void Register:: add_item(double item_price){
  total_price += item_price;
  item_count++;
}

void Register:: clear(){
  total_price = 0;
  item_count = 0;
}

int main(){
    // create register object
   // int num;
    Register reg1;
    Register reg2;
    //Register reg3;

    reg1.clear();
    reg1.add_item(3.5);
    reg1.add_item(4.1);
    reg1.add_item(2.5);


    reg2.clear();
    reg2.add_item(4);


    cout<<reg1.get_total_price()<<endl;
    cout<<reg1.get_item_count()<<endl;

    reg1.add_multiple_items(2,5);

    cout<<reg1.get_total_price()<<endl;
    cout<<reg1.get_item_count()<<endl;

    cout<<reg2.get_total_price()<<endl;
  return 0;
}




