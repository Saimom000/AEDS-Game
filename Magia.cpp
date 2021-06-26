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
  string imagemMagia;
  void fazerMagia(string nome);
public:
  Magia(string nome);
  int mostrarDanoMagia();
  int mostrarCuraMagia();
  string mostrarNomeMagia();
  int mostrarGastoManaMagia();
  string mostraImagemMagia();
};
void Magia::fazerMagia(string nome){
  if(nome == "pocao_da_vida"){
    this->imagemMagia = "\n\n           ===\n         ( + + )\n         ( + + )\n";
  }else if(nome == "halito_de_fogo"){
    this->imagemMagia = "\n\n\t  [----<<<<<\n\t  [----<<<<<\n";
  }else if(nome == "bio"){
    this->imagemMagia ="\n\n\t   - {             \n\t   |            \n\t  [ ]\n";
  }else if(nome == "cura"){
    this->imagemMagia ="\n\n\t++++++\n\t+  }{  +\n\t+++++\n";
  }else if(nome == "flama_gelada"){  
    this->imagemMagia ="\n\n\t  [:::::>>>>\n\t  [:::::>>>>\n";
  }else if(nome == "intoxicacao"){
    this->imagemMagia ="\n\n           ===\n         ( x x )\n         ( x x )\n";;
  }else if (nome == "tempestade"){
    this->imagemMagia ="\n\n              (  ;      ::     )\n        (     ;     :::      )\n      /         \\              / \n";
  }else{
      this->imagemMagia ="";
  }
}
Magia::Magia(string nome){

  srand(time(0));

  this->nome = nome;

  vector<string> list = getAttributes(nome);

  this->dano = stoi(list.at(0));
  this->cura = stoi(list.at(1));
  this->gastoMana = stoi(list.at(2));
  fazerMagia(nome);
}

int Magia::mostrarDanoMagia(){
  return this->dano;
}
int Magia::mostrarCuraMagia(){
  return this->cura;
}
string Magia::mostrarNomeMagia(){
  return this->nome;
}
int Magia::mostrarGastoManaMagia(){
  return this->gastoMana;
}
string Magia::mostraImagemMagia(){
  return this->imagemMagia;
}
