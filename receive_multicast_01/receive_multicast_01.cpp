// receive_multicast_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{

	// multicast group
	Poco::Net::SocketAddress mcGroup("239.255.255.250", 1900);

	// bind to any adresse here 0.0.0.0 by default and same port as group
	//Poco::Net::MulticastSocket socket(
	//	Poco::Net::SocketAddress(
	//		Poco::Net::IPAddress(), mcGroup.port()
	//	), true // reuse adresse
	//);


	// bind to 127.0.0.1
	Poco::Net::MulticastSocket socket(
		Poco::Net::SocketAddress(
			"127.0.0.1", mcGroup.port()
		), true // reuse adresse
	);

	// to receive any data you must join the multicast group
	socket.joinGroup(mcGroup.host());

	Poco::Net::SocketAddress sender;
	char buffer[512];

	std::cout << "Waiting for data ...\n";

	int n = socket.receiveFrom(buffer, sizeof(buffer), sender);
	//socket.sendTo(buffer, n, sender);

	std::cout << "Received " << n << " bytes from " << sender.toString() << " \n";

	socket.close();

    return 0;
}

