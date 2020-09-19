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

void foo(Account* c) {
  c->deposit(20);
  (*c).deposit(22);
  std::cout << c << std::endl;
}
void foo(Account& c) {
  c.deposit(11);
}

Account* newAccount(int num) {
  Account * c = new Account;
  c->id = num;
  c->balance = 100;
  return c;
}

int main(void) {
  Account c = {1, 100.54};
  c.id = 1;
  c.deposit(100);
  foo(c);

  std::cout << "balance: " << c.getBalance() << std::endl;

  return 0;
}
