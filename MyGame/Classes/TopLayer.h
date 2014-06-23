#pragma once
#include "RPGHead.h"

typedef enum TopUIBtnType
{
	TopBtnAttack = 1,
	TopBtnBack
};

/**
ս�����ϲ�
����ս����ť
ս����ʾ��UI

*/

class TopLayer : public Layer
{
public:
	TopLayer(void);
	~TopLayer(void);

	bool init(void);

	void gameStart();

	void yourTurn();

	void showImageEffect(const std::string &imageName);

	CREATE_FUNC(TopLayer);
};


class TopUILayer : public Layer
{
public:
	TopUILayer(void);
	~TopUILayer(void);

	bool init(void);

	Button* getBtn(TopUIBtnType btnType);

	CREATE_FUNC(TopUILayer);
private:
	Layout *_layout;
};

