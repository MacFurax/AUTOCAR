// send_MultiCast_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	// multicast group
	Poco::Net::SocketAddress mcGroup("239.255.255.250", 1900);
	Poco::Net::MulticastSocket ms(Poco::Net::SocketAddress("127.0.0.1", 1900));
	
	char buffer[512];
	int n;

	buffer[0] = 'Y';
	buffer[1] = 'o';
	buffer[2] = 'i';
	buffer[3] = 0;
	n = 3;

	ms.sendTo(buffer, n, mcGroup);

	ms.close();

    return 0;
}

