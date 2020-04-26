#include <iostream>
#include <string>
#include <vector>

#include "../include/DNI.hpp"

int Demostracion();
int Estadistica();

template<class Clave>
void Insercion(std::vector<Clave>&, size_t);

template<class Clave>
void Burbuja(std::vector<Clave>&, size_t);

int main()
{
  srand(time(NULL));
  std::string modo;
  do{
  std::cout << "Elija modo (Demostración, Estadística)" << std::endl;
  // std::cin >> modo;
  modo = "Demostración";
  if (modo == "Demostración")
    Demostracion();
  else if (modo == "Estadística")
    Estadistica();
  else
    std::cout << "Elija una opción valida" << std::endl;
  } while(modo != "Demostración" && modo != "Estadística");

  return 0;
}

int Demostracion()
{
  std::cout << "Estoy en demostracion" << std::endl;
  std::vector<DNI> contenedor(25);
  std::cout << "Vector antes de ordenar" << std::endl;
  for (unsigned i = 0; i < contenedor.size(); ++i) {
    std::cout << contenedor[i] << '\t';
  }

  std::cout << '\n';
  Burbuja(contenedor, contenedor.size());

  std::cout << "Vector despues de ordenar" << std::endl;
  for (unsigned i = 0; i < contenedor.size(); ++i)
  {
    std::cout << contenedor[i] << '\t';
  }
  std::cout << '\n';

  return 0;
}

int Estadistica()
{
  std::cout << "Estoy en estadistica" << std::endl;
  return 0;
}

template<class Clave>
void Insercion(std::vector<Clave>& contenedor, size_t tamano)
{
  for (size_t i = 1; i < tamano; ++i)
  {
    int j = i;
    while ( j > 0 && contenedor[--j] > contenedor[i])
    {
      std::swap(contenedor[j], contenedor[i]);
      i--;
    }
  }
}

template<class Clave>
void Burbuja(std::vector<Clave>& contenedor, size_t tamano)
{
  for (size_t i = 0; i < tamano - 1; ++i)
  {
    for (size_t j = 0; j < tamano - 1; ++j)
    {
      if (contenedor[j] > contenedor[j + 1])
        std::swap(contenedor[j], contenedor[j + 1]);
    }
  }
}
