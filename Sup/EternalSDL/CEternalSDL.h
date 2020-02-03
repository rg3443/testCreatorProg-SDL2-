#ifndef CETERNALSDL_H_INCLUDED
#define CETERNALSDL_H_INCLUDED

class CEternalSDL {
public:
	CEternalSDL() {}
	void setup(QAB * qb);
	
protected:
	QAB * qb;
	baseSDL cast;
	
	
};

#endif