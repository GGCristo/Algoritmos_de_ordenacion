#include "../include/DNI.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
DNI::DNI ()
{
  Valor_ = rand() % 100;
}
bool DNI::operator == (const DNI& dni)
{
  return Valor_ == dni.Valor_;
}
