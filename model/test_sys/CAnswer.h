#ifndef CANSWER_H_INCLUDE
#define CANSWER_H_INCLUDE

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../../pcgGlobal.h"
#include "BaseModelObject.h"

class CAnswer : public BaseModelObject {
public:
	CAnswer(){}
	CAnswer(int id, string text, bool currect);
	void create(int id, string text, bool currect);
	
	string get_text() { return text; }
	bool is_currect() { return currect;	}
protected:
	string text; //	SAM VOPROS
	bool currect;  // PRAVILNIY ILI NET
};

#endif
