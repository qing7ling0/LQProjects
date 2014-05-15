#pragma once
#include "RPGHead.h"

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

