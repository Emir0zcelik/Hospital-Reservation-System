#include "Doctor.h"

#include <iostream>

Doctor::Doctor()
{
}

Doctor::Doctor(int doc_id, int dep_id, int doc_shift_start, int doc_shift_end, string name)
{
	this->doc_id = doc_id;
	this->dep_id = dep_id;
	this->doc_shift_start = doc_shift_start;
	this->doc_shift_end = doc_shift_end;
	this->name = name;
}

Doctor::Doctor(const Doctor &doc){
	doc_id = doc.doc_id;
	dep_id = doc.dep_id;
	doc_shift_start = doc.doc_shift_start;
	doc_shift_end = doc.doc_shift_end;
}


void Doctor::set_doc_id(int doc_id){
	this->doc_id = doc_id;
}

int Doctor::get_doc_id() const {
	return doc_id;
}

void Doctor::set_dep_id(int dep_id){
	this->dep_id = dep_id;
}

int Doctor::get_dep_id() const {
	return dep_id;
}

int Doctor::get_shift_start()const {
	return doc_shift_start;
}

int Doctor::get_shift_end()const {
	return doc_shift_end;
}

string Doctor::get_doc_name()const{
	return name;
}
