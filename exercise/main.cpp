#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"


/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  int scelta = -1;
  while(scelta != 0)
  {
    std::cout << "Exercise 3 - Di Costanzo Simone - Matricola: N86004655" << std::endl;
    std::cout << "1)Test Professore " << std::endl;
    std::cout << "2)Test miei" << std::endl;
    std::cout << "0)Exit" << std::endl;
    std::cin  >> scelta;
    if(scelta == 1)
      lasdtest();
    if(scelta == 2)
      mytest();
}
return 0;
}