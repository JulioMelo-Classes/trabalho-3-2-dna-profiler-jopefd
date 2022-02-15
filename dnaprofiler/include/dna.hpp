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
  /**
   * \brief Construct a new DNA object
   *
   * \param profile_type
   * \param dna_sequence_filepath
   */
  DNA(const std::vector<std::string> &profile_type,
      const std::string &dna_sequence_filepath);

  /**
   * \brief Load DNA sequence from the given file
   *
   * \param dna_sequence_filepath
   */
  void LoadDNA(const std::string &dna_sequence_filepath);

  /**
   * \brief Get the profile object
   *
   * \return Profile
   */
  Profile get_profile() const;
};

#endif
