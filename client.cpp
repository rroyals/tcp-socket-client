#include "client.hpp"

using namespace std;

#define SERVER_IP     "127.0.0.1"
#define SERVER_PORT   13374

int main() {

	WSAData win_sock_data;
	WORD dll_version;


	dll_version = MAKEWORD(2, 1);
	WSAStartup(dll_version, &win_sock_data);

	char buf[4096];
	ZeroMemory(buf, 4096);

	SOCKADDR_IN address;
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, NULL);
	address.sin_addr.s_addr = inet_addr(SERVER_IP);
	address.sin_family = AF_INET;
	address.sin_port = htons(SERVER_PORT);

	cout << "CLIENT :: Connecting..." << endl;;

	connect(sock, (SOCKADDR*)&address, sizeof(address));

	int recv_data = recv(sock, buf, 4096, NULL);
	cout << "Message from the server :: " << string(buf, 0, recv_data)  << endl;

	std::string s_reflect;
	std::cout << "Reflect a String (no spaces) :: ";
	std::cin >> s_reflect;

	send(sock, s_reflect.c_str(), s_reflect.length(), NULL);

	recv_data = recv(sock, buf, 4096, NULL);

	cout << "Message from the server :: " << string(buf, 0, recv_data) << endl;

	system("pause");

		

}