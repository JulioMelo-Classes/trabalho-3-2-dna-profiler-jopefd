#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::map;
using std::to_string;
using std::set;
using std::size_t;
using std::string;
using std::stringstream;
using std::vector;

// INICIO IMPLEMENTACAO DO GEEKSFORGEEKS
void computeLPSArray(string pat, int M, int lps[]) {
  int len = 0;
  int i = 1;
  lps[0] = 0;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];

      } else {
        lps[i] = len;
        i++;
      }
    }
  }
}

int KMPSearch(string pat, string txt) {
  int M = pat.length();
  int N = txt.length();

  int lps[M];
  int j = 0;

  computeLPSArray(pat, M, lps);

  int i = 0;
  int res = 0;
  int next_i = 0;

  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == M) {
      j = lps[j - 1];
      res++;
    }

    else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
  return res;
}
// FIM IMPLEMENTACAO DO GEEKSFORGEEKS

int main(int argc, char **argv) {
  ifstream database_file(argv[1]);

  vector<string> strs;
  map<string, string> dnas_profiles;

  // consumir "name" e guardar strs
  string aux_str;
  getline(database_file, aux_str);
  stringstream ss(aux_str);
  getline(ss, aux_str, ',');
  while (getline(ss, aux_str, ',')) strs.push_back(aux_str);

  // guardar dnas e seus nomes
  for (string aux_str; getline(database_file, aux_str);) {
    stringstream ss(aux_str);

    string name;
    getline(ss, name, ',');
    string dna;
    getline(ss, dna);

    dnas_profiles[dna] = name;
  }

  ifstream dna_sequence_file(argv[2]);

  string dna_sequence;
  getline(dna_sequence_file, dna_sequence);

  string dna_readed = "";
  for (auto &s : strs) {
    if (not dna_readed.empty()) dna_readed += ",";
    dna_readed += to_string(KMPSearch(s, dna_sequence));
  }

  string result = dnas_profiles[dna_readed];
  cout << (result.empty() ? "no match" : result)  << endl;
}
