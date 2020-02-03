#ifndef CPRESENTER_H_INCLUDED
#define CPRESENTER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;

#include "../pcgGlobal.h"
#include "../Sup/QABsys/trueQAB.h"
#include "../model/CModel.h"
#include "../model/input/CInput.h"
#include "../view/CView.h"
#include "../Sup/SDL_stuf/CRenderGate.h"


class CPresenter {
public:
	CPresenter(){}
	void setup(QAB * qb);
	void prog_start();
	void prog_quit();
protected:
	QAB * qb;
	CModel model;
	CView output;
	CInput input;
	bool quit;
	
	CRenderGate screen_refresher;
	
};

#endif
