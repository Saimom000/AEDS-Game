#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <string>
#include <stdio.h>

#include "Personagem.cpp"

using namespace std;

void imprimirmenu()
{
    Personagem *player1, *player2;
    int i, num_perso;
    // player 1
    for (i = 0; i < 1; i++)
    {
        cout << "Digite o numero do personagem do jogador " << i + 1 << " :\n";
        cout << "1 - Gurreiro  2 - Ladrao\n";
        cout << "3 - Mago  4 - Paladino\n";
        cout << "5 - Animal  6 - Troll\n";
        cout << "7 - Dragão  8 - Zumbi\n";
        cin >> num_perso;

        switch (num_perso)
        {
        case 1:
        {
            player1 = new Personagem("Aguerreiro.txt");
            break;
        }
        case 2:
        {
            player1 = new Personagem("Aladrao.txt");
            break;
        }
        case 3:
        {
            player1 = new Personagem("Amago.txt");
            break;
        }
        case 4:
        {
            player1 = new Personagem("Apaladino.txt");
            break;
        }
        case 5:
        {
            player1 = new Personagem("Aanimal.txt");
            break;
        }
        case 6:
        {
            player1 = new Personagem("Atroll.txt");
            break;
        }
        case 7:
        {
            player1 = new Personagem("Adragao.txt");
            break;
        }
        case 8:
        {
            player1 = new Personagem("Azumbi.txt");
            break;
        }

        default:
        {
            cout << "Numero de personagem invalido";
            i--;
            break;
        }
        }
    }
    // player 2
    for (i = 0; i < 1; i++)
    {
        cout << "Digite o numero do personagem do jogador " << i + 1 << " :\n";
        cout << "1 - Gurreiro  2 - Ladrao\n";
        cout << "3 - Mago  4 - Paladino\n";
        cout << "5 - Animal  6 - Troll\n";
        cout << "7 - Dragão  8 - Zumbi\n";
        cin >> num_perso;

        switch (num_perso)
        {
        case 1:
            player2 = new Personagem("Aguerreiro.txt");
            break;
        case 2:
            player2 = new Personagem("Aladrao.txt");
            break;
        case 3:
            player2 = new Personagem("Amago.txt");
            break;
        case 4:
            player2 = new Personagem("Apaladino.txt");
            break;
        case 5:
            player2 = new Personagem("Aanimal.txt");
            break;
        case 6:
            player2 = new Personagem("Atroll.txt");
            break;
        case 7:
            player2 = new Personagem("Adragao.txt");
            break;
        case 8:
            player2 = new Personagem("Azumbi.txt");
            break;

        default:
            cout << "Numero de personagem invalido";
            i--;
            break;
        }
    }
}

int main()
{

    int qtdAtributos = 7;

    Accessdata *a = new Accessdata(qtdAtributos);

    int *atributos = a->obtemAtributos("guerreiro.txt");

    //imprime o vetor de atributos da classe escolhida no jogo
    for (int i = 0; i < qtdAtributos; i++)
        cout << atributos[i] << " ";

    cout << endl;
    int n;
    do
    {
        cout << "\nDigite 1 para começar o jogo e 2 para fechar\n";
        cin >> n;

        if (n == 1)
        {
            imprimirmenu();
        }
        else if (n == 2)
        {
        }
        else
            cout << "Valor digitado invalido";

    } while (n != 2);

    return 0;
}
