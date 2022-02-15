#ifndef DNAPROFILER_DATABASE_H_
#define DNAPROFILER_DATABASE_H_

#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "profile.hpp"

class Database {
 private:
  std::map<std::string, std::string> dnas_profiles_;
  std::vector<std::string> profile_;

 public:
  /**
   * \brief Construct a new Database object
   *
   * \param database_filepath
   */
  Database(const std::string &database_filepath);

  /**
   * \brief Load database from the given file
   *
   * \param database_filepath
   */
  void LoadDatabase(const std::string &database_filepath);

  /**
   * \brief Find profile code in database
   *
   * \param profile_code
   * \return std::string
   */
  std::string Find(const std::string &profile_code) const;

  /**
   * \brief Get the profile object
   *
   * \return Profile
   */
  Profile get_profile() const;
};

#endif
