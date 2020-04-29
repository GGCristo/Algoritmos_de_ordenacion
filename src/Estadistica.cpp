#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

#include "../include/DNI.hpp"
#include "../include/Algoritmos.hpp"

int Estadistica(const int& tamano)
{
  std::cout << "|| ESTADÍSTICA ||" << '\n';
  DNI::MODO = false;

  std::cout << "Numero de pruebas: " << '\n';
  int nPrueba;
  std::cin >> nPrueba;

  unsigned I_minimo = std::numeric_limits<unsigned>::max(), B_minimo = std::numeric_limits<unsigned>::max(),
           H_minimo = std::numeric_limits<unsigned>::max(), Q_minimo = std::numeric_limits<unsigned>::max(),
           S_minimo = std::numeric_limits<unsigned>::max();
  unsigned I_maximo = std::numeric_limits<unsigned>::min(), B_maximo = std::numeric_limits<unsigned>::min(),
           H_maximo = std::numeric_limits<unsigned>::min(), Q_maximo = std::numeric_limits<unsigned>::min(),
           S_maximo = std::numeric_limits<unsigned>::min();
  unsigned I_acumulado = 0, B_acumulado = 0, H_acumulado = 0, Q_acumulado = 0, S_acumulado = 0;

  for (int i = 0; i < nPrueba; ++i)
  {
    std::vector<DNI> BP_Insercion(tamano);
    Insercion(BP_Insercion, BP_Insercion.size());
    if (DNI::CONTADOR < I_minimo) I_minimo = DNI::CONTADOR;
    if (DNI::CONTADOR > I_maximo) I_maximo = DNI::CONTADOR;
    I_acumulado += DNI::CONTADOR;
    DNI::CONTADOR = 0;
  }

  for (int i = 0; i < nPrueba; ++i)
  {
    std::vector<DNI> BP_Burbuja(tamano);
    Burbuja(BP_Burbuja, BP_Burbuja.size());
    if (DNI::CONTADOR < B_minimo) B_minimo = DNI::CONTADOR;
    if (DNI::CONTADOR > B_maximo) B_maximo = DNI::CONTADOR;
    B_acumulado += DNI::CONTADOR;
    DNI::CONTADOR = 0;
  }

  for (int i = 0; i < nPrueba; ++i)
  {
    std::vector<DNI> BP_Heapsort(tamano);
    Heapsort(BP_Heapsort, BP_Heapsort.size());
    if (DNI::CONTADOR < H_minimo) H_minimo = DNI::CONTADOR;
    if (DNI::CONTADOR > H_maximo) H_maximo = DNI::CONTADOR;
    H_acumulado += DNI::CONTADOR;
    DNI::CONTADOR = 0;
  }

  for (int i = 0; i < nPrueba; ++i)
  {
    std::vector<DNI> BP_Quicksort(tamano);
    Quicksort(BP_Quicksort, 0, BP_Quicksort.size() - 1);
    if (DNI::CONTADOR < Q_minimo) Q_minimo = DNI::CONTADOR;
    if (DNI::CONTADOR > Q_maximo) Q_maximo = DNI::CONTADOR;
    Q_acumulado += DNI::CONTADOR;
    DNI::CONTADOR = 0;
  }

  for (int i = 0; i < nPrueba; ++i)
  {
    std::vector<DNI> BP_Shellsort(tamano);
    Shellsort(BP_Shellsort, BP_Shellsort.size());
    if (DNI::CONTADOR < S_minimo) S_minimo = DNI::CONTADOR;
    if (DNI::CONTADOR > S_maximo) S_maximo = DNI::CONTADOR;
    S_acumulado += DNI::CONTADOR;
    DNI::CONTADOR = 0;
  }

  std::cout << "Número de comparaciones:"         << '\n';
  std::cout << "          Mínimo  Medio  Máximo" << '\n';
  std::cout << "Insercion: " << std::right << std::setw(5) << I_minimo << std::setw(7) << I_acumulado/nPrueba << std::setw(8) << I_maximo << '\n';
  std::cout << "Burbuja:   " << std::setw(5) << B_minimo << std::setw(7) << B_acumulado/nPrueba << std::setw(8) << B_maximo << '\n';
  std::cout << "Heapsort:  " << std::setw(5) << H_minimo << std::setw(7) << H_acumulado/nPrueba << std::setw(8) << H_maximo << '\n';
  std::cout << "Quicksort: " << std::setw(5) << Q_minimo << std::setw(7) << Q_acumulado/nPrueba << std::setw(8) << Q_maximo << '\n';
  std::cout << "Shellsort: " << std::setw(5) << S_minimo << std::setw(7) << S_acumulado/nPrueba << std::setw(8) << S_maximo << '\n';
  return 0;
}
