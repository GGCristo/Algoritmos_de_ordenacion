#include <iostream>
#include <vector>

#include "../include/DNI.hpp"
#include "../include/Algoritmos.hpp"

template<class Clave>
void Llamar_algoritmo(std::vector<Clave>&, std::string);

int Demostracion(const int& tamano)
{
  std::cout << "|| DEMOSTRACIÓN ||" << '\n';

  std::vector<DNI> contenedor(tamano);

  std::string Algoritmo;
  do
  {
    std::cout << "Elija el algoritmo (Inserción, Burbuja, Heapsort, Quicksort, Shellsort)"
      << '\t';
    std::cin >> Algoritmo;
  } while (Algoritmo != "Inserción" && Algoritmo != "Burbuja" && Algoritmo != "Heapsort" &&
           Algoritmo != "Quicksort" && Algoritmo != "Shellsort");

  std::cout << "Vector antes de ordenar" << '\n';
  mostrar(contenedor);
  std::cout << '\n';

  Llamar_algoritmo(contenedor, Algoritmo);

  std::cout << '\n';
  std::cout << "Vector despues de ordenar" << '\n';
  mostrar(contenedor);

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
  else
    std::cout << "Esa opción no esta programada" << '\n';
}
