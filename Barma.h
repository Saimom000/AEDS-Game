#include <string.h>
#include <iostream>

using namespace std;

class Arma
{
private:
    int id;
    string nome;
    int danomin;
    int danomax;
    int durabilidade;
    int *tipoperso;
public:
    Arma(/* args */);
    ~Arma();
};
