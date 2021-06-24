#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>

#include "Personagem.cpp"

using namespace std;

Personagem *player1, *player2;

void imprimirinicio()
{
  int i, num_perso;
  // player 1
  for (i = 0; i < 1; i++)
  {
    cout << "Digite o numero do personagem do jogador 1 :\n";
    cout << "1 - Gurreiro  2 - Ladrao\n";
    cout << "3 - Mago  4 - Paladino\n";
    cout << "5 - Animal  6 - Troll\n";
    cout << "7 - Dragao  8 - Zumbi\n";
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
    cout << "Digite o numero do personagem do jogador 2 :\n";
    cout << "1 - Gurreiro  2 - Ladrao\n";
    cout << "3 - Mago  4 - Paladino\n";
    cout << "5 - Animal  6 - Troll\n";
    cout << "7 - Dragao  8 - Zumbi\n";
    cin >> num_perso;

    switch (num_perso)
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

void imprimirmenu()
{
  /* 
  1 - troca arma
  2 - ataca arma
  3 - ataca magia
  */
}

void jogo()
{
}

int main()
{

  Personagem *exemplo = new Personagem("guerreiro");

  cout << 'a';

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
