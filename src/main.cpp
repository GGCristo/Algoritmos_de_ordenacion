#include <iostream>
#include <string>
#include <vector>

#include "../include/DNI.hpp"
#include "../include/Algoritmos.hpp"

int Demostracion(const int&);
int Estadistica(const int&);


bool DNI::MODO = true;
unsigned DNI::CONTADOR = 0;

int main()
{
  srand(time(NULL));

  int tamano;
  do
  {
    std::cout << "¿Tamaño del contenedor?" << '\n';
    std::cin >> tamano;
  } while (tamano < 0);

  std::string modo;
  do
  {
    std::cout << "Elija modo (Demostración, Estadística)" << '\n';
    std::cin >> modo;

    if (modo == "Demostración")
      Demostracion(tamano);
    else if (modo == "Estadística")
      Estadistica(tamano);
    else
      std::cout << "Elija una opción valida" << '\n';
  } while(modo != "Demostración" && modo != "Estadística");

  return 0;
}
