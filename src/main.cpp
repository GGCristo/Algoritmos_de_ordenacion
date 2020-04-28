#include <iostream>
#include <string>
#include <vector>

#include "../include/DNI.hpp"
#include "../include/Algoritmos.hpp"

int Demostracion();
int Estadistica();

template<class Clave>
void Llamar_algoritmo(std::vector<Clave>&, std::string);

bool DNI::MODO = true;

int main()
{
  srand(time(NULL));
  std::string modo;
  do
  {
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
  std::cout << "|| DEMOSTRACIÓN ||" << std::endl;
  int tamano;
  {
    std::cout << "¿Tamaño del contenedor?" << '\n';
    std::cin >> tamano;
  } while (tamano < 0);

  std::vector<DNI> contenedor(tamano);

  std::string Algoritmo;
  do
  {
    std::cout << "Elija el algoritmo (Inserción, Burbuja, Heapsort, Quicksort, Shellsort)"
              << '\t';
    std::cin >> Algoritmo;
  } while (Algoritmo != "Inserción" && Algoritmo != "Burbuja" && Algoritmo != "Heapsort" &&
           Algoritmo != "Quicksort" && Algoritmo != "Shellsort");

  std::cout << "Vector antes de ordenar" << std::endl;
  mostrar(contenedor);
  std::cout << '\n';

  Llamar_algoritmo(contenedor, Algoritmo);

  std::cout << '\n';
  std::cout << "Vector despues de ordenar" << std::endl;
  mostrar(contenedor);

  return 0;
}

int Estadistica()
{
  std::cout << "|| ESTADÍSTICA ||" << std::endl;
  DNI::MODO = false;
  return 0;
}

template<class Clave>
void Llamar_algoritmo(std::vector<Clave>& contenedor, std::string algoritmo)
{
  if (algoritmo == "Inserción")
    Insercion(contenedor, contenedor.size());
  else if (algoritmo == "Burbuja")
    Burbuja(contenedor, contenedor.size());
  else if (algoritmo == "Heapsort")
    Heapsort(contenedor, contenedor.size());
  else if (algoritmo == "Quicksort")
    Quicksort(contenedor, 0, contenedor.size() - 1);
  else if (algoritmo == "Shellsort")
    Shellsort(contenedor, contenedor.size());
}
