#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "Arma.cpp"
#include "Magia.cpp"
#include "ArmaLendaria.cpp"
#include "Accessdata.cpp"

const int TURNOS_ULT = 10;

using namespace std;

class Personagem
{
private:
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
  int turnosUlt = TURNOS_ULT;
  Arma *ult = NULL;
  Magia *ultMagia = NULL;
  vector<Arma> armaAtual;
  vector<Arma> armas;
  vector<Magia> magias;
  vector<ArmaLendaria> lendaria;
  int calcularDesvio(int agilidade); // arma
  void voltarArmaInicial();          // arma
  void regeneraMana();               // magia
  int chanseBulKathos();             // arma lendaria
  int imprimiArmas();                // arma lendaria
  int quantidadeArmaTroca();         // arma
public:
  Personagem(string nome);
  int mostrarAtributos(string jogadoratual); // menu
  int receberDano(int dano, int ataque);     // magia e arma
  int usarMagia(int nummagia);               // magia
  void listarMagias();                       // magia
  int atacarArma(int lenda);                 // arma
  void semDurabilidade();                    // arma
  void trocarArma();                         // arma
  void descansar();                          // cura 120 de vida
  string retornaNome();                      // retorna o nome
  int verificaArmaTroca();                   // arma
  void mostrarTodosAtributos();              // printa todos os atributos dos 2 jogadores
  void montarUltimates();                    // ulti
  int retornaturnosUlt();                    // ulti
  void mostraUlti(string nome);              // teste
  Arma *retornaUlt();                        // ulti
  int atacaUlt();                            // ulti
  void resetaUlt();                          // ulti
};
Personagem::Personagem(string nome)
{
  srand(time(0));

  this->nome = nome;

  vector<string> list = getAttributes(nome);

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

  ArmaLendaria *lenda = new ArmaLendaria("Voto_Solene_de_Bul_Kathos");
  lendaria.push_back(*lenda);

  // ===== ULT =====

  if (nome == "guerreiro")
  {
    ult = new Arma("ult_guerreiro");

    ult;
  }
  else if (nome == "ladrao")
  {
    ult = new Arma("ult_ladrao");
  }
  else if (nome == "mago")
  {
    ultMagia = new Magia("ult_mago");
  }
  else if (nome == "paladino")
  {
    ultMagia = new Magia("ult_paladino");
  }
  else if (nome == "animal")
  {
    ult = new Arma("ult_animal");
  }
  else if (nome == "troll")
  {
    ult = new Arma("ult_troll");
  }
  else if (nome == "dragao")
  {
    ult = new Arma("ult_dragao");
  }
  else if (nome == "zumbi")
  {
    ultMagia = new Magia("ult_zumbi");
  }
}
///////////////////////////////////////////////Imagem Ulti/////////////////////////////////////////
void Personagem::mostraUlti(string nome)
{
  if (nome == "guerreiro")
  {
    cout << endl
         << "Ulti: Espada do Rei Destruido" << endl;
    cout << endl
         << "      /\\---------------------------------\\"
         << endl
         << "<====={} ------------>                    |"
         << endl
         << "      \\/---------------------------------/ "
         << endl;
  }
  else if (nome == "ladrao")
  {
    cout << endl
         << "Ulti: Veneno de dois Gumes" << endl;
    cout << endl
         << " </^^^^^^^^^^\\                        /^^^^^^^^^^\\>"
         << endl
         << "<| }{  }{  }{ |=======()>  <()=======| }{  }{  }{ |>"
         << endl
         << "  `^^^^^^^^^^^`                       `^^^^^^^^^^^`"
         << endl;
  }
  else if (nome == "mago")
  {
    cout << endl
         << "Ulti: Explosao Primordial" << endl;
    cout << endl
         << "                            </=-------=\\>"
         << endl
         << "<===============()=()=()=()=|( @ @ )"
         << endl
         << "                            <\\=-------=/>"
         << endl;
  }
  else if (nome == "paladino")
  {
    cout << endl
         << "Ulti: Protecao da Aurora" << endl;
    cout << endl
         << "      /T\\"
         << endl
         << "     / - \\"
         << endl
         << "    /= - =\\"
         << endl
         << "   / = - = \\"
         << endl
         << " (  =  0  =  )"
         << endl
         << "(   =  0  =   )"
         << endl
         << " (  =  0  =  )"
         << endl
         << "   \\ = - = /"
         << endl
         << "    \\= - =/"
         << endl
         << "     \\ - /"
         << endl
         << "      \\T/"
         << endl;
  }
  else if (nome == "animal")
  {
    cout << endl
         << "Ulti: Emissario da Tempestade" << endl;
    cout << endl
         << "         /\\\\"
         << endl
         << "        /   \\\\"
         << endl
         << "       /     \\\\"
         << endl
         << "  >---{-------||--->"
         << endl
         << "       \\     //"
         << endl
         << "        \\   //"
         << endl
         << "         \\//"
         << endl;
  }
  else if (nome == "troll")
  {
    cout << endl
         << "Ulti: Subjugar" << endl;
    cout << endl
         << "  ________________/::::::::::::::::::::::::\\)"
         << endl
         << " |----------------|@@@@@@@@@@@@@@@@@@@@@@@@|)"
         << endl
         << "  ^^^^^^^^^^^^^^^^\\::::::::::::::::::::::::/)"
         << endl;
  }
  else if (nome == "dragao")
  {
    cout << endl
         << "Ulti: Coercao Infinita" << endl;
    cout << endl
         << "   <==\\====0==|        |==0====/==>"
         << endl
         << " <=====\\===0==|        |==0===/=====>"
         << endl
         << "<======|===0==|        |==0===|======>"
         << endl
         << " <=====/===0==|        |==0===\\=====>"
         << endl
         << "    <==/===0==|        |==0====\\==>"
         << endl;
  }
  else if (nome == "zumbi")
  {
    cout << endl
         << "Ulti: Aperto Mortal" << endl;
    cout << endl
         << "       / ` \\- ``\\` ``.-.__."
         << endl
         << "    _-`|    |    | \\   \\.  \\"
         << endl
         << " /`   ` \\ _ / \\_ / -\\ _/ \\_ /"
         << endl
         << " \\   `\\               /  "
         << endl
         << "  \\_ _/  _    .   __/"
         << endl
         << "  /              /"
         << endl;
  }
}
////////////////////////////////RegeneraMana//////////////////////////////////////
void Personagem::regeneraMana()
{ // regenera mana se não usar magia
  if (this->mana != this->maxmana)
  {
    cout << "Mana +10\n";
  }
  if (this->mana + 10 <= this->maxmana)
  {
    this->mana += 10;
  }
  else
  {
    this->mana = this->maxmana;
  }
}
/////////////////////////////////ARMA//////////////////////////////////////////////
void Personagem::voltarArmaInicial()
{
  this->armaAtual.clear();
  this->armaAtual.push_back(armas[0]);
}
void Personagem::semDurabilidade()
{ // verifica se a durabilidade de arma atual acabou, se for a arma base nao mostra mensagem
  if (this->armaAtual[0].mostraDurabiArma() == 0)
  {
    if (this->armaAtual[0].mostraNomeArma() != this->armas[0].mostraNomeArma())
      cout << "\nA durabilidade da sua arma acabou, voce voltou para sua arma inicial.\n";

    voltarArmaInicial();
  }
}
int Personagem::calcularDesvio(int agilidade)
{
  int a = (rand() % 100) + 1;

  if (a <= agilidade)
    return 1; // desvia

  return 0; // nao desvia
}
int Personagem::atacarArma(int lenda)
{
  int danoArma = 0;
  if (lenda == 2)
    danoArma = (*this->ult).CalcularDano();
  else if (lenda == 1)
    danoArma = this->lendaria[0].CalcularDano();
  else
    danoArma = this->armaAtual[0].CalcularDano();

  regeneraMana();

  int datoTolta = danoArma + (danoArma * (this->forcaFisica)) / 100;

  return datoTolta;
}
int Personagem::verificaArmaTroca()
{
  if (this->armas.size() - 1 == 0)
    return 0;

  return 1;
}
void Personagem::trocarArma()
{
  if (verificaArmaTroca() == 1)
  {
    int a = (rand() % (armas.size() - 1)) + 1; // nao dropa para a arma inicial

    this->armaAtual.clear();
    this->armaAtual.push_back(armas[a]);

    cout << "Nova arma: " << this->armaAtual[0].mostraNomeArma() << "\n";

    regeneraMana();
  }
}
int Personagem::chanseBulKathos()
{
  int a = (rand() % 100) + 1;
  int chanse = this->lendaria[0].DropLendaria();
  if (a <= chanse)
    return 1; // vai dropar a arma lendaria

  return 0;
}
int Personagem::imprimiArmas()
{
  int a = chanseBulKathos();

  if (a == 0)
  { // mostra as caracteristicas da arma comum
    cout << "\nArma: " << this->armaAtual[0].mostraNomeArma()
         << "  Durabilidade: " << this->armaAtual[0].mostraDurabiArma()
         << "\nDano bruto: " << this->armaAtual[0].mostraDanoMinArma() << " - " << this->armaAtual[0].mostraDanoMaxArma()
         << "  " << this->armaAtual[0].mostraImagemArma()
         << "\n";
  }
  else
  {
    cout << "\nArma: " << this->lendaria[0].mostraNomeArma()
         << "  Durabilidade: ate o fim do turno"
         << "\nDano bruto: " << this->lendaria[0].mostraDanoMinArma() << " - " << this->lendaria[0].mostraDanoMaxArma()
         << "  " << this->lendaria[0].mostraImagemArma()
         << "\n\nVoce adquiriu a BENCAO DE BUL-KATHOS\n";
    return 1;
  }

  return 0;
}
int Personagem::quantidadeArmaTroca()
{
  return this->armas.size() - 1;
}
////////////////////////////////////////MAGIA/////////////////////////////////////
void Personagem::listarMagias()
{
  cout << "\nEscolha uma Magia:\n";
  for (int i = 0; i < this->magias.size(); i++)
  {
    cout << i + 1 << " - " << this->magias[i].mostrarNomeMagia() << "\nCusto: " << this->magias[i].mostrarGastoManaMagia();
    if (this->magias[i].mostrarDanoMagia() != 0)
    { // se dano for igual a 0 é magia de cura
      cout << " Dano: " << this->magias[i].mostrarDanoMagia();
    }
    else
    {
      cout << " Cura: " << this->magias[i].mostrarCuraMagia();
    }

    cout << "\n\n";
  }

  cout << "0 - Voltar\n";
}
int Personagem::usarMagia(int nummagia)
{
  nummagia -= 1; // o usuario digitou magia 1, 2 ou 3, ai o nummagia-= 1; volta da ordem certa no vetor

  int danoMagia = 0;

  if (nummagia >= 0 && nummagia <= this->magias.size())
  { // verifica se o numero digitado foi valido
    danoMagia = this->magias[nummagia].mostrarDanoMagia();

    if (nummagia == this->magias.size())
    {
      danoMagia = (*this->ultMagia).mostrarDanoMagia();
      danoMagia = danoMagia + (danoMagia * (this->forcaMagica) / 100);
      return danoMagia;
    }
    else if (this->mana - this->magias[nummagia].mostrarGastoManaMagia() < 0)
    { // verifica se tem mana suficiente para usar a magia
      return -2;
    }
    else if (this->magias[nummagia].mostrarDanoMagia() != 0)
    { // se dano for igual a 0 é magia de cura
      danoMagia = danoMagia + (danoMagia * (this->forcaMagica) / 100);
    }
    else
    {
      if (this->magias[nummagia].mostrarCuraMagia() + this->vida > this->maxvida)
      { // a cura nao passa do limite de vida
        this->vida = this->maxvida;
      }
      else
      {
        this->vida += this->magias[nummagia].mostrarCuraMagia(); // cura
      }

      this->mana -= this->magias[nummagia].mostrarGastoManaMagia(); // tira a mana gasta do jogador ex: 100/100 vira 88/100
      cout << this->magias[nummagia].mostraImagemMagia();

      // mostra a imagem da magia

      return -1;
    }

    this->mana -= this->magias[nummagia].mostrarGastoManaMagia(); // tira a mana gasta do jogador ex: 100/100 vira 88/100
    cout << this->magias[nummagia].mostraImagemMagia();           // mostra a imagem da magia
  }
  else
  {
    cout << "Numero invalido, digite novamente\n";
    return 0;
  }

  return danoMagia;
}
/////////////////////////////////////////Calculo de Arma e Magia //////////////////////////////////
int Personagem::receberDano(int dano, int ataque)
{
  // ataque = 1 dano de magia, ataque = 0 dano fisico

  int danoRecebido = 0;
  int esquiva = calcularDesvio(this->agilidade);

  if (esquiva == 1 && ataque == 0) // calcula esquiva somente de armas
    return 0;

  float reducaodano;

  if (ataque == 0) // tipo de dano (por arma ou magia)
    reducaodano = this->resistenciaFisica;
  else
    reducaodano = this->resistenciaMagica;

  if (dano > 0)
  {
    danoRecebido = dano - ((dano * reducaodano) / 100);
    // cout << "Dano recebido "<<danoRecebido<<"\n";
    if (danoRecebido > this->vida) // tira a vida
      this->vida = 0;
    else
      this->vida -= danoRecebido;

    if (this->vida == 0)
    { // morreu
      return -1;
    }
  }
  else if (dano == -1)
  { // cura
    return -2;
  }
  else if (dano == -2)
  { // sem mana
    return -3;
  }
  else if (dano == 0)
  { // numero invalido
    return -4;
  }

  return danoRecebido;
}
void Personagem::descansar()
{ // recupera vida
  if (this->vida + 120 < this->maxvida)
  { // cura sem de vidao ao descansar,
    // mas personagens que ja tem cura como mago e paladino não podem usar
    this->vida += 120;
  }
  else
  {
    this->vida = this->maxvida;
  }

  cout << "Ao descansar voce curou +120 de vida\n";

  regeneraMana();
}
////////////////montrar coisa no main/////////////////////////////////////////
int Personagem::mostrarAtributos(string jogadoratual)
{ //imprime o menu base com a arma
  cout << "\n\n-------------------" << jogadoratual << "------------------------";
  cout << "\nPersonagem: " << this->nome
       << " \nVida: " << this->vida << "/" << this->maxvida
       << "  Mana: " << this->mana << "/" << this->maxmana
       << "  Armas para troca: " << quantidadeArmaTroca()
       << "\nFalta " << this->turnosUlt << " turnos para poder usar a sua ULTIMATE"
       << endl;

  if (this->turnosUlt > 0)
    this->turnosUlt--;

  return imprimiArmas();
}
string Personagem::retornaNome()
{
  return this->nome;
}
int Personagem::retornaturnosUlt()
{
  return this->turnosUlt;
}
void Personagem::mostrarTodosAtributos()
{ //printa todos os atributos do 2 personagens
  cout << "\nPersonagem: " << this->nome
       << " \nVida: " << this->vida << "/" << this->maxvida
       << "  Mana: " << this->mana << "/" << this->maxmana
       << "  Forca Fisica: " << this->forcaFisica << "%"
       << "  Forca Magica: " << this->forcaMagica << "%"
       << "\nArmadura: " << this->resistenciaFisica << "%"
       << "  Resistencia Magica: " << this->resistenciaMagica << "%"
       << "  Agilidade: " << this->agilidade << "%"
       << "\n";
}
int Personagem::atacaUlt()
{ // ataca com a ult
  if (this->ult == NULL)
    return this->usarMagia(this->magias.size() + 1);
  else
    return this->atacarArma(2);
}
Arma *Personagem::retornaUlt()
{
  return this->ult;
}
void Personagem::resetaUlt()
{
  this->turnosUlt = TURNOS_ULT;
}
