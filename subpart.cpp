#include "subpart.h"
#include "tictoc.h"
#include <ctime>

void delayOneClockIncrement() {
    _TICTOC_TIC_FUNC
    clock_t start = clock();
    while (clock() == start) {
        ;//blank
    }
    _TICTOC_TOC_FUNC
}
