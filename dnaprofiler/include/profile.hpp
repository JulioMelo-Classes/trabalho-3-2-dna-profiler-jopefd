#ifndef DNAPROFILER_PROFILE_H_
#define DNAPROFILER_PROFILE_H_

#include <string>
#include <vector>

class Profile {
 private:
  std::vector<std::string> type_;
  std::string code_;

  static void computeLPSArray(std::string pat, int M, int lps[]);

  static int KMPSearch(std::string pat, std::string txt);

 public:
  Profile(const std::vector<std::string> profile_type);

  Profile(const std::vector<std::string> profile_type,
          const std::string &dna_sequence);

  static string Profile::GetProfileCode(const vector<string> &profile_type,
                                        const string &dna_sequence);

  std::vector<std::string> get_type() const;

  std::string get_code() const;

  void set_code(const std::string &code);
};

#endif
