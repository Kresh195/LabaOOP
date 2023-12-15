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
    out << "Имя: " << object.name << endl;
    out << "Название работы: " << object.title << endl;
    out << "Тип работы: отчёт по практике" << endl;
    out << "Количество страниц: " << object.pageCount << endl;
    out << "Процент плагиата: " << object.plagiarismRate << endl;
    out << "Процент самоцитирования: " << object.selfcitationRate << endl;
    out << "Наличие дневника: ";
    if (object.diary)
        out << "есть" << endl;
    else
        out << "нет" << endl;
    out << "Наличие отзыва работадателя: ";
    if (object.employerFeedback)
        out << "есть" << endl;
    else
        out << "нет" << endl;
    out << "Результат проверки: ";
    if (object.result)
        out << "Пройдена" << endl;
    else
        out << "Не пройдена" << endl;
    return out;
}