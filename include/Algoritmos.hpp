#include <iostream>
#include <vector>

#include "DNI.hpp"

template<class Clave>
void Insercion(std::vector<Clave>& contenedor, size_t tamano)
{
  for (size_t i = 1; i < tamano; ++i)
  {
    int j = i;
    while ( j > 0 && contenedor[--j] > contenedor[i])
      miswap(contenedor[j], contenedor[i--], contenedor);
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
        miswap(contenedor[j], contenedor[j + 1], contenedor);
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
      if (contenedor[p - 1] < contenedor[i - 1])
        miswap(contenedor[p - 1], contenedor[i - 1], contenedor);
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
    miswap(contenedor[0], contenedor[--tamano], contenedor);
    while(i*2 <= tamano)
    {
      if ((i*2 + 1) > tamano || contenedor[(i*2) - 1] > contenedor[(i*2 + 1) - 1])
        minimo_i = i*2;
      else
        minimo_i = i*2 + 1;

      if (contenedor[minimo_i - 1] > contenedor[i - 1])
        miswap(contenedor[minimo_i - 1], contenedor[i - 1], contenedor);
      else
        break;
      i = minimo_i;
    }
  }
}

template<class Clave>
void Shellsort(std::vector<Clave>& contenedor, size_t tamano)
{
  float alpha;
  int delta;
  do
  {
    std::cout << "¿Cual es el valor de alpha?" << std::endl;
    std::cin >> alpha;
  } while (alpha <= 0 || alpha >= 1);

  delta = tamano * alpha;
  while (delta > 1)
  {
    delta *= alpha;
    for (unsigned i = delta; i < tamano; ++i)
    {
      unsigned x = contenedor[i];
      int j = i;
      while (j >= delta && x < contenedor[j - delta])
      {
        contenedor[j] = contenedor[j - delta];
        j -= delta;
      }
      contenedor[j] = x;
    }
  }
}


template<class Clave>
void Quicksort(std::vector<Clave>& contenedor, int ini, int fin)
{
  int i = ini;
  int f = fin;
  Clave pivote = contenedor[(i + f) /2];
  while (i <= f)
  {
    while (contenedor[i] < pivote) i++;
    while (contenedor[f] > pivote) f--;
    if (i <= f)
      miswap(contenedor[i++], contenedor[f--], contenedor);
  }
  if (ini < f)
    Quicksort(contenedor, ini, f);
  if (i < fin)
    Quicksort(contenedor, i, fin);
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

template<class Clave>
void miswap(Clave& uno, Clave& dos, std::vector<Clave> contenedor)
{
  if (DNI::MODO)
    mostrar(contenedor);
  std::swap(uno, dos);
}
