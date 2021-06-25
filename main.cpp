#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>

#include "Personagem.cpp"

using namespace std;

Personagem *player1, *player2;

void jogadormenu(string atacante){
  cout << "\nEscolha uma das opcoes " << atacante << " :\n";
  cout <<"1 - Atacar com arma\n"
          <<"2 - Atacar com magia\n"
          <<"3 - Trocar arma\n";
}

void imprimirmenu()
{
  int opcao,j=1;
  for (int i = 1; i != 4 ; i++)
  {
    do{
      int jogador = i % 2 != 0 ? 1: 2;
      int vitima = i % 2 != 0 ? 2: 1;
      string jogadoratual = i % 2 != 0 ? "Jogador 1": "Jogador 2";
      string jogadorNaoatual = i % 2 != 0 ? "Jogador 2": "Jogador 1";
      if(jogador == 1){
        player1->mostrarAtributos();
      }else{
        player2->mostrarAtributos();
      }

      jogadormenu(jogadoratual);
      cin >> opcao;
      switch (opcao)
      {
      case 1:
        if(jogador == 1){
          int dano = player2->receberDano(player1->atacarArma(),0);
          if(dano == 0){
            cout<< "Voce errou o ataque\n";
          }else if(dano == -1){
            //o jogador inimigo morreu
          }else
          cout <<"Voce causou "<< dano << " no " << jogadorNaoatual << "\n";
        }else{
          int dano = player1->receberDano(player2->atacarArma(),0);
          if(dano == 0){
            cout<< "Voce errou o ataque\n";
          }else if(dano == -1){
            //o jogador inimigo morreu
          }else
          cout <<"Voce causou "<< dano << " de dano no " << jogadorNaoatual << "\n";
        }
        //atacar com arma
        break;
      case 2:
        //player2->receberDano(player1->UsarMagia(),1);
        //atacar ou curar com magia
        break;
      case 3:
        //player2->receberDano(player1->atacarArma(),0);
        //trocar arma
        break;
      default:
        j = 0;
        break;
      }
      j = 0;
    }while(j != 0);
    
    
  //i=-1;
  }

}
void imprimirinicio()
{
  int i, num_perso,num_perso2;
  // player 1
  for (i = 0; i < 1; i++)
  {
    cout << "Digite o numero do personagem do jogador 1 :\n"
        << "1 - Gurreiro  2 - Ladrao\n"
        << "3 - Mago  4 - Paladino\n"
        << "5 - Animal  6 - Troll\n"
        << "7 - Dragao  8 - Zumbi\n";
    cin >> num_perso;

    switch (num_perso)
    {
    case 1:
      player1 = new Personagem("guerreiro");
      break;
    case 2:
      player1 = new Personagem("ladrao");
      break;
    case 3:
      player1 = new Personagem("mago");
      break;
    case 4:
      player1 = new Personagem("paladino");
      break;
    case 5:
      player1 = new Personagem("animal");
      break;
    case 6:
      player1 = new Personagem("troll");
      break;
    case 7:
      player1 = new Personagem("dragao");
      break;
    case 8:
      player1 = new Personagem("zumbi");
      break;
    default:
      cout << "Numero de personagem invalido";
      i--;
      break;
    }
  }
  //cout << player1->verificaVida();
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
      player2 = new Personagem("guerreiro");
      break;
    case 2:
      player2 = new Personagem("ladrao");
      break;
    case 3:
      player2 = new Personagem("mago");
      break;
    case 4:
      player2 = new Personagem("paladino");
      break;
    case 5:
      player2 = new Personagem("animal");
      break;
    case 6:
      player2 = new Personagem("troll");
      break;
    case 7:
      player2 = new Personagem("dragao");
      break;
    case 8:
      player2 = new Personagem("zumbi");
      break;

    default:
      cout << "Numero de personagem invalido";
      i--;
      break;
    }
  }
  cout << "\n\n\n";
 imprimirmenu();
}


void jogo()
{
}

int main()
{

  // Personagem *exemplo = new Personagem("guerreiro");
  // cout << exemplo->verificaVida();

  int n=0;
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
