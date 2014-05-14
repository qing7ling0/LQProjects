#pragma once
#include "RPGHead.h"
#include "Role.h"
#include "HeroRole.h"
#include "TouchControl.h"
#include "HeroControl.h"
#include "HeroAnimi.h"

class RoleScript : public Ref
{
public:
	RoleScript(void);
	~RoleScript(void);

	virtual void init(HeroRole *role){}

	virtual void doScript(float dt){}

	virtual void update(float dt){}
	
	/**
	* ִ��һЩ��������Щ����ͨ������ҡ�˻��
	*/
	virtual void doTouchActions(std::vector<DirectionFlag> directionFlags){}

	virtual Node* createRoleNode(){ return nullptr; }

	virtual CommandType parseRoleAction(std::vector<DirectionFlag> directionFlags);
	
	/**
	* ������ɫ�ű�
	*/
	static RoleScript* createScript(ScriptType scriptType);

	/**
	* ���ݽ�ɫ������ȡ��ɫ������Ӧ�Ķ�������
	*/
	virtual int getRoleAnimiFlag(RoleActionBase action);
	
	/**
	* �����·�ٶ�
	*/
	virtual float getMoveSpeed() { return 50; }
	
	/**
	* ����ܲ��ٶ�
	*/
	virtual float getRunSpeed() { return getMoveSpeed() * 2; }
	
	/**
	* ������ٶ�
	*/
	virtual float getJumpSpeed() { return 30; }
	
	/**
	* ��������ٶ�
	*/
	virtual float getDropSpeed() { return getJumpSpeed(); }

protected:
	HeroRole *_hero;
};

