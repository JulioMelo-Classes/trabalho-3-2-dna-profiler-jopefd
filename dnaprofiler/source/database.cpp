#include "database.hpp"

using std::getline;
using std::ifstream;
using std::map;
using std::string;
using std::stringstream;
using std::vector;

Database::Database(const string &database_filepath) {
  LoadDatabase(database_filepath);
}

void Database::LoadDatabase(const string &database_filepath) {
  ifstream database_file(database_filepath);

  string aux_str;
  getline(database_file, aux_str);
  stringstream ss(aux_str);
  getline(ss, aux_str, ',');
  while (getline(ss, aux_str, ',')) profile_.push_back(aux_str);

  for (string aux_str; getline(database_file, aux_str);) {
    stringstream ss(aux_str);

    string name;
    getline(ss, name, ',');
    string dna;
    getline(ss, dna);

    dnas_profiles_[dna] = name;
  }
}

string Database::Find(const string &profile_code) const {
  return dnas_profiles_.at(profile_code);
}

Profile Database::get_profile() const { return profile_; }
