#include <string>
#include <iostream>
#include <ctime>
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
    int forca;
    int magiah;
    int armadura;
    int resistencia;
    int agilidade;
    //Arma arma[];
    Magia magia[];
    string abreArquivo(string nomeClasse);
    int *obtemAtributos(string nomeClasse);
    int calcularDesvio(int agilidade);
    int verificaVida();
public:
    Personagem(string classePersonagem);
    int atacarArma();
    int receberDano(int dano,int ataque);
    // ~Personagem();
};

Personagem::Personagem(string classePersonagem)
{
    srand(time(0));
    int qtdAtributos = 8;
    Accessdata *a = new Accessdata(qtdAtributos);
    int *atributos = a->obtemAtributos(classePersonagem);
    this->id = atributos[0];
    this->vida = atributos[1];
    this->maxvida = atributos[1];
    this->mana = atributos[2];
    this->maxmana = atributos[2];
    this->forca = atributos[3];
    this->magiah = atributos[4];
    this->armadura = atributos[5];
    this->resistencia = atributos[6];
    this->agilidade = atributos[7];

    // delete a;
    // delete atributos;
}

int Personagem::calcularDesvio()
{
    int a;
    a = (rand() % 100)+1;
    if (a <= this.agilidade)
    {
        return 1; // desvia
    }

    return 0; //nao desvia
}
int Personagem::atacarArma(){
    int danoArma =0;

    int datoTolta = danoArma + (danoArma* (this->forca/100))
}
int Personagem::receberDano(int dano, int ataque)
{

    int esquiva = calcularDesvio();
    if(esquiva == 1){
        return 0;
    }

    int reducaodano;
    if(ataque == 0)
        reducaodano = this->resistencia /100;
    else
        reducaodano = this->armadura/100;

    int danoRecebido = dano - (dano * (reducaodano);

        if (danoRecebido > this->vida)
            this->vida = 0;
        else
            this->vida -= danoRecebido;

    return  danoRecebido;
}
int Personagem::verificaVida(){
    return this->vida;
}