#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "Arma.cpp"
#include "Magia.cpp"
#include "ArmaLendaria.cpp"
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
  int quantidadeArmas;
  vector<Arma> armaAtual;
  vector<Arma> armas;
  vector<Magia> magias;
  vector<ArmaLendaria> lendaria;
  //string abreArquivo(string nomeClasse);
  //int *obtemAtributos(string nomeClasse);
  int recuperaMana();//magia
  int calcularDesvio(int agilidade);//arma
  void voltarArmaInicial();//arma
  

public:
  Personagem(string nome);
  int mostrarAtributos();//menu
  int receberDano(int dano, int ataque);//magia e arma
  int usarMagia();//magia
  int listarMagias();//magia
  int atacarArma(int lenda);//arma
  void semDurabilidade();//arma
  void trocarArma();//arma
  int chanseBulKathos();
  int imprimirbencaoBulKathos();//arma lendaria

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
  //vector<string> list1 = getAttributes("Voto_Solene_de_Bul_Kathos");
  ArmaLendaria *lenda = new ArmaLendaria("Voto_Solene_de_Bul_Kathos");
  lendaria.push_back(*lenda);
  //cout << lendaria[0].mostraNomeArma();

}
/////////////////////////////////ARMA//////////////////////////////////////////////
void Personagem::voltarArmaInicial(){

  this->armaAtual.clear();
  this->armaAtual.push_back(armas[0]);
  
}
void Personagem::semDurabilidade(){
  if(this->armaAtual[0].mostraDurabiArma() == 0){
    
    if(this->armaAtual[0].mostraNomeArma() != this->armas[0].mostraNomeArma()){
      cout << "\nA durabilidade da sua arma acabou, voce voltou para sua arma inicial.\n";
    }
    voltarArmaInicial();
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
int Personagem::atacarArma(int lenda)
{
  int danoArma = 0;
  if(lenda == 1){
    danoArma = this->lendaria[0].CalcularDano();
  }else{
    danoArma = this->armaAtual[0].CalcularDano();
  }
  
  
  //cout << danoArma;
  int datoTolta = danoArma + (danoArma * (this->forcaFisica))/ 100;
  //cout << "AtacarArma"<< datoTolta << "\n";
  return datoTolta;
}
void Personagem::trocarArma(){
  int a = (rand() % (armas.size()-1)) + 1;
  //cout <<"Aleatorio" << a <<" Tamanho" <<armas.size() ;
  this->armaAtual.clear();
  this->armaAtual.push_back(armas[a]);
  cout << "Nova arma:" << this->armaAtual[0].mostraNomeArma() <<"\n";
}
int Personagem::chanseBulKathos(){
  int a = (rand() % 100) + 1;
  int chanse = this->lendaria[0].DropLendaria();
  if(a <= chanse){
    return 1;
  }
  return 0;
}
int Personagem::imprimirbencaoBulKathos(){
  int a = chanseBulKathos();
  if(a == 0){
    cout << "\nArma: " << this->armaAtual[0].mostraNomeArma()
       << "  Durabilidade: " << this->armaAtual[0].mostraDurabiArma()
       << "  " << this->armaAtual[0].mostraImagemArma()
         << "\n";
  }else{
    cout << "\nArma: " << this->lendaria[0].mostraNomeArma()
       << "  Durabilidade: " << this->lendaria[0].mostraDurabiArma()
       << "  " << this->lendaria[0].mostraImagemArma()
         <<"\n\nVoce adquiriu a BENCAO DE BUL-KATHOS\n";
         return 1;
  }
  
  return 0;
}
////////////////////////////////////////MAGIA/////////////////////////////////////
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

/////////////////////////////////////////Calculo de Arma e Magia //////////////////////////////////
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
////////////////montrar coisa no main/////////////////////////////////////////
int Personagem::mostrarAtributos(){
  cout << "\n\n-----------------------------------------------------";
  cout << "\nPersonagem: " << this->nome
      << " \nVida: " << this->vida <<"/"<<this->maxvida
       << "  Mana: " << this->mana <<"/"<<this->maxmana;
       return imprimirbencaoBulKathos();
}

