#include <SFML/Window/Keyboard.hpp>
#include <stdio.h>
#include <unistd.h>

int main() {
  printf("\n\nMAIN\n\n");
  bool click = false;
  while (1) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      if (!click) {
        printf("A\n");
        click = true;
      }
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && click == true) {
      click = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
      if (!click) {
        printf("B");
        click = true;
      }
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) && click == true) {
      click = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
      if (!click) {
        printf("C");
        click = true;
      }
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) && click == true) {
      click = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      if (!click) {
        printf("D");
        click = true;
      }
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && click == true) {
      click = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
      if (!click) {
        printf("E");
        click = true;
      }
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) && click == true) {
      click = false;
    }


  }
  return 0;
}
