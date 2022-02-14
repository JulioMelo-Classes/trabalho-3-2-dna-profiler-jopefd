#include "profile.hpp"

using std::string;
using std::to_string;
using std::vector;

// INICIO IMPLEMENTACAO DO GEEKSFORGEEKS
void Profile::computeLPSArray(string pat, int M, int lps[]) {
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

int Profile::KMPSearch(string pat, string txt) {
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

Profile::Profile(const vector<string> profile_type) : type_(profile_type) {}

Profile::Profile(const vector<string> profile_type, const string &dna_sequence)
    : type_(profile_type), code_(GetProfileCode(profile_type, dna_sequence)) {}

string Profile::GetProfileCode(const vector<string> &profile_type,
                               const string &dna_sequence) {
  string code = "";

  for (const auto &s : profile_type) {
    if (not code.empty()) code += ",";
    code += to_string(KMPSearch(s, dna_sequence));
  }

  return code;
}

vector<string> Profile::get_type() const { return type_; }

string Profile::get_code() const { return code_; }

void Profile::set_code(const string &code) { code_ = code; }