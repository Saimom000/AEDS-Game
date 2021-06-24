#pragma once

#include <iostream>
#include <string>

#include "Accessdata.cpp"
#include "Arma.cpp"

using namespace std;

class ArmaLendaria : public Arma
{
private:
    int chanseCritico;
    int danoCritico;

public:
    ArmaLendaria(string nomeArma);
    int CalcularDano() override;
};

ArmaLendaria::ArmaLendaria(string nomeArma) : Arma(nomeArma)
{
    srand(time(0));
    this->chanseCritico = 30;
    this->danoCritico = 100;
}
int ArmaLendaria::CalcularDano()
{
    durabilidade -= 1;
    int dano = danomin + (rand() % (danomax - danomin + 1));
    int chanceDeCritico = (rand() % 100) + 1;

    if (chanceDeCritico <= this->chanseCritico)
    {
        dano += dano * (this->danoCritico / 100);
    }
}
