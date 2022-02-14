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

  static void WriteHeader();

  static void WriteDatabaseRead(const std::string &database_filepath);

  static void WriteResult(const std::string &result);
};

#endif
