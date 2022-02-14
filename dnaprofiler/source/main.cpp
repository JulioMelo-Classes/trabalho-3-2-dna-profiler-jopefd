#include "database.hpp"
#include "dna.hpp"
#include "io.hpp"
#include "profile.hpp"

int main(int argc, char **argv) {
  const Database database(argv[1]);
  const Profile profile(database.get_profile().get_type());
  const DNA dna_input(profile.get_type(), argv[2]);

  IO::WriteResult(database.Find(dna_input.get_profile().get_code()));
}
