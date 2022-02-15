#include "io.hpp"

using std::cout;
using std::endl;
using std::string;

const string IO::kBlue = "\033[0;34m";
const string IO::kGreen = "\033[0;32m";
const string IO::kRed = "\033[0;31m";
const string IO::kNoColor = "\033[0m";

void IO::WriteHeader() {
  cout << endl
       << "==================================================" << endl
       << "  Welcome to the Basis DNA Profiler, v1.0" << endl
       << "  Copyright (C) 2022, João Pedro F. Dantas" << endl
       << "==================================================" << endl
       << endl
       << endl
       << IO::kBlue << "This program loads a DNA database and an unknown"
       << endl
       << "DNA sequence and tries to find a match between" << endl
       << "the input DNA sequence an the DNA database." << IO::kNoColor << endl
       << endl;
}

void IO::WriteDatabaseRead(const string &database_filepath) {
  cout << "[+] Preparing to read the DNA database file [" << IO::kRed
       << database_filepath << IO::kNoColor << "]" << endl;
}

void IO::WriteDNASequenceRead(const string &dna_sequence_filepath) {
  cout << "[+] Preparing to read the DNA sequence file [" << IO::kRed
       << dna_sequence_filepath << IO::kNoColor << "]" << endl;
}

void IO::WriteProcessingData() {
  cout << "[+] Processing data, please wait." << endl << endl;
}

void IO::WriteFilesRead() {
  cout << "[+] Input files successfully read." << endl;
}

void IO::WriteSearching() {
  cout << "[+] Searching the database for a match... please wait." << endl
       << endl;
}

void IO::WriteResult(const string &result) {
  if (result.empty()) {
    cout << ">>> Sorry, no match in our database." << endl << endl;
  } else {
    cout << "DNA Profile: " << result << endl << endl;
  }
}