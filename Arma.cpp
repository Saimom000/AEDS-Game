#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stdio.h>

#include "Accessdata.cpp"

using namespace std;

class Arma
{
protected:
  string nome;
  int danoMin;
  int danoMax;
  int durabilidade;
  string imagemArma;
  void fazerArmas(string nome);
public:
  Arma(string nome);
  virtual int CalcularDano();
  string mostraNomeArma();
  string mostraImagemArma();
  int mostraDurabiArma();
  int mostraDanoMinArma();
  int mostraDanoMaxArma();
  void semDurabilidade();
  ~Arma();
};
void Arma::fazerArmas(string nome){
  if(nome == "espada_barroca"){
    this->imagemArma = "\n\n         <==[-------\n";
  }else if(nome == "porrete"){
    this->imagemArma = "\n\n         =|:::::::\n";
  }else if(nome == "cajado"){
    this->imagemArma ="\n\n            0 \n           /\n";
  }else if(nome == "tridente_sagrado"){
    this->imagemArma ="\n\n         +----{-\n";
  }else if(nome == "besta"){  
    this->imagemArma ="\n\n         =,===}->\n";
  }else if(nome == "esfera_de_ataque"){
    this->imagemArma ="\n\n            (@)\n";
  }else if (nome == "garra_letal"){
    this->imagemArma ="\n\n              {=\n";
  }else if(nome == "Voto_Solene_de_Bul_Kathos"){
      this->imagemArma ="\n\n   <===/'''''''''''''''/\n       `''''''''''''''`";
  }else{
      this->imagemArma ="";
  }
}
Arma::Arma(string nome)
{
  srand(time(0));

  this->nome = nome;

  vector<string> list = getAttributes(nome);

  this->danoMin = stoi(list.at(0));
  this->danoMax = stoi(list.at(1));
  this->durabilidade = stoi(list.at(2));
  fazerArmas(nome);
  //cout <<"Danomin" <<this->danoMin;
}
int Arma::CalcularDano()
{
  this->durabilidade -= 1;
  
  int numeromax = this->danoMax - this->danoMin + 1;
  int calculo = this->danoMin + (rand() % numeromax);
  //cout <<"CalculoDano"<< calculo <<"\n";
  return calculo;
}


////mostra coisa no main
string Arma::mostraNomeArma(){
  return this->nome;
}
string Arma::mostraImagemArma(){
  return this->imagemArma;
}
int Arma::mostraDanoMaxArma(){
  return this->danoMax;
}
int Arma::mostraDanoMinArma(){
  return this->danoMin;
}
int Arma::mostraDurabiArma(){
  return this->durabilidade;
}

Arma::~Arma(){

}