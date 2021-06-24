#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

class Accessdata
{
private:
  int *atributos;
  int qtdAtributos;
  string abreArquivo(string nomeDaClasse);

public:
  Accessdata(int qtdAtributos);
  int *obtemAtributos(string nomeDaClasse);
};

Accessdata::Accessdata(int qtdAtributos)
{
  //você deverá retorar este vetor de atributos para dentro do seu programa no momento de instanciar um novo personagem
  this->qtdAtributos = qtdAtributos;
  this->atributos = new int[qtdAtributos]; //quantidade de atributos das classes do jogo
}

string Accessdata::abreArquivo(string nomeDaClasse)
{
  fstream arq;

  arq.open(nomeDaClasse, ios::in);

  string linha;

  //Faz a leitura linha a linha do arquivo texto (string linha armazena a linha lida do arquivo)
  if (arq.is_open())
  {
    getline(arq, linha);
  }

  arq.close();

  return linha;
}

int *Accessdata::obtemAtributos(string nomeDaClasse)
{
  string s = abreArquivo(nomeDaClasse);
  string delimiter = ",";

  size_t pos = 0;
  int i = 0;
  while ((pos = s.find(delimiter)) != std::string::npos)
  {
    string token = s.substr(0, pos);
    this->atributos[i++] = stoi(token);
    s.erase(0, pos + delimiter.length());
  }

  return this->atributos;
}
