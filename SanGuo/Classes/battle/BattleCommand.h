#pragma once
#include "QConfig.h"
#include "BattleControl.h"

class BattleCommand : public Object
{
public:
	BattleCommand(void);
	~BattleCommand(void);

	virtual void init();

	virtual void doing(float dt);

	virtual void over();

	virtual void dispose();

protected:
	 BattleControl *_battleControl;
};

class GameStartCommand : public BattleCommand
{
public:
	GameStartCommand(void);
	~GameStartCommand(void);

	void init() override;

	void doing(float dt) override;

	void over() override;

	void dispose() override;
};

/**
* �Լ��Ļغ�
*/
class SelfRoundCommand : public BattleCommand
{
public:
	SelfRoundCommand(void);
	~SelfRoundCommand(void);

	void init() override;

	void doing(float dt) override;

	void over() override;

	void dispose() override;

protected:
	void start();
	bool _start;
};

/**
* �Է��Ļغ�
*/
class OtherRoundCommand : public BattleCommand
{
public:
	OtherRoundCommand(void);
	~OtherRoundCommand(void);

	void init() override;

	void doing(float dt) override;

	void over() override;

	void dispose() override;
};

/**
* �ȴ���һ�غ�
*/
class WaitNextRoundCommand : public BattleCommand
{
public:
	WaitNextRoundCommand(void);
	~WaitNextRoundCommand(void);

	void init() override;

	void doing(float dt) override;

	void over() override;

	void dispose() override;
};
