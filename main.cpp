#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <string.h>
#include <stdio.h>

#include "Baccessdata.h"
#include "Bpersonagem.h"

using namespace std;
void imprimirmenu(){
    int qtdAtributos = 7;
    Accessdata * a = new Accessdata(qtdAtributos);    

    
    int quantidade_jogadores = 2,i,num_perso;
    for ( i = 0; i < quantidade_jogadores; i++)
    {
        cout << "Digite o numero do personagem do jogador "<< i+1 <<" :\n";
        cout << "1 - Gurreiro  2 - Ladrao\n";
        cout << "3 - Mago  4 - Paladino\n";
        cout << "5 - Animal  6 - Troll\n";
        cout << "7 - Dragão  8 - Zumbi\n";
        cin >> num_perso;
        if(num_perso >= 1 && num_perso <= 8){
            switch (num_perso)
            {
            case 1:
                int * atributos = a->obtemAtributos ("Aguerreiro.txt");
                break;
            case 2:
                int * atributos = a->obtemAtributos ("Aladrao.txt");
                break;
            case 3:
                int * atributos = a->obtemAtributos ("Amago.txt");
                break;
            case 4:
                int * atributos = a->obtemAtributos ("Apaladino.txt");
                break;
            case 5:
                int * atributos = a->obtemAtributos ("Aanimal.txt");
                break;
            case 6:
                int * atributos = a->obtemAtributos ("Atroll.txt");
                break;
            case 7:
                int * atributos = a->obtemAtributos ("Adragao.txt");
                break;
            case 8:
                int * atributos = a->obtemAtributos ("Azumbi.txt");
                break;
            
            default:
                cout << "Numero de personagem invalido";
                i--;
                break;
            }
        }
        
    }
}
int main () {

    int qtdAtributos = 7;

    Accessdata * a = new Accessdata(qtdAtributos);    
    Personagem *player1,*player2;
    int * atributos = a->obtemAtributos ("guerreiro.txt");

    //imprime o vetor de atributos da classe escolhida no jogo
    for (int i = 0; i < qtdAtributos; i++)        
        cout << atributos[i] << " "; 

    cout << endl;    
    int n;
    do 
    {
        cout << "\nDigite 1 para começar o jogo e 2 para fechar\n";
        cin >> n;

    if(n == 1){

    }else if(n == 2){

    }else 
        cout << "Valor digitado invalido";

    }while (n != 2);


    return 0;

}
