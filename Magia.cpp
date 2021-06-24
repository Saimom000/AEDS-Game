#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "Accessdata.cpp"

class Magia
{
private:
  string nome;
  int dano;
  int cura;
  int gastoMana;

public:
  Magia(string nome);
  int causarDanoMagia();
  int causarCuraMagia();
};

Magia::Magia(string nome){

  srand(time(0));

  this->nome = nome;

  vector<string> list = getAttributes(nome);

  this->dano = stoi(list.at(0));
  this->cura = stoi(list.at(1));
  this->gastoMana = stoi(list.at(2));
}

int Magia::causarDanoMagia(){
  return this->dano;
}
int Magia::causarCuraMagia(){
  return this->cura;
}
