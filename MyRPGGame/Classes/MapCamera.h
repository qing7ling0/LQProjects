#pragma once
#include "RPGHead.h"
#include "Role.h"
#include "MapControl.h"

typedef enum CameraType
{
	// ��ͷ�����������
	camera_none,

	// ��ͷ��Ӣ�ۿ���
	camera_hero,
};

class MapCamera : public Object
{
public:
	MapCamera(void);
	~MapCamera(void);

	virtual bool init(Size size, Size sceneSize);

	virtual void addObserved(Role *role);

	virtual void setMap(MapControl *map);

	virtual void setCameraType(CameraType type);

	//virtual void update(float dt);

	/**
	* ��⾵ͷ��û�г���
	* return true ���磻return false û�г���
	*/
	virtual bool checkBound(Point off);

	/**
	* ���þ�ͷ�۲��
	*/
	virtual void setCamera(const Point viewPosition);
	
	/**
	* ���þ�ͷ�۲��
	*/
	virtual void setCamera(float x, float y);

	/**
	* ������ͷ�۲��,���ܳ���
	*/
	virtual Point correctCamera(const Point viewPosition);

	virtual void update(float dt);

protected:

	/**
	* ��ͷ�����ƶ�
	*/
	virtual void updateCamera(const float x, const float y);

protected:
	// ��ͷ��С
	Size _size;

	// ��ͷ������С
	Size _sceneSize;

	// ��ͷƫ����
	Point _off;
	
	Vector<Role*> _observedRoles;

	MapControl* _map;

	CameraType _cameraType;

	bool _cameraUpdate;
};

