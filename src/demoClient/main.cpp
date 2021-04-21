#include "fenet/Fenet.h"
#include <cstdlib>
#include <string>
#include <iostream>



//int main()
//{
//	if (Network::Initialize() == FenetResult::fenetSuccess)
//	{
//		Socket socket;
//
//		if (socket.Create() == FenetResult::fenetSuccess)
//		{
//			if (socket.Connect(IPEndPoint("127.0.0.1", 4790)) == FenetResult::fenetSuccess) // 0.0.0.0 Means anything can connect
//			{
//				Packet packet;
//				Packet packet2;
//				std::string string1 = "Hello Server";
//				uint32_t  int2 = 1234567890;
//				std::string string3 = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, s";
//				char char4 = 'L';
//
//				packet << string3 << string1 << int2;
//				int result = FenetResult::fenetSuccess;
//				while (result == FenetResult::fenetSuccess)
//				{
//					result = socket.Send(packet);
//					if (result != FenetResult::fenetSuccess)
//					{
//						break;
//					}
//					Sleep(500);
//					//socket.Recieve(packet2);
//					//packet2 >> string3;
//					//std::cout << string3 << std::endl;
//					//result = socket.SendAll(buffer.data(), buffer.size());
//					//if (result != FenetResult::fenetSuccess)
//					//{
//					//	break;
//					//}
//
//				}
//
//			}
//			socket.Close();
//		}
//	}
//	Network::Shutdown();
//	system("pause");
//	return 0;
//
//}

int main()
{
	if (Network::Initialize() == FenetResult::fenetSuccess)
	{
		SSLSocket socket(IPVersion::IPv4);

		if (socket.Create() == FenetResult::fenetSuccess)
		{
			if (socket.Connect(IPEndPoint("127.0.0.1", 27050)) == FenetResult::fenetSuccess) // 0.0.0.0 Means anything can connect //127.0.0.1
			{
				Packet packet;
				Packet packet2;
				std::string string1 = "Hello Server";
				uint32_t  int2 = 1234567890;
				std::string string3 = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, s";
				char char4 = 'L';

				packet << string3 << string1 << int2;
				int result = FenetResult::fenetSuccess;
				while (result == FenetResult::fenetSuccess)
				{
					//result = FenetResult::fenetSuccess;
					//Sleep(10000);
					result = socket.Send(packet);
					if (result != FenetResult::fenetSuccess)
					{
						break;
					}
					Sleep(500);
					//socket.Recieve(packet2);
					//packet2 >> string3;
					//std::cout << string3 << std::endl;
					//result = socket.SendAll(buffer.data(), buffer.size());
					//if (result != FenetResult::fenetSuccess)
					//{
					//	break;
					//}

				}

			}
			socket.Close();
		}
	}
	Network::Shutdown();
	int stop;
	std::cin >> stop;
	return 0;

}