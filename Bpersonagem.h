#include <string.h>
#include <iostream>
#include "Barma.h"
#include "Bmagia.h"
#include "Baccessdata.h"

using namespace std;

class Personagem{
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
        Arma *arma;
        Magia *magia;
        string abreArquivo(string nomeClasse);
        int * obtemAtributos(string nomeClasse);
        int esquiva(int agilidade);
        int calcularDesvio();
    public:
        Personagem(string classePersonagem);
        int atacar();
        int receberDano(int dano);
        ~Personagem();
};
