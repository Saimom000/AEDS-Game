#include <iostream>
#include <string>

using namespace std;

class G
{
private:
  /* data */
public:
G(string m)
{
  cout << m;
}
};

void say(string a){
  cout << a;
}

int main(int argc, char const *argv[])
{
  // cout << "a";

  G *g = new G("sad");

  say("aa");
  return 0;
}
