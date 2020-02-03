#ifndef BASEMODELOBJECT_H_INCLUDED
#define BASEMODELOBJECT_H_INCLUDED

class BaseModelObject {
public:
	BaseModelObject() {}
	void set_id(int id) { this->id = id; }
	int get_id() { return id; } 
protected:
	int id;
};

#endif
