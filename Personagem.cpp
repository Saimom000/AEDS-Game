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
  int resistenciaFisica;
  int resistenciaMagica;
  int agilidade;
  vector<Arma> armaAtual;
  vector<Arma> armas;
  vector<Magia> magias;
  string abreArquivo(string nomeClasse);
  int *obtemAtributos(string nomeClasse);
  int calcularDesvio(int agilidade);
  

public:
  Personagem(string nome);
  int atacarArma();
  int receberDano(int dano, int ataque);
  int usarMagia();
  int recuperaMana();
  int listarMagias();
  int verificaVida();
  void mostrarAtributos();
};

Personagem::Personagem(string nome)
{
  srand(time(0));

  this->nome = nome;

  vector<string> list = getAttributes(nome);

  this->id = stoi(list[0]);
  this->vida = stoi(list.at(1));
  this->mana = stoi(list.at(2));
  this->maxvida = stoi(list.at(1));
  this->maxmana = stoi(list.at(2));
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
  this->armaAtual.push_back(armas[0]);
  // this->armaAtual->danoMin = armas[0].danoMin;
  // this->armaAtual->danoMax = armas[0].danoMax;
  // this->armaAtual->durabilidade = armas[0].durabilidade;
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
  int danoArma = this->armaAtual[0].CalcularDano();
  //int danoArma = 500;
  //cout << danoArma;
  int datoTolta = danoArma + (danoArma * (this->forcaFisica / 100));
  //cout << "AtacarArma"<< datoTolta << "\n";
  return datoTolta;
}
int Personagem::receberDano(int dano, int ataque)
{
  int esquiva = calcularDesvio(this->agilidade);
  if (esquiva == 1)
  {
    return 0;
  }

  float reducaodano;
  //cout << "Resistencia fisica"<< this->resistenciaFisica <<"\n";
  if (ataque == 0)// tipo de dano (por arma ou magia)
    reducaodano = this->resistenciaFisica;
  else
    reducaodano = this->resistenciaMagica;
  //cout << "Reducao dano "<<reducaodano<<"\n";
  int danoRecebido = dano - ((dano * reducaodano)/100);
  //cout << "Dano recebido "<<danoRecebido<<"\n";
  if (danoRecebido > this->vida)  //tira a vida
    this->vida = 0;
  else
    this->vida -= danoRecebido;

  if(this->vida == 0){
    return -1;
  }
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
int Personagem::usarMagia()
{
  int danoArma = 0;

  int datoTolta = danoArma + (danoArma * (this->forcaFisica / 100));

  return 0;
}
////////////////montrar coisa no main
void Personagem::mostrarAtributos(){
  cout << "\nClasse do personagem: " << this->nome
      << "  Vida atual: " << this->vida <<"/"<<this->maxvida
       << "  Mana atual: " << this->mana <<"/"<<this->maxmana
       << "  Arma atual: " << this->armaAtual[0].mostraNomeArma() 
       << "\n";
}

