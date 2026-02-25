#include "../unit_test_hash.hpp"
bool UNIT_TEST_Hash::hash38()
{
    string name = "hash107";
    //! data ------------------------------------
    xMap<int *, string> hash(&newINT_keyHash, 0.45, 0,
                             xMap<int *, string>::freeKey);

    hash.put(new int(1), "votien1");
    hash.put(new int(11), "votien11");
    hash.put(new int(3), "votien3");
    //! expect ----------------------------------
    string expect =
        "\n\
==================================================\n\
capacity:   10\n\
size:       3\n\
0   : \n\
1   :  (n_1,votien1); (n_11,votien11)\n\
2   : \n\
3   :  (n_3,votien3)\n\
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
           << hash.toString(&newINT_toString);

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
