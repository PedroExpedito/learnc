#include <iostream>
#include <string.h>

class Account {
  private:
  public:
    int id = 0;
    double balance = 0;
    double getBalance() {
      return this->balance;
    }
    double deposit(double value) {
      if ( value > 0 ) {
        this->balance += value;
      }
      return this->balance;
    }
    double whitdraw(double value) {
      if ( balance >= value && value > 0) {
        this->balance -= value;
      }
      return this->balance;
    }

  protected:
};

int main(void) {
  Account c = {1, 100.54};
  c.id = 1;
  c.deposit(100);
  c.whitdraw(10);

  std::cout << c.getBalance() << std::endl;
  c.whitdraw(-20);
  std::cout << "balance: " << c.getBalance() << std::endl;

  return 0;
}
