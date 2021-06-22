#include <iostream>
#include <string.h>
#include "Bpersonagem.h"
using namespace std;

Personagem::Personagem(string classePersonagem)
{
   int qtdAtributos = 8;
   Accessdata * a = new Accessdata(qtdAtributos);
   int * atributos = a->obtemAtributos (classePersonagem);
   this->id = atributos[0];
   this->vida = atributos[1];
   this->mana = atributos[2];
   this->forca = atributos[3];
   this->magiah = atributos[4];
   this->armadura = atributos[5];
   this->resistencia = atributos[6];
   this->agilidade = atributos[7];

   delete a;
}
int Personagem::esquiva(int agilidade){
    int a;
    a = (rand() % 100);
    if(a <= agilidade){
        return 1;
    }

    return 0;
}
int Personagem::calcularDesvio(){
    
}
int Personagem::receberDano(int dano,int agilidade){

    calcularDesvio();

    int danoArmaRecebido = dano * 0.2;
    int esquiva = esquiva();
    if(dano > this->vida)
        this->vida = 0;
    else
        this->vida  -= dano;
}
Personagem::~Personagem()
{
}