#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>

#include "Personagem.cpp"

using namespace std;

Personagem *player1, *player2;

void jogador1(){
  cout << "Escolha  das opcoes jogador 1\n";
  cout <<"1 - Atacar com arma\n"
          <<"2 - Atacar com magia\n"
          <<"3 - Trocar arma\n";
}

void jogador2(){
  cout << "Escolha  das opcoes jogador 2\n";
  cout <<"1 - Atacar com arma\n"
          <<"2 - Atacar com magia\n"
          <<"3 - Trocar arma\n";
}

void imprimirmenu()
{
  int opcao,j=1;
  for (int i = 0; i != 1; i)
  {
    do{
      jogador1();
      cin >> opcao;
      switch (opcao)
      {
      case 1:
        player2->receberDano(player1->atacarArma(),0);
        break;
      case 2:
        //player2->receberDano(player1->UsarMagia(),1);
        break;
      case 3:
        //player2->receberDano(player1->atacarArma(),0);
        break;
      default:
        j = 0;
        break;
      }
    }while(j != 0);
    
    

  }

}
void imprimirinicio()
{
  int i, num_perso,num_perso2;
  // player 1
  for (i = 0; i < 1; i++)
  {
    cout << "Digite o numero do personagem do jogador 2 :\n"
        << "1 - Gurreiro  2 - Ladrao\n"
        << "3 - Mago  4 - Paladino\n"
        << "5 - Animal  6 - Troll\n"
        << "7 - Dragao  8 - Zumbi\n";
    cin >> num_perso;

    switch (num_perso)
    {
    case 1:
      player1 = new Personagem("data/guerreiro.txt");
      break;
    case 2:
      player1 = new Personagem("data/ladrao.txt");
      break;
    case 3:
      player1 = new Personagem("data/mago.txt");
      break;
    case 4:
      player1 = new Personagem("data/paladino.txt");
      break;
    case 5:
      player1 = new Personagem("data/animal.txt");
      break;
    case 6:
      player1 = new Personagem("data/troll.txt");
      break;
    case 7:
      player1 = new Personagem("data/dragao.txt");
      break;
    case 8:
      player1 = new Personagem("data/zumbi.txt");
      break;
    default:
      cout << "Numero de personagem invalido";
      i--;
      break;
    }
  }
  // player 2
  for (i = 0; i < 1; i++)
  {
    cout << "Digite o numero do personagem do jogador 2 :\n"
        << "1 - Gurreiro  2 - Ladrao\n"
        << "3 - Mago  4 - Paladino\n"
        << "5 - Animal  6 - Troll\n"
        << "7 - Dragao  8 - Zumbi\n";
    cin >> num_perso2;

    switch (num_perso2)
    {
    case 1:
      player2 = new Personagem("data/guerreiro.txt");
      break;
    case 2:
      player2 = new Personagem("data/ladrao.txt");
      break;
    case 3:
      player2 = new Personagem("data/mago.txt");
      break;
    case 4:
      player2 = new Personagem("data/paladino.txt");
      break;
    case 5:
      player2 = new Personagem("data/animal.txt");
      break;
    case 6:
      player2 = new Personagem("data/troll.txt");
      break;
    case 7:
      player2 = new Personagem("data/dragao.txt");
      break;
    case 8:
      player2 = new Personagem("data/zumbi.txt");
      break;

    default:
      cout << "Numero de personagem invalido";
      i--;
      break;
    }
  }

}


void jogo()
{
}

int main()
{

  Personagem *exemplo = new Personagem("guerreiro");


  int n;
  do
  {
    cout << "\nDigite 1 para comecar o jogo e 2 para fechar\n";
    cin >> n;

    if (n == 1)
    {
      imprimirinicio();
      jogo();
    }
    else if (n == 2)
    {
    }
    else
      cout << "Valor digitado invalido";

  } while (n != 2);

  return 0;
}
