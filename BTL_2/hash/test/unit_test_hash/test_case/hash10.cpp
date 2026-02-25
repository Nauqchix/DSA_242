#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash10() {
  string name = "hash102";
    //! data ------------------------------------
    xMap<int, string> hash(xMap<int, string>::intKeyHash);
    xMap<int, string> copy(hash);
    //! expect ----------------------------------
    string expect =
        "\n\
==================================================\n\
capacity:   10\n\
size:       0\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

    //! output ----------------------------------
    stringstream output;
    output << "\n"
           << copy.toString();

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
