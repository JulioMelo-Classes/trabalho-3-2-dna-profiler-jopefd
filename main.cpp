#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::getline;
using std::ifstream;
using std::map;
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::vector;

int main(int argc, char **argv) {
  ifstream database(argv[1]);

  map<string, map<string, size_t>> dnas;
  set<string> strs;

  string aux;
  stringstream ss;

  // consumir name e guardar strs
  getline(database, aux);
  ss << aux;
  getline(ss, aux, ',');
  while (getline(ss, aux, ','))
    strs.insert(aux);

  // guardar nomes e seus strs
  while (getline(database, aux)) {
    map<string, size_t> strs;
    
    ss << aux;
    
    string name;
    getline(ss, name, ',');

    while(getline(ss, aux, ','))
      strs[aux]++;

    dnas[name] = strs;
  }
}
