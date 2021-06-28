#pragma once

#include <iostream>
#include <string>

#include "Accessdata.cpp"
#include "Arma.cpp"

using namespace std;

class ArmaLendaria : public Arma
{
private:
  int chanseCritico;
  int danoCritico;
  int chanseDrop;

public:
  ArmaLendaria(string nomeArma);
  int CalcularDano() override;
  int DropLendaria();
};

ArmaLendaria::ArmaLendaria(string nomeArma) : Arma(nomeArma)
{
  srand(time(0));

  this->chanseCritico = 30;
  this->danoCritico = 100;
  this->chanseDrop = 20;
}
int ArmaLendaria::CalcularDano()
{
  // durabilidade -= 1;
  int dano = danoMin + (rand() % (danoMax - danoMin + 1));
  int chanceDeCritico = (rand() % 100) + 1;

  if (chanceDeCritico <= this->chanseCritico)
    dano += dano * (this->danoCritico / 100);

  return dano;
}
int ArmaLendaria::DropLendaria()
{
  return this->chanseDrop;
}
