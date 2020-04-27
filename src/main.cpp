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

template<class Clave>
void Heapsort(std::vector<Clave>&, size_t);

template<class Clave>
void Crearheap(std::vector<Clave>&, size_t);

template<class Clave>
void Extraerheap(std::vector<Clave>& , size_t);

template<class Clave>
void mostrar(const std::vector<Clave>&);

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
  std::cout << "Estoy en demostracion" << std::endl;
  std::vector<DNI> contenedor(8);
  //std::vector<int> contenedor = {44, 55, 12 ,42 ,94, 18, 6 , 67};
  std::cout << "Vector antes de ordenar" << std::endl;
  mostrar(contenedor);
  std::cout << '\n';
  Heapsort(contenedor, contenedor.size());

  std::cout << '\n';
  std::cout << "Vector despues de ordenar" << std::endl;
  mostrar(contenedor);

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

template<class Clave>
void Heapsort(std::vector<Clave>& contenedor, size_t tamano)
{
  Crearheap(contenedor, tamano);
  Extraerheap(contenedor, tamano);
}

template<class Clave>
void Crearheap(std::vector<Clave>& contenedor, size_t tamano)
{
  for (unsigned x = 2; x <= tamano; ++x)
  {
    int i = x;
    int p = x/2;
    while (p > 0)
    {
      if (contenedor[p - 1] > contenedor[i - 1])
      {
        std::swap(contenedor[p - 1], contenedor[i - 1]);
      }
      else
        break;
      i = p;
      p /= 2;
    }
  }
}

template<class Clave>
void Extraerheap(std::vector<Clave>& contenedor, size_t tamano)
{
  int minimo_i;
  while (tamano > 0)
  {
    unsigned i = 1;
    std::swap(contenedor[0], contenedor[--tamano]);
    while(i*2 <= tamano)
    {
      if ((i*2 + 1) > tamano || contenedor[(i*2) - 1] < contenedor[(i*2 + 1) - 1])
        minimo_i = i*2;
      else
        minimo_i = i*2 + 1;

      if (contenedor[minimo_i - 1] < contenedor[i - 1])
      {
        std::swap(contenedor[minimo_i - 1], contenedor[i - 1]);
      }
      else
        break;
      i = minimo_i;
    }
  }
}

template<class Clave>
void mostrar(const std::vector<Clave>& contenedor)
{
  for (unsigned i = 0; i < contenedor.size(); ++i)
  {
    std::cout << contenedor[i] << '\t';
  }
  std::cout << '\n';
}
