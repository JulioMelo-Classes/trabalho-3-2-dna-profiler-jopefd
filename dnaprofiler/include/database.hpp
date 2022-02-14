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
  Database(const std::string &database_filepath);

  void LoadDatabase(const std::string &database_filepath);

  std::string Find(const std::string &profile_code) const;

  Profile get_profile() const;
};

#endif
