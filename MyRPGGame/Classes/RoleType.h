#pragma once

//
// ��ɫ�ƶ�����
//
typedef enum RoleDirect
{
	roleNone,
	roleLeft,
	roleRight,
	roleUp,
	roleDown,
	roleUpLeft,
	roleUpRight,
	roleDownLeft,
	roleDownRight,
};

//
// ��ɫ������־
//
typedef enum RoleFlag
{
	// վ��
	flagStand,
	// ����
	flagDrop,
	// ����
	flagJump,
	// �¶�
	flagSquat,
};


//
// ��ɫ��������
//
typedef enum RoleActionBase
{
	// ��
	actionNone,
	// ����
	actionAttack,
	// ������
	actionHurt,
	// �ƶ�
	actionMove,
	// ��
	actionRun,
	// ����
	actionDefense
};


//
// ��ɫ����
//
typedef enum CommandType
{
	// ��
	noneCommand,
	// ����
	attackCommand,
	// ����
	waitCommand,
	// �ƶ�
	moveCommand,
	// ����ƶ�
	moveBackCommand,
	// ��
	runCommand,
	// ����
	defenseCommand
};


typedef enum ScriptType
{
	scriptRobot
};

struct RoleData
{
	int roleId;
	float px;
	float py;
	ScriptType scriptType;
	RoleData()
	{
		this->roleId = 0;
		this->px = 0;
		this->py = 0;

	}

	RoleData(const int roleId, const float px, const float py, const ScriptType scriptType)
	{
		this->roleId = roleId;
		this->px = px;
		this->py = py;
		this->scriptType = scriptType;
	}
};


