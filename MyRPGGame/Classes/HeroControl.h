#pragma once
#include "RPGHead.h"
#include "HeroRole.h"

class HeroControl : public Ref
{
public:
	HeroControl(void);
	~HeroControl(void);

	virtual void init(HeroRole *role);

	/**
	* ���ƽ�ɫ�ƶ�
	* speedx speedy ��ɫ�ƶ��ٶ�
	* direct �ƶ������Ƿ�������ֵ��������
	* fast �Ƿ��ǳ����ƶ�
	*/
	virtual void doMove(float speedx, float speedy, RoleDirect direct, bool fast=false);

	virtual void move(float speedx, float speedy, float accx, float accy, bool fast=false);

	virtual void update(float dt);

	virtual void stop();

protected:
	HeroRole *_hero;

	/** �ƶ��ٶ� */
	Point _speed;

	/** ���ٶ� */
	Point _acc;

	/** �Ƿ����ƶ� */
	bool _fastMove;

	/** �ƶ����� */
	RoleDirect _roleDirect;

	RoleActionBase _roleActionFlag;
};

