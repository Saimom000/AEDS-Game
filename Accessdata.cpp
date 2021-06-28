#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

string getFile(string name)
{
  fstream arq;
  string linha;

  arq.open(name, ios::in);

  if (arq.is_open())
    getline(arq, linha);

  arq.close();

  return linha;
}

vector<string> getAttributes(string name)
{
  vector<string> arr;

  string s = getFile("data/" + name + ".txt");
  string delimiter = ",";

  size_t pos = 0;
  while ((pos = s.find(delimiter)) != string::npos)
  {
    string token = s.substr(0, pos);
    arr.push_back(token);
    s.erase(0, pos + delimiter.length());
  }

  return arr;
}
