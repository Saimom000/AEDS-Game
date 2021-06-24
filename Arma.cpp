#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "Accessdata.cpp"

using namespace std;

class Arma
{
protected:
  string nome;
  int danoMin;
  int danoMax;
  int durabilidade;

public:
  Arma(string nome);
  virtual int CalcularDano();
};

Arma::Arma(string nome)
{
  srand(time(0));

  this->nome = nome;

  vector<string> list = getAttributes(nome);

  this->danoMin = stoi(list.at(0));
  this->danoMax = stoi(list.at(1));
  this->durabilidade = stoi(list.at(2));
}
int Arma::CalcularDano()
{
  this->durabilidade -= 1;
  return this->danoMin + (rand() % (this->danoMax - this->danoMin + 1));
}
