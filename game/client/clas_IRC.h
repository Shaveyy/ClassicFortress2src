#ifndef HEADER_IRC
#define HEADER_IRC
namespace IRC
{
	void StartIRC();
	void CloseConnection();
	void RecvMessage();
	void PostMessageToChat();
	int CreateConnection();
}
#endif