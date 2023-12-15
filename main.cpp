#include <iostream>
#include <stdio.h>
#include <cstring>
#include "AntiplagiarismResults.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double plagiarismRate = 42.3;
    double selfcitationRate = 18.6;
    const char* StudentName = "Fedor";
    const char* WorkTitle = "Existence of life in space";
    int pagesCount = 52;
    try {
        AntiplagiarismResults firstWork(StudentName, WorkTitle, WorkType(GQW), pagesCount);
        firstWork.setPlagiarsimRate(plagiarismRate);
        firstWork.setSelfcitationRate(selfcitationRate);
        firstWork.getOriginalityResult();
        firstWork.CheckVolumeCorrectness();
        cout << firstWork;
    }
    catch (const std::invalid_argument& error) {
        cerr << error.what() << endl;
    }

    return 0;
}