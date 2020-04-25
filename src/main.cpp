#include <iostream>
#include <string>
int Demostracion();
int Estadistica();

int main()
{
  std::string modo;
  do{
  std::cout << "Elija modo (Demostración, Estadística)" << std::endl;
  std::cin >> modo;
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
  return 0;
}

int Estadistica()
{
  std::cout << "Estoy en estadistica" << std::endl;
  return 0;
}
