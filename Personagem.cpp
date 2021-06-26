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
  int calcularDesvio(int agilidade);//arma
  void voltarArmaInicial();//arma
  void regeneraMana();//magia
  int chanseBulKathos();//arma lendaria
  int imprimirbencaoBulKathos();//arma lendaria
  

public:
  Personagem(string nome);
  int mostrarAtributos(string jogadoratual);//menu
  int receberDano(int dano, int ataque);//magia e arma
  int usarMagia(int nummagia);//magia
  void listarMagias();//magia
  int atacarArma(int lenda);//arma
  void semDurabilidade();//arma
  void trocarArma();//arma
  

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
  this->quantidadeArmas = stoi(list.at(8));
  // this->maxmana = stoi(list.at(4));
  // this->maxvida = stoi(list.at(2));
  int soma = 9 + this->quantidadeArmas;
  
  for (int i = 9; i < soma; i++)
  {
    Arma *arma = new Arma(list.at(i));
    armas.push_back(*arma);
  }
  for (int i = soma; i < list.size(); i++)
  {
    Magia *magia = new Magia(list.at(i));
    magias.push_back(*magia);
  }
  this->armaAtual.push_back(armas[0]);
  //vector<string> list1 = getAttributes("Voto_Solene_de_Bul_Kathos");
  ArmaLendaria *lenda = new ArmaLendaria("Voto_Solene_de_Bul_Kathos");
  lendaria.push_back(*lenda);
  //cout << lendaria[0].mostraNomeArma();

}
////////////////////////////////RegeneraMana//////////////////////////////////////
void Personagem::regeneraMana(){//regenera mana se não usar magia
  if(this->mana != this->maxmana){
    cout << "Mana +10\n";
  }
  if(this->mana + 10 <= this->maxmana){
    this->mana += 10;
  }else{
    this->mana = this->maxmana;
  }
  
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
  regeneraMana();
  
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
  cout << "Nova arma: " << this->armaAtual[0].mostraNomeArma() <<"\n";
  regeneraMana();
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
       <<"\nDano bruto: "<< this->armaAtual[0].mostraDanoMinArma()<<" - " <<this->armaAtual[0].mostraDanoMaxArma()
       << "  " << this->armaAtual[0].mostraImagemArma()
         << "\n";
  }else{
    cout << "\nArma: " << this->lendaria[0].mostraNomeArma()
       << "  Durabilidade: " << this->lendaria[0].mostraDurabiArma()
       <<"\nDano bruto: "<< this->lendaria[0].mostraDanoMinArma()<<" - " <<this->lendaria[0].mostraDanoMaxArma()
       << "  " << this->lendaria[0].mostraImagemArma()
         <<"\n\nVoce adquiriu a BENCAO DE BUL-KATHOS\n";
         return 1;
  }
  
  return 0;
}
////////////////////////////////////////MAGIA/////////////////////////////////////
void Personagem::listarMagias(){
  cout << "\nEscolha uma Magia:\n";
  for (int i = 0; i < this->magias.size(); i++)
  {
    cout << i+1 <<" - " << this->magias[i].mostrarNomeMagia() << "\nCusto: " << this->magias[i].mostrarGastoManaMagia();
    if(this->magias[i].mostrarDanoMagia() != 0){
      cout << " Dano: "<< this->magias[i].mostrarDanoMagia();
    }else{
      cout << " Cura: "<< this->magias[i].mostrarCuraMagia();
    }
    cout <<"\n\n";
  }
  cout << "0 - Voltar\n";
}
int Personagem::usarMagia(int nummagia)
{
  nummagia-= 1;
  int danoMagia = 0;
  if(nummagia >= 0 && nummagia < this->magias.size()){
    danoMagia = this->magias[nummagia].mostrarDanoMagia();
    if(this->mana - this->magias[nummagia].mostrarGastoManaMagia() < 0){
      return -2;
    }else if(this->magias[nummagia].mostrarDanoMagia() != 0){
      danoMagia = danoMagia + (danoMagia * (this->forcaMagica / 100));
    }else{
      if(this->magias[nummagia].mostrarCuraMagia() + this->vida > this->maxvida){
        this-> vida = this->maxvida;
      }else{
        this->vida += this->magias[nummagia].mostrarCuraMagia();
      }
      this->mana -= this-> magias[nummagia].mostrarGastoManaMagia();
      cout << this-> magias[nummagia].mostraImagemMagia();
      return -1;
    }
    this->mana -= this-> magias[nummagia].mostrarGastoManaMagia();
    cout << this-> magias[nummagia].mostraImagemMagia();
  }else{
    cout << "Numero invalido, digite novamente\n";
    return 0;
  }
  
  //cout <<"Dano Magia"<<danoMagia<<"\n";
  return danoMagia;
}
/////////////////////////////////////////Calculo de Arma e Magia //////////////////////////////////
int Personagem::receberDano(int dano, int ataque)
{
  int danoRecebido=0;
  int esquiva = calcularDesvio(this->agilidade);
  if (esquiva == 1 && ataque == 0)
  {
    return 0;
  }

  float reducaodano;

  if (ataque == 0)// tipo de dano (por arma ou magia)
    reducaodano = this->resistenciaFisica;
  else
    reducaodano = this->resistenciaMagica;

  if(dano > 0){
    danoRecebido = dano - ((dano * reducaodano)/100);
    //cout << "Dano recebido "<<danoRecebido<<"\n";
    if (danoRecebido > this->vida)  //tira a vida
      this->vida = 0;
    else
      this->vida -= danoRecebido;

    if(this->vida == 0){//morreu
      return -1;
    }
  }else if(dano == -1){//cura
    return -2;
  }else if(dano == -2){//sem mana
    return -3;
  }else if(dano == 0){//numero invalido
    return -4;
  }
  return danoRecebido;
}
////////////////montrar coisa no main/////////////////////////////////////////
int Personagem::mostrarAtributos(string jogadoratual){
  cout << "\n\n-------------------"<< jogadoratual <<"------------------------";
  cout << "\nPersonagem: " << this->nome
      << " \nVida: " << this->vida <<"/"<<this->maxvida
       << "  Mana: " << this->mana <<"/"<<this->maxmana;
       return imprimirbencaoBulKathos();
}

