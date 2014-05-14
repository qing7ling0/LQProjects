#pragma once
// ������Ҫ ���ܷ��������͹�������Ϣ
#include <queue>
#include "SocketThread.h"
#include "Packet.h"

class RecvThread : public SocketThread
{
public:	
	~RecvThread(void);
	RecvThread(ODSocket *socket, std::queue<Packet*>* recvQueue):SocketThread(socket)
	{
		this->recvQueue = recvQueue;
	};

	void start(void) override {
		SocketThread::start();
	};

protected:
	void run(void) override;
	void recvPacket();
	std::queue<Packet*>* recvQueue;
};
