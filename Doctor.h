#ifndef _DOCTOR_H
#define _DOCTOR_H
#include "Person.h"

class Doctor : public Person {
private:
	int doc_id, dep_id, doc_shift_start, doc_shift_end;
	string name;
public:
	Doctor();

	Doctor(int doc_id, int dep_id, int doc_shift_start, int doc_shift_end, string name);
	// Copy constructor
	Doctor(const Doctor &doc1);
	
	void set_doc_id(int doc_id);
	void set_dep_id(int dep_id);
	int get_doc_id() const;
	int get_dep_id() const;
	int get_shift_start()const;
	int get_shift_end()const;
	string get_doc_name()const;
};

#endif
