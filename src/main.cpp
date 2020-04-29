#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "../include/DNI.hpp"
#include "../include/Algoritmos.hpp"

int Demostracion(const int&);
int Estadistica(const int&);

template<class Clave>
void Llamar_algoritmo(std::vector<Clave>&, std::string);

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
    std::cout << "Elija modo (Demostración, Estadística)" << std::endl;
    std::cin >> modo;

    if (modo == "Demostración")
      Demostracion(tamano);
    else if (modo == "Estadística")
      Estadistica(tamano);
    else
      std::cout << "Elija una opción valida" << std::endl;
  } while(modo != "Demostración" && modo != "Estadística");

  return 0;
}

int Demostracion(const int& tamano)
{
  std::cout << "|| DEMOSTRACIÓN ||" << std::endl;

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

int Estadistica(const int& tamano)
{
  std::cout << "|| ESTADÍSTICA ||" << std::endl;
  DNI::MODO = false;

  std::cout << "Numero de prueba: " << std::endl;
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
    Quicksort(BP_Quicksort, 0, BP_Quicksort.size());
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

  std::cout << "Numero de comparaciones" << std::endl;
  std::cout << "          Mínimo  Medio  Máximo" << std::endl;
  std::cout << "Método 1: " << I_minimo << "  " << I_acumulado/nPrueba << "  " << I_maximo << '\n';
  std::cout << "Método 2: " << B_minimo << "  " << B_acumulado/nPrueba << "  " << B_maximo << '\n';
  std::cout << "Método 3: " << H_minimo << "  " << H_acumulado/nPrueba << "  " << H_maximo << '\n';
  std::cout << "Método 4: " << Q_minimo << "  " << Q_acumulado/nPrueba << "  " << Q_maximo << '\n';
  std::cout << "Método 5: " << S_minimo << "  " << S_acumulado/nPrueba << "  " << S_maximo << '\n';
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
