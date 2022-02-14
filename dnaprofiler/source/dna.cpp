#include "dna.hpp"

using std::getline;
using std::ifstream;
using std::string;
using std::vector;

DNA::DNA(const vector<string> &profile_type,
         const string &dna_sequence_filepath)
    : profile_(profile_type) {
  LoadDNA(dna_sequence_filepath);
}

void DNA::LoadDNA(const string &dna_sequence_filepath) {
  ifstream dna_sequence_file(dna_sequence_filepath);

  string dna_sequence;
  getline(dna_sequence_file, dna_sequence);

  profile_.set_code(Profile::GetProfileCode(profile_.get_type(), dna_sequence));
}

Profile DNA::get_profile() const { return profile_; }
