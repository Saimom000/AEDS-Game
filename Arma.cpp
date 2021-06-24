#pragma once

#include <iostream>
#include <string>
#include <ctime>

#include "Accessdata.cpp"

using namespace std;

class Arma
{
protected:
    int id;
    string nome;
    int danomin;
    int danomax;
    int durabilidade;
    int *listaPerso;

public:
    Arma(string nomeArma);
    virtual int CalcularDano();
};

Arma::Arma(string nomeArma)
{
    srand(time(0));
    this->nome = nomeArma;

    int qtdAtributos = 10;
    Accessdata *a = new Accessdata(qtdAtributos);
    int *atributos = a->obtemAtributos(nomeArma);
    this->danomax = atributos[0];
    this->danomin = atributos[1];
    this->durabilidade = 3;
    this->listaPerso = new int[8];
    int j = 0;
    for (int i = 2; i < qtdAtributos; i++)
    {
        listaPerso[j++] = atributos[i];
    }
    
    delete a;
    delete atributos;
}
int Arma::CalcularDano()
{
    this->durabilidade -= 1;
    return (this->danomin + (rand() % (this->danomax - this->danomin + 1)));
}
