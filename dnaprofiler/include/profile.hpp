#ifndef DNAPROFILER_PROFILE_H_
#define DNAPROFILER_PROFILE_H_

#include <string>
#include <vector>

class Profile {
 private:
  std::vector<std::string> type_;
  std::string code_;

  /**
   * \brief Implementation of KMP search from GeeksForGeeks
   * 
   * https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
   *
   * \param pat
   * \param M
   * \param lps
   */
  static void computeLPSArray(std::string pat, int M, int lps[]);

  /**
   * \brief Implementation of KMP search from GeeksForGeeks
   * 
   * https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
   *
   * \param pat
   * \param txt
   * \return int
   */
  static int KMPSearch(std::string pat, std::string txt);

 public:
  /**
   * \brief Construct a new Profile object
   *
   * \param profile_type
   */
  Profile(const std::vector<std::string> profile_type);

  /**
   * \brief Construct a new Profile object
   *
   * \param profile_type
   * \param dna_sequence
   */
  Profile(const std::vector<std::string> profile_type,
          const std::string &dna_sequence);

  /**
   * \brief Get the Profile Code object
   *
   * \param profile_type
   * \param dna_sequence
   * \return std::string
   */
  static std::string GetProfileCode(
      const std::vector<std::string> &profile_type,
      const std::string &dna_sequence);

  /**
   * \brief Get the type object
   *
   * \return std::vector<std::string>
   */
  std::vector<std::string> get_type() const;

  /**
   * \brief Get the code object
   *
   * \return std::string
   */
  std::string get_code() const;

  /**
   * \brief Set the code object
   *
   * \param code
   */
  void set_code(const std::string &code);
};

#endif
