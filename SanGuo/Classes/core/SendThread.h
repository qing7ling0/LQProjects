#pragma once
// ������Ҫ ���͹�������Ϣ
#include "SocketThread.h"
#include "Packet.h"
#include <queue>

class SendThread : public SocketThread
{
public:	
	~SendThread(void);
	SendThread(ODSocket *socket, std::queue<Packet*>* sendQueue):SocketThread(socket)
	{
		this->sendQueue = sendQueue;
	}

	void start(void) override{
		SocketThread::start();
	};

protected:
	void run(void) override;
	std::queue<Packet*>* sendQueue;
};
