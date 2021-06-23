#include <string>
#include <iostream>
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
  int mana;
  int forca;
  int magiah;
  int armadura;
  int resistencia;
  int agilidade;
  vector<Arma> armas;
  vector<Magia> magias;

public:
  Personagem(string classePersonagem)
  {
    int qtdAtributos = 8;
    Accessdata *a = new Accessdata(qtdAtributos);
    int *atributos = a->obtemAtributos(classePersonagem);
    this->id = atributos[0];
    this->vida = atributos[1];
    this->mana = atributos[2];
    this->forca = atributos[3];
    this->magiah = atributos[4];
    this->armadura = atributos[5];
    this->resistencia = atributos[6];
    this->agilidade = atributos[7];
  }

  int calcularDesvio(int agilidade)
  {
    int a = rand() % 100;
    if (a <= agilidade)
    {
      return 1; // desvia
    }

    return 0; //nao desvia
  }

  int receberDano(int dano, int agilidade)
  {

    int esquiva = calcularDesvio(agilidade);
    if (esquiva == 0)
    {
      int danoArmaRecebido = dano * 0.2;
      if (dano > this->vida)
        this->vida = 0;
      else
        this->vida -= dano;
    }

    return 0;
  }
};
