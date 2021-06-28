#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale.h>
#include "Personagem.cpp"

using namespace std;

Personagem *player1, *player2;
int semDescansar(string nome)
{ // o jogador do tipo paladino ou mago n podem descansar
  if (nome == "mago" || nome == "paladino")
  {
    return 1;
  }
  return 0;
}
void jogadormenu(string atacante, int tipo)
{
  if (tipo == 1)
  {
    cout << "\nEscolha uma das opcoes " << atacante << " :\n"; // menu do mago e paladino
    cout << "1 - Atacar com arma\n"
         << "2 - Usar magia\n"
         << "3 - Trocar arma\n"
         << "4 - Ver TODOS os atributos dos 2 jogadores\n";
  }
  else
  {
    cout << "\nEscolha uma das opcoes " << atacante << " :\n"; // menu do resto
    cout << "1 - Atacar com arma\n"
         << "2 - Usar magia\n"
         << "3 - Trocar arma\n"
         << "4 - Ver TODOS os atributos dos 2 jogadores\n"
         << "5 - Descansar (+120 vida)\n";
  }
}

void imprimirmenu()
{
  setlocale(LC_ALL, "portuguese");
  int opcao, lendaria = 0, dano, magia, k, v, tipo;
  for (int i = 1; i != 0; i++) //turnos
  {

    int jogador = i % 2 != 0 ? 1 : 2;
    int vitima = i % 2 != 0 ? 2 : 1;
    string jogadoratual = i % 2 != 0 ? "Jogador 1" : "Jogador 2";
    string jogadorNaoatual = i % 2 != 0 ? "Jogador 2" : "Jogador 1";
    if (jogador == 1)
    { //mostra os atributos do jogador 1 ou 2 , arma equipada, vida, mana ...
      lendaria = player1->mostrarAtributos(jogadoratual);
    }
    else
    {
      lendaria = player2->mostrarAtributos(jogadoratual);
    }
    do
    { //resetar caso o valor digitado seja invalido ou queira voltar para o menu
      v = 1;

      if (jogador == 1)
      { // o jogador do tipo paladino ou mago nao podem descansar
        tipo = semDescansar(player1->tipoJogador());
        jogadormenu(jogadoratual, tipo);
      }
      else if (jogador == 2)
      {
        tipo = semDescansar(player2->tipoJogador());
        jogadormenu(jogadoratual, tipo);
      }
      cin >> opcao;
      cout << "\n";
      switch (opcao)
      {
      case 1: //atacar com arma
        if (jogador == 1)
        {
          dano = player2->receberDano(player1->atacarArma(lendaria), 0);
          if (dano == 0)
          { //errou o ataque
            cout << "Voce errou o ataque\n";
          }
          else if (dano == -1)
          { //o jogador inimigo morreu
            cout << "\nO " << jogadorNaoatual << " morreu, voce venceu o jogo\n"
                 << "\n O " << jogadoratual << " VENCEU\n"
                 << "OBRIGADO POR JOGAR :)\n";
            i = -1;
          }
          else
          {
            cout << "Voce causou " << dano << " no " << jogadorNaoatual << "\n";
          }
          player1->semDurabilidade(); //verifica se a durabilidade de arma atual acabou, se for a arma base nao mostra mensagem
        }
        else
        {
          dano = player1->receberDano(player2->atacarArma(lendaria), 0);
          if (dano == 0)
          {
            cout << "Voce errou o ataque\n";
          }
          else if (dano == -1)
          {
            cout << "\nO " << jogadorNaoatual << " morreu, voce venceu o jogo\n"
                     << "\n O " << jogadoratual << " VENCEU\n"
                     << "OBRIGADO POR JOGAR :)\n";
            i = -1;
          }
          else
          {
            cout << "Voce causou " << dano << " de dano no " << jogadorNaoatual << "\n";
          }
          player2->semDurabilidade();
        }

        break;
      case 2: //atacar ou curar com magia

        if (jogador == 1)
        {
          player1->listarMagias();
        }
        else
        {
          player2->listarMagias();
        }
        do
        { //repete se o numero digitado for invalido ou ficar sem mana
          k = 1;
          cin >> magia;
          if (magia != 0)
          { //se for magia for 0 ele vai voltar para o menu anterior

            if (jogador == 1)
            {
              dano = player2->receberDano(player1->usarMagia(magia), 1);
              if (dano == 0)
              {
                cout << "Voce errou o ataque\n";
              }
              else if (dano == -1)
              {
                cout << "\nO " << jogadorNaoatual << " morreu, voce venceu o jogo\n"
                     << "\n O " << jogadoratual << " VENCEU\n"
                     << "OBRIGADO POR JOGAR :)\n";
                i = -1;
                //o jogador inimigo morreu
              }
              else if (dano == -2)
              { //cura
                cout << "\nVoce foi curado\n";
              }
              else if (dano == -3)
              { //sem mana
                cout << "Voce esta sem mana, escolha uma opcao novamente:\n";
                k = 0;
              }
              else if (dano == -4)
              { //numero invalido
                k = 0;
              }
              else
              {
                cout << "\nVoce causou " << dano << " no " << jogadorNaoatual << "\n";
              }
            }
            else
            {
              dano = player1->receberDano(player2->usarMagia(magia), 1);
              if (dano == 0)
              { //nao da pra desviar de magia, mas se precisar colocar esta aqui
                cout << "Voce errou o ataque\n";
              }
              else if (dano == -1)
              { //jogador inimigo morreu
                cout << "\nO " << jogadorNaoatual << " morreu, voce venceu o jogo\n"
                     << "\n O " << jogadoratual << " VENCEU\n"
                     << "OBRIGADO POR JOGAR :)\n";
                i = -1;
                //o jogador inimigo morreu
              }
              else if (dano == -2)
              { //cura
                cout << "\nVoce foi curado\n";
              }
              else if (dano == -3)
              { //sem mana
                cout << "Voce esta sem mana, escolha uma opcao novamente:\n";
                k = 0;
              }
              else if (dano == -4)
              { //numero invalido
                k = 0;
              }
              else
              {
                cout << "\nVoce causou " << dano << " no " << jogadorNaoatual << "\n";
              }
            }
          }
          else
          {
            v = 0;
          }
        } while (k == 0);
        //player2->receberDano(player1->UsarMagia(),1);

        break;
      case 3: //trocar arma
        //player2->receberDano(player1->atacarArma(),0);
        if (jogador == 1)
        {
          if (player1->verificaArmaTroca() == 1)
          {
            player1->trocarArma();
          }
          else
          {
            cout << "Sem arma para trocar, escolha outro numero\n";
            v = 0;
          }
        }
        else
        {
          if (player2->verificaArmaTroca() == 1)
          {
            player2->trocarArma();
          }
          else
          {
            cout << "Sem arma para trocar, escolha outro numero\n";
            v = 0;
          }
        }
        break;
      case 4: //ver todos atributos
        if (jogador == 1)
        {
          cout << "Seus Atributos:\n";
          player1->mostrarTodosAtributos();
          cout << "\nAtributos do jogador 2:\n";
          player2->mostrarTodosAtributos();
        }
        else
        {
          cout << "Seus Atributos:\n";
          player2->mostrarTodosAtributos();
          cout << "\nAtributos do jogador 1:\n";
          player1->mostrarTodosAtributos();
        }
        v = 0;
        break;
      case 5: //descansar

        if (tipo != 1)
        {
          if (jogador == 1)
          {

            player1->descansar();
          }
          else
          {
            player2->descansar();
          }
        }
        else
        {
          cout << "Valor digitado invalido\n";
          v = 0;
        }

        break;
      default:
        cout << "Valor digitado invalido\n";
        v = 0;
        break;
      }
    } while (v == 0);
  }
}
void imprimirinicio()
{
  int i, num_perso, num_perso2;
  // player 1
  for (i = 0; i < 1; i++)
  {
    cout << "Digite o numero do personagem do jogador 1 :\n"
         << "1 - Gurreiro  2 - Ladrao\n"
         << "3 - Mago    4 - Paladino\n"
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
  // player 2
  for (i = 0; i < 1; i++)
  {
    cout << "Digite o numero do personagem do jogador 2 :\n"
         << "1 - Gurreiro  2 - Ladrao\n"
         << "3 - Mago    4 - Paladino\n"
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

  int n = 0;
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
