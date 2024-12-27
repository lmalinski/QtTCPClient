#include "mytcpclient.h"

MyTCPClient::MyTCPClient(QObject *parent)
    : QObject{parent}
{
    connect(&m_socket,SIGNAL(connected()),this,SLOT(on_connected()));
    connect(&m_socket,SIGNAL(disconnected()),this,SIGNAL(disconnected()));
}

void MyTCPClient::connectTo(QString address, int port)
{
    m_ipAddress = address;
    m_port = port;
    m_socket.connectToHost(m_ipAddress,port);
}

void MyTCPClient::disconnectFrom()
{
    m_socket.close();
}

void MyTCPClient::on_connected()
{
    emit connected(m_ipAddress,m_port);
}
