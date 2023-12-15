#include <iostream>
#include <stdio.h>
#include <cstring>
#include "AntiplagiarismResults.h"
#include "PracticeResults.h"


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
        cout << firstWork << endl << endl;
    }
    catch (const std::invalid_argument& error) {
        cerr << error.what() << endl;
    }

    double secondPlagiarismRate = 53.6;
    double secondSelfcitationRate = 33.2;
    const char* secondStudentName = "Leha";
    const char* secondWorkTitle = "Practice in Zavod";
    int secondPagesCount = 37;
    try {
        PracticeResults secondWork(secondStudentName, secondWorkTitle);
        secondWork.setPageCount(secondPagesCount);
        secondWork.setPlagiarsimRate(secondPlagiarismRate);
        secondWork.setSelfcitationRate(secondSelfcitationRate);
        secondWork.setDiary(true);
        secondWork.setEmployerFeedback(true);
        secondWork.setWorkType(WorkType(2));
        secondWork.getOriginalityResult();
        secondWork.CheckVolumeCorrectness();
        cout << secondWork.getWorktype();
    }
    catch (const std::invalid_argument& error) {
        cerr << error.what() << endl;
    }

    return 0;
}