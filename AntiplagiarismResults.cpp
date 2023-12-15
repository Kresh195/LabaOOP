#include "AntiplagiarismResults.h"

AntiplagiarismResults::AntiplagiarismResults(const char* name, const char* title, WorkType workType, int pageCount) {
    if (strlen(name) == 0 || name == nullptr) 
        throw std::invalid_argument("��� �������� �� ������.");
    if (strlen(title) == 0 || title == nullptr)
        throw std::invalid_argument("�������� ������ �� ������.");
    if (workType < labReport || workType > practiceReport)
        throw std::invalid_argument("��� ������ ������� �� ���������� ���������.");
    this->workType = workType;
    if (pageCount <= 0)
        throw std::invalid_argument("���������� ������� ������ ���� ����������� ������.");
    else this->pageCount = pageCount;
    char* nameBuffer = new char[strlen(name) + 1];
    char* titleBuffer = new char[strlen(title) + 1];
    strcpy_s(nameBuffer, strlen(name) + 1, name);
    strcpy_s(titleBuffer, strlen(title) + 1, title);
    this->name = nameBuffer;
    this->title = titleBuffer;
}

AntiplagiarismResults::AntiplagiarismResults(const char* name, const char* title) {
    if (strlen(name) == 0 || name == nullptr)
        throw std::invalid_argument("��� �������� �� ������.");
    if (strlen(title) == 0 || title == nullptr)
        throw std::invalid_argument("�������� ������ �� ������.");
    char* nameBuffer = new char[strlen(name) + 1];
    char* titleBuffer = new char[strlen(title) + 1];
    strcpy_s(nameBuffer, strlen(name) + 1, name);
    strcpy_s(titleBuffer, strlen(title) + 1, title);
    this->name = nameBuffer;
    this->title = titleBuffer;
}

AntiplagiarismResults::~AntiplagiarismResults() {
    delete[] name;
    delete[] title;
}

WorkType AntiplagiarismResults::getWorktype() const {
    return workType;
}

int AntiplagiarismResults::getPageCount() const {
    return pageCount;
}

double AntiplagiarismResults::getPlagiarismRate() const {
    return plagiarismRate;
}

double AntiplagiarismResults::getSelfcitationRate() const {
    return selfcitationRate;
}

bool AntiplagiarismResults::getResult() const {
    return result;
}

void AntiplagiarismResults::setPlagiarsimRate(double rate) {
    if (rate < 0 || rate>100) {
        throw std::invalid_argument("������� ����� ���� � ��������� �� 0 �� 100.");
    }
    plagiarismRate = rate;
    if (plagiarismRate < 100 - passCheckPercent)
        result = true;
}

void AntiplagiarismResults::setSelfcitationRate(double rate) {
    if (rate < 0 || rate>100) {
        throw std::invalid_argument("������� ����� ���� � ��������� �� 0 �� 100.");
    }
    else 
        selfcitationRate = rate;
}

void AntiplagiarismResults::setWorkType(enum WorkType type) {
    this->workType = type;
}

void AntiplagiarismResults::setPageCount(int count) {
    this->pageCount = count;
}

void AntiplagiarismResults::printResult() {
    cout << "��������� ��������: ";
    if (result) 
        cout << "��������, ";
    else
        cout << "�� ��������, ";
    cout << "������� �������� ���������� " << plagiarismRate << "%." << endl;
}

bool AntiplagiarismResults::CheckVolumeCorrectness() const {
    if ((workType == GQW && (pageCount < pagesValues(GQW_minPages) || pageCount > pagesValues(GQW_maxPages))) ||
        (workType == coursework && (pageCount < pagesValues(coursework_minPages) || pageCount > pagesValues(coursework_maxPages))) ||
        (workType == labReport && (pageCount < pagesValues(labReport_minPages) || pageCount > pagesValues(labReport_maxPages))) ||
        (workType == practiceReport && pageCount <= pagesValues(practiceReport_minPages))) {
        return true;
    }
    return false;
}

void AntiplagiarismResults::getOriginalityResult() {
    double originalityRate = 100 - plagiarismRate + selfcitationRate;
    if (selfcitationRate > plagiarismRate)
        throw std::invalid_argument("����� ��������������� ��������� ������� ��������.");
    else {
        if (originalityRate > passCheckPercent) {
            result = true;
        }
        else
            result = false;
    }
}

void AntiplagiarismResults::getOriginalityResult(int checkRateThreshold) {
    double originalityRate = 100 - plagiarismRate + selfcitationRate;
    if (selfcitationRate > plagiarismRate)
        throw std::invalid_argument("����� ��������������� ��������� ������� ��������.");
    else {
        if (originalityRate > checkRateThreshold) {
            result = true;
        }
        else
            result = false;
    }
}

ostream& operator<<(ostream& out, AntiplagiarismResults& object) {
    out << "���: " << object.name << endl;
    out << "�������� ������: " << object.title << endl;
    out << "��� ������: ";
    switch (object.workType) {
    case WorkType(0):
        out << "����� �� ������������ ������" << endl;
        break;
    case WorkType(1):
        out << "���" << endl;
        break;
    case WorkType(2):
        out << "�������� ������" << endl;
        break;
    case WorkType(3):
        out << "����� �� ��������" << endl;
        break;
    }
    out << "���������� �������: " << object.pageCount << endl;
    out << "������� ��������: " << object.plagiarismRate << endl;
    out << "������� ���������������: " << object.selfcitationRate << endl;
    out << "��������� ��������: ";
    if (object.result)
        out << "��������" << endl;
    else
        out << "�� ��������" << endl;
    return out;
}

void AntiplagiarismResults::operator+=(int count) {
    pageCount += count;
}

void AntiplagiarismResults::operator-=(int count) {
    if (count > pageCount)
        throw std::invalid_argument("���������� ���������� ������� ��������� ���������� �������!");
    pageCount -= count;
}
