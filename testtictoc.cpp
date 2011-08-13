/* 
 * File:   testtictoc.cpp
 * Author: Marc
 *
 * Created on December 3, 2009, 2:31 PM
 */

#include <stdlib.h>
#include <iostream>
#include "tictoc.h"
#include "Timer.h"
#include "subpart.h"
using namespace TICTOC;
using namespace std;
/*
 * 
 */


void delayms (int nms);
void testTicToc();

int main(int argc, char** argv) {

    testTicToc();
    return (EXIT_SUCCESS);
}

void delayms (int nms) {
    _TICTOC_TIC_FUNC
    static Timer tim;
    tim.start();
    while (tim.getElapsedTimeInMilliSec() < nms) {
        ; //intentionally blank
    }
    tim.stop();
    _TICTOC_TOC_FUNC
}

void testTicToc() {
    tictoc bob;
    bob.tic("timer tic");
   // tictoc& timer = *(tictoc::timer);
    timer().tic("all");
    bob.toc("timer tic");
    for (int j = 0; j < 10; ++j) {
        bob.tic("timer tic");
        timer().tic("outer loop");
        bob.toc("timer tic");

        delayOneClockIncrement();

        for (int k = 0; k < 10; ++k) {
            bob.tic("timer tic");
            timer().tic ("inner loop");
            bob.toc("timer tic");
            delayms(1);
            bob.tic("timer toc");
            timer().toc ("inner loop");
            bob.toc("timer toc");
        }
        bob.tic("timer toc");
        timer().toc ("outer loop");
        bob.toc("timer toc");
    }
    bob.tic("timer toc");
    timer().toc("all");
    bob.toc("timer toc");
    cout << timer().generateReport();
    cout << "\n" << bob.generateReport();
    cout << "\naverage time for inner loop: " << timer().getStatistics("inner loop") << "\n";
}
