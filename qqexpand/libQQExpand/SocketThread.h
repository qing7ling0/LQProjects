#pragma once
#include <thread>
#include <mutex>
#include "ODSocket.h"

class SocketThread
{
public:	
	~SocketThread(void);
	SocketThread(ODSocket *socket);

	virtual	void start(void);

	//������ֹ��ǰ�̡߳�
	virtual void stop(void);

	virtual void run();

protected:

	// 0 ��ʾ���ӳɹ� 1 ��ʾ����ʧ��
	int state;

	ODSocket *socket;

	std::thread *mThread;

	bool isRun;
	std::mutex mMutex;
};

