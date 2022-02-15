#include "database.hpp"
#include "dna.hpp"
#include "io.hpp"
#include "profile.hpp"

int main(int argc, char **argv) {
  IO::WriteHeader();

  const Database database(argv[1]);
  IO::WriteDatabaseRead(argv[1]);

  const Profile profile(database.get_profile().get_type());

  const DNA dna_input(profile.get_type(), argv[2]);
  IO::WriteDNASequenceRead(argv[2]);

  IO::WriteProcessingData();
  IO::WriteFilesRead();
  IO::WriteSearching();

  IO::WriteResult(database.Find(dna_input.get_profile().get_code()));
}
