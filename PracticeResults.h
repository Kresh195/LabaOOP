#pragma once
#include "AntiplagiarismResults.h"

class PracticeResults : public AntiplagiarismResults{
private: 
	bool diary;
	bool employerFeedback;

public:
	PracticeResults(const char* name, const char* title): AntiplagiarismResults(name, title) {}

	bool getDiary() const;

	bool getEmployerFeedback() const;

	void setDiary(bool diary);

	void setEmployerFeedback(bool employerFeedback);

	friend ostream& operator<<(ostream& out, PracticeResults& object);
};


