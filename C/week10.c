#include <stdio.h>


void deposit(double *account,double amount){
    *account += amount;
}

void withdraw(double *account, double amount){
    *account -= amount;
}

int main() 
{
  double *acc_ptr = NULL;

  double personal_acc = 100;
  double joint_acc = 900;
  double savings_acc = 500;

  printf("Current balance in personal acc: %lf\n", personal_acc);
  printf("Current balance in joint acc: %lf\n", joint_acc);
  printf("Current balance in savings acc: %lf\n", savings_acc);


  printf("Current address in personal acc: %p\n", &personal_acc);
  printf("Current address in joint acc: %p\n", &joint_acc);
  printf("Current address in acc_ptr : %p\n", &acc_ptr);

  withdraw(&joint_acc,300);
  deposit(&personal_acc,300);

  withdraw(&savings_acc,500);
  deposit(&personal_acc,500);
 
  
  printf("Current balance in personal acc: %lf\n", personal_acc);
  printf("Current balance in joint acc: %lf\n", joint_acc);
  printf("Current balance in savings acc: %lf\n", savings_acc);
 
  return 0;
}