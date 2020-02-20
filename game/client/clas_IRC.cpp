#include "cbase.h"
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <locale>
#include "clas_irc.h"
#include <regex>
#include <thread>
#include "dbg.h"
/*
================================================================
Helpful links:
Docs for general irc.
https://dev.twitch.tv/docs/irc
Commands documentation.
https://dev.twitch.tv/docs/irc/commands
Membership guide (weird ttv stuff).
https://dev.twitch.tv/docs/irc/membership
================================================================
Twitch sends a PING message every 10 minutes, respond with PONG.
if (buffer == "PING")
   send(Socket, "PONG\r\n", strlen("PONG\r\n"), 0);
================================================================
WSACleanup();
closesocket(Socket);
Move this to its own function, since we dont really need to close the socket unless the game is closed.
================================================================
TODO:
Add SSL to prevent man in the midddle attacks to get our OAUTH.
*/
using namespace std;
#pragma comment(lib,"ws2_32.lib")
#pragma warning( disable : 4996)
SOCKET Socket;
string IRC_Message;
int nDataLength;
char buffer[100000];
int i = 0;
string channeltojoin = "JOIN #rocketleague\r\n";// all channel names MUST be lowercase or irc freaks out.
void PostMessageToChat(string msg, string channel) {
    string actualmsg = "PRIVMSG #" + channel + " : " + msg + "\r\n";
    send(Socket, actualmsg.c_str(), strlen(actualmsg.c_str()), 0);

}
string parseMessage(string msg) {
    std::regex rgx(":(.*?)!.............................(.*?)#(.*?):(.*)");
    std::smatch match;
    if (std::regex_search(IRC_Message, match, rgx))
        return match[4];
    /*
    match[1] is usernames,
    match[2] is message_type,
    match[3] is current channel,
    and match[4] is message.
    my regex is a bit broken but it works, so yeah!
    */
    return "reg error \r\n";
}
int IRC::CreateConnection() {
    std::thread connection(StartIRC);
    connection.detach();// We detach it from the current thread, so we dont stop the current thread dead in its tracks!
    return 0;
}
void IRC::StartIRC() {

    WSADATA wsaData;
    SOCKADDR_IN SockAddr;
    int lineCount = 0;
    int rowCount = 0;
    struct hostent* host;
    locale local;

    // IRC url
    string url = "irc.chat.twitch.tv";
    string userconnectionstring1 = "NICK shaveyy\r\n"; // username can be anything lowercase!
    string userconnectionstring2 = "PASS oauth:waj3xbpmhf2laqc9o52h2xsvrze9qd\r\n"; // go to this site for your oauth https://twitchapps.com/tmi/, OR you can get your oauth with the twitch api at https://dev.twitch.tv/docs/authentication/getting-tokens-oauth

    WSAStartup(MAKEWORD(2, 2), &wsaData);
    Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    host = gethostbyname(url.c_str());
    SockAddr.sin_port = htons(6667);
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

    if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
        cout << "Could not connect";

    // Send LOGIN strings.
    send(Socket, userconnectionstring2.c_str(), strlen(userconnectionstring2.c_str()), 0);
    send(Socket, userconnectionstring1.c_str(), strlen(userconnectionstring1.c_str()), 0);
    // Send channel we want to join.
    send(Socket, channeltojoin.c_str(), strlen(channeltojoin.c_str()), 0);
    string lol = "PRIVMSG #dwight_lol :Me :)\r\n";
    //send(Socket, lol.c_str(), strlen(lol.c_str()), 0);
    Msg("Connected to twitch!\r\n");
    RecvMessage();
}
string newline = "\r\n";
void IRC::RecvMessage() {
    while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0) {
        int i = 0;
        int ii = 0;
        while (buffer[i] >= 1 || buffer[i] == '\n' || buffer[i] == '\r') {
            IRC_Message += buffer[i];
            i += 1;
            if (buffer == "PING")
                send(Socket, "PONG\r\n", strlen("PONG\r\n"), 0);
        }
        ii++;
        Msg(parseMessage(IRC_Message).c_str());
        Msg("\r\n");
        IRC_Message.clear();
    }
}