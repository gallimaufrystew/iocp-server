
#include <tchar.h>
#include "EchoHandler.h"

void RunNormalServer(bool sendGracefulShutdownMessage)
{
	using namespace iocp;

	//std::shared_ptr<CEchoHandler> h(
	//	new CEchoHandler(sendGracefulShutdownMessage)
	//	);
	auto h = std::make_shared<CEchoHandler>(sendGracefulShutdownMessage);

	//! Simple echo server that receives and sends at normal rate.
	//CIocpServer *echoServer = new CIocpServer(50000,h);
	auto echoServer = std::make_unique<CIocpServer>(50000, h);

	// enter something in to exit
	char c;
	std::cin >> c;

	//delete echoServer;
}

void RunSlowReader(bool sendGracefulShutdownMessage)
{
	using namespace iocp;

	//std::shared_ptr<CEchoHandler> h(
	//	new CEchoHandler(sendGracefulShutdownMessage)
	//	);

	auto h = std::make_shared<CEchoHandler>(sendGracefulShutdownMessage);

	//! Stress test server that receives with 1 byte buffer. This will
	//! maximize the number of IO Completion port traffic.
	//CIocpServer *echoServer =
	//	new CIocpServer(50000,h, INADDR_ANY, 1);

	auto echoServer = std::make_unique<CIocpServer>(50000,h, INADDR_ANY, 1);

	// enter something in to exit
	char c;
	std::cin >> c;

	//delete echoServer;
}

int main()
{
	//RunSlowReader(false);
	RunNormalServer(false);

	return 0;
}
