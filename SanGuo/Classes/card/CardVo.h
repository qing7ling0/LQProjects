#pragma once
#include <string>
#include "QConfig.h"

/** ���Ƥμ��� */
static const short CARD_SKILL = 1;

/** ���Ƥ�ʿ�� */
static const short CARD_SOLDIER = 2;

/** ���Ƥ�Ӣ�� */
static const short CARD_HERO = 3;

/** ���Ƥ����� */
static const short CARD_WEAPON = 4;

class CardVo : public Object
{
public:
	CardVo(void);
	~CardVo(void);
	std::string name;
	int attack;
	int life;
	int maxLife;
	int icon;
	short type;
	bool isEnemy;
	int fali;
	int maxFali;
	int armor;
	int id;
};