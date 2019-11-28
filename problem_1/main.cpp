#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main (int argc, char **argv)
{
  for (int i = 0; i < argc; ++i)
  {
      //out << argv[i] << std::endl;
  }

  //return 0;
  std::ifstream in (argv[1]);
  std::string line;
  std::ofstream out (argv[2]);
  //size_t k = 0;
  std::vector <int> columns;
  for (int i = 3; i < argc; i++)
      columns.push_back(atoi(argv[i]));
  for (int i = 0; i < columns.size(); i++){
      //out << columns[i] << std::endl;
  }
  while (!in.eof() && in.good ())
  {
    std::getline (in, line);
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    //out << line << std::endl;
    while (!ss.eof () && ss.good ())
    {
        std::getline (ss, token, ',');
        tokens.push_back(token);
        //out << tokens[tokens.size() - 1] << std::endl;
    }
    for (int p : columns)
        if (p != columns[columns.size() - 1])
            out << tokens[p] << ',';
        else
            out << tokens[p];
    out << '\n';
  }
}
