# Jogo AEDS

## Convenções

- Nome de classe: `PascalCase`
- Nome de métodos/funções: `lowerCamelCase`
- Nome de atributos: `lowerCamelCase`

```cpp
class Coisa {
  string nome;

  string getNome() {
    return this->nome;
  }
}
```

## Práticas

- Formata o código `sempre` (`shift` + `alt` + `F`)

- `vector` em vez de array

```cpp
vector<int> numeros; // array de int
vector<Coisa> coisas; // array de Coisa
vector<string> strings; // array de string

numeros.push_back(2); // coloca um novo no final
strings.push_back("coisa");
strings.push_back("23");
numeros.size(); // pega o tamanho

string coisa = strings.at(1); // pega o index 0
int numero = stoi(coisa); // string to int, converte de string pra int
```

- instanciar algo

```cpp
Coisa *coisa = new Coisa();
```

## Outros

- `#pragma once` evita erro de declarar a mesma classe 2 vezes pq incluiu o arquivo 2 vezes

```cpp
#pragma once

// ...
```

- dá pra n usar `::`

```cpp
// isso
class Coisa {
  int numero;

  int getNumero();
  void setNumero(int numero);
}

int Coisa::getNumero() {
  return this->numero;
}

void Coisa::getNumero(int numero) {
  this->numero = numero;
}

// mesma coisa disso (acho melhor)
class Coisa {
  int numero;

  int getNumero() {
    return this->numero;
  }

  void setNumero(int numero) {
    this->numero = numero;
  }
}
```
