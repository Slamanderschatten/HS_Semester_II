


#include "_MAIN.h"
#include "E_VI/E_VI.h"





#define TASK 6
#define SUBTASK 2








int main() {
    using namespace hs_pro_II;
    using namespace std;


#if TASK == 6

#if SUBTASK == 1
    {
        E_VI::recursiveAnalyse(0);
    }
#endif

#if SUBTASK == 2
    {
        E_VI::testGraph_II_a();
        cout << endl << endl;
        E_VI::testGraph_II_b();
    }
#endif

#endif






    return 0;
}
