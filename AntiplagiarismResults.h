#include <iostream>
#define AntiplagiarismResults_h

using namespace std;

enum WorkType {
    labReport, GQW, coursework, practiceReport
};

class AntiplagiarismResults {
private:
    const char* name;
    const char* title;
    WorkType workType;
    int pageCount;
    double plagiarismRate;
    double selfcitationRate;
    const int passCheckPercent = 70;
    bool result = false;
    enum pagesValues {
        GQW_minPages = 60,
        GQW_maxPages = 100,
        coursework_minPages = 15,
        coursework_maxPages = 25,
        labReport_minPages = 5,
        labReport_maxPages = 50,
        practiceReport_minPages = 20
    };

public:
    AntiplagiarismResults(const char* name, const char* title, WorkType workType, int pageCount);

    AntiplagiarismResults(const char* name, const char* title);

    ~AntiplagiarismResults();

    WorkType getWorktype() const; //все get должны быть const

    int getPageCount() const;

    double getPlagiarismRate() const;

    double getSelfcitationRate() const;

    bool getResult() const;

    void setPlagiarsimRate(double rate);

    void setSelfcitationRate(double rate);

    void setWorkType(enum WorkType type);

    void setPageCount(int count);

    void printResult();

    bool CheckVolumeCorrectness() const;

    void getOriginalityResult();

    void getOriginalityResult(int checkRateThreshold);

    void operator+=(int count);

    void operator-=(int count);

    friend ostream& operator<<(ostream& out, AntiplagiarismResults& object);
};