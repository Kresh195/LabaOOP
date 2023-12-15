#include "PracticeResults.h"

bool PracticeResults::getDiary() const {
	return diary;
}

bool PracticeResults::getEmployerFeedback() const {
	return employerFeedback;
}

void PracticeResults::setDiary(bool diary) {
	this->diary = diary;
}

void PracticeResults::setEmployerFeedback(bool employerFeedback) {
	this->employerFeedback = employerFeedback;
}

ostream& operator<<(ostream& out, PracticeResults& object) {
    out << "���: " << object.name << endl;
    out << "�������� ������: " << object.title << endl;
    out << "��� ������: ����� �� ��������" << endl;
    out << "���������� �������: " << object.pageCount << endl;
    out << "������� ��������: " << object.plagiarismRate << endl;
    out << "������� ���������������: " << object.selfcitationRate << endl;
    out << "������� ��������: ";
    if (object.diary)
        out << "����" << endl;
    else
        out << "���" << endl;
    out << "������� ������ ������������: ";
    if (object.employerFeedback)
        out << "����" << endl;
    else
        out << "���" << endl;
    out << "��������� ��������: ";
    if (object.result)
        out << "��������" << endl;
    else
        out << "�� ��������" << endl;
    return out;
}