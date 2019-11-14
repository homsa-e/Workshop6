#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main (int argc, char **argv)
{
  for (int i = 0; i < argc; ++i)
  {
      std::cout << argv[i] << std::endl;
  }



  std::ifstream in ("input.csv");
  std::string line;

  while (!in.eof() && in.good ())
  {
    std::getline (in, line);
    std::cout << line << std::endl;

    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (!ss.eof () && ss.good ())
    {
        std::getline (ss, token, ',');
        std::cout << token << std::endl;
        tokens.push_back (token);
    }
  }
}
