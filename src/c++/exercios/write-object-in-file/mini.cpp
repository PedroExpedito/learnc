#include <iostream>
#include <fstream> // ofstream e ifstream


using namespace std;

class People {
  public:
    std::string name;
    int age;

  // sobrecarga do operador de inserção de dados <<
	// ostream = output stream
	friend ostream& operator<<(ostream& os, const People& p)
	{
		// escrever cada membro
		os << "\n" << p.name<< "\n";
		os << p.age;
		return os;
	}

	// sobrecarga do operador de extração de dados >>
	// istream = input stream
	friend istream& operator>>(istream& is, People& p)
	{
		// ler cada membro
		is >> p.name >> p.age;
		return is;
	}


};
int main() {
  People p;

  p.age = 19;
  p.name.append("pedro");

  std::ofstream ofs("arquivo.txt", std::fstream::app);

  ofs << p;

  ofs.close();

}
