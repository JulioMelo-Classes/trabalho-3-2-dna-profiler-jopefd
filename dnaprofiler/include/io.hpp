#ifndef DNAPROFILER_IO_H_
#define DNAPROFILER_IO_H_

#include <iostream>
#include <string>

class IO {
 public:
  static const std::string kBlue;
  static const std::string kGreen;
  static const std::string kRed;
  static const std::string kNoColor;

  /**
   * \brief Write program header
   *
   */
  static void WriteHeader();

  /**
   * \brief Write confirmation of database reading
   *
   * \param database_filepath
   */
  static void WriteDatabaseRead(const std::string &database_filepath);

  /**
   * \brief Write confirmation of DNA sequence reading
   *
   * \param dna_sequence_filepath
   */
  static void WriteDNASequenceRead(const std::string &dna_sequence_filepath);

  /**
   * \brief Write message of data processing
   *
   */
  static void WriteProcessingData();

  /**
   * \brief Write confirmation of files reading
   *
   */
  static void WriteFilesRead();

  /**
   * \brief Write message of searching
   *
   */
  static void WriteSearching();

  /**
   * \brief Write result
   *
   * \param result
   */
  static void WriteResult(const std::string &result);
};

#endif
