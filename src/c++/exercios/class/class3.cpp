#include <iostream>
#include <string.h>
// function friend
// dar acesso a um membro protedigo
class Language;
class LanguageFriend {
  friend class Language;

public:
  int value = 10;

protected:
  void Hello() { std::cout << "Hello" << std::endl; }
private:

};

class Language {
public:
  void helloFriend(LanguageFriend *l) { l->Hello(); }
  char *getName() { return name; }

protected:

private:
  char name[100];
};

int main(void) {
  Language l;
  LanguageFriend lf;
  l.helloFriend(&lf);

  return 0;
}
