#include "accessdata.h"

Accessdata::Accessdata(int qtdAtributos)
{
    //você deverá retorar este vetor de atributos para dentro do seu programa no momento de instanciar um novo personagem
    this->qtdAtributos = qtdAtributos;
    this->atributos = new int [qtdAtributos];    //quantidade de atributos das classes do jogo
}

string Accessdata::abreArquivo (string nomeDaClasse)
{
    fstream arq;

    arq.open(nomeDaClasse ,ios::in);
    
    string linha;
    
    //Faz a leitura linha a linha do arquivo texto (string linha armazena a linha lida do arquivo)
    if (arq.is_open()){ 
        getline(arq, linha);       
    }

    arq.close();

    return linha;
}

int * Accessdata::obtemAtributos (string nomeDaClasse)
{    
    string linha = abreArquivo (nomeDaClasse);

    char str[linha.size()];

    //converte a string para um vetor de caractere          
    for (int i = 0; i < linha.size(); i++)        
        str[i] = linha[i];
   
    char ch[2] = ",";   //especifica o caractere que será usado para dividir a string (split)    

    char *token;
    char *palavra;

    int i = 0; 
    
    token = strtok(str, ch);     
    while( token != NULL ) {
        palavra = token;
        token = strtok(NULL, ch);

        this->atributos[i++] = atoi(palavra);
    }

    return this->atributos;         
}




