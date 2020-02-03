#include "CView.h"

void CView::setup(QAB * qb)
{
	this->qb = qb;
	keeper.setup(qb);
	drawer.insert_qab(qb);
	drawer.setup(qb->get_etrnd(), qb->get_etwnd());
	this->give_font();
}

void CView::draw(int question_id)
{
	//drawer.test_func();
	drawer.draw(question_id,qb->get_model());
}

void CView::give_font()
{
	russian_font_rend.setup(qb);
	drawer.set_otf_render(&russian_font_rend);
}
