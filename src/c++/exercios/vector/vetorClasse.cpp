#include <iostream>
#include <vector>

using namespace std;

class Point {
  private:
  public:
    int x, y;
    Point(int x, int y) {
      this->x = x;
      this->y = y;
    }
};

int main(void) {
  vector<Point*> vet;
  vector<Point*>::iterator it;

  Point* p1 = new Point(1,2);
  Point* p2 = new Point(3,4);

  vet.push_back(p1);
  vet.push_back(p2);

  for(it = vet.begin(); it != vet.end(); it++){
    cout << "(" << (*it)->x << "," << (*it)->y << ")" << endl;
  }
  return 0;
}
