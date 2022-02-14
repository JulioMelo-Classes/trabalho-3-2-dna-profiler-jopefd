#ifndef DNAPROFILER_DNA_H_
#define DNAPROFILER_DNA_H_

#include <fstream>
#include <string>
#include <vector>

#include "profile.hpp"

class DNA {
 private:
  Profile profile_;

 public:
  DNA(const std::vector<std::string> &profile_type,
      const std::string &dna_sequence_filepath);

  void LoadDNA(const std::string &dna_sequence_filepath);

  Profile get_profile() const;
};

#endif
