#include <iostream>
#include <fstream>

using namespace std;

namespace cifra {
    class Cesar {
        public:
            void encripte(string fileIn, string fileOut, int k);
    };
}