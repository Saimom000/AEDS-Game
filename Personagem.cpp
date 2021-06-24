#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "Arma.cpp"
#include "Magia.cpp"
#include "Accessdata.cpp"

using namespace std;

class Personagem
{
private:
  int jogador;
  int id;
  string classe;
  string nome;
  int vida;
  int maxmana;
  int mana;
  int maxvida;
  int forcaFisica;
  int forcaMagica;
  int magiah;
  int armadura;
  int resistenciaFisica;
  int resistenciaMagica;
  int agilidade;
  vector<Arma> armas;
  vector<Magia> magias;
  string abreArquivo(string nomeClasse);
  int *obtemAtributos(string nomeClasse);
  int calcularDesvio(int agilidade);
  int verificaVida();

public:
  Personagem(string nome);
  int atacarArma();
  int receberDano(int dano, int ataque);
  int recuperaMana();
};

Personagem::Personagem(string nome)
{
  srand(time(0));

  this->nome = nome;

  vector<string> list = getAttributes(nome);

  this->id = stoi(list[0]);
  this->vida = stoi(list.at(1));
  this->mana = stoi(list.at(2));
  this->forcaFisica = stoi(list.at(3));
  this->forcaMagica = stoi(list.at(4));
  this->resistenciaFisica = stoi(list.at(5));
  this->resistenciaMagica = stoi(list.at(6));
  this->agilidade = stoi(list.at(7));
  // this->maxmana = stoi(list.at(4));
  // this->maxvida = stoi(list.at(2));

  for (int i = 8; i < list.size(); i++)
  {
    Arma *arma = new Arma(list.at(i));
    armas.push_back(*arma);
  }
}

int Personagem::calcularDesvio(int agilidade)
{
  int a = (rand() % 100) + 1;
  if (a <= agilidade)
  {
    return 1; // desvia
  }

  return 0; //nao desvia
}
int Personagem::atacarArma()
{
  int danoArma = 0;

  int datoTolta = danoArma + (danoArma * (this->forcaFisica / 100));

  return 0;
}
int Personagem::receberDano(int dano, int ataque)
{
  int esquiva = calcularDesvio(this->agilidade);
  if (esquiva == 1)
  {
    return 0;
  }

  int reducaodano;
  if (ataque == 0)
    reducaodano = this->resistenciaFisica / 100;
  else
    reducaodano = this->armadura / 100;

  int danoRecebido = dano - (dano * (reducaodano));

  if (danoRecebido > this->vida)
    this->vida = 0;
  else
    this->vida -= danoRecebido;

  return danoRecebido;
}
int Personagem::verificaVida()
{
  return this->vida;
}
int Personagem::recuperaMana()
{
  if (this->mana < this->maxmana - 10)
  {
    this->mana += 10;
  }
  else
  {
    this->mana = this->maxmana;
  }
  return 0;
}
