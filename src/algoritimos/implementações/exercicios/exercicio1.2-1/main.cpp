#include <iostream>
#define SIZE 2

class Product {
  private:
  std::string name;
  double price;
  public:
  ~Product() {
    name.clear();
  }
  Product(std::string name, double price) {
    this->price = price;
    this->name.append(name);
  }
    void setName(std::string name) {
      this->name.append(name);
    }
    std::string getName() {
      return this->name;
    }
    void setPrice(double price) {
      this->price = price;
    }
    double getPrice() {
      return this->price;
    }
};

void searchIn(std::string name, Product p[], int size) {
  for (int i = 0; i < size; i++ ) {
    if( p[i].getName().compare(name) == 0) {
      std::cout << "Possuimos na posi: " << i << std::endl;
      break;
    }
  }
}

int main(void) {
  std::string searchName;
  Product p[SIZE]{{"banana", 7.50}, { "Abacaxi", 8.80}};
  std::cout << "Pesquisar por fruta" << std::endl;
  std::cin >> searchName;
  searchIn(searchName, p, SIZE);

}
