#include "clientmw.h"
#include "qhostaddress.h"
#include "mytcpclient.h"
#include "ui_clientmw.h"

ClientMW::ClientMW(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientMW)
{
    ui->setupUi(this);
}

ClientMW::~ClientMW()
{
    delete ui;
}

QString ClientMW::composeIPAddres()
{
    QString address = ui->adr0Edit->text() + "." +
                      ui->adr1Edit->text() + "." +
                      ui->adr2Edit->text() + "." +
                      ui->adr3Edit->text();
    return address;
}

bool ClientMW::validateConnectionData(QString adr, int port)
{
    QHostAddress ipAdr(adr);
    if(ipAdr.protocol() != QAbstractSocket::IPv4Protocol)
    {
        ui->statusbar->showMessage("Invalid IPv4 Address!");
        return false;
    }
    if(port < 0 || 65535 < port)
    {
        ui->statusbar->showMessage("Invalid TCP port number!");
        return false;
    }
    return true;
}

void ClientMW::resetClient()
{
    if(m_client != nullptr)
    {
        m_client->disconnectFrom();
        disconnect(m_client);
        delete m_client;
    }
    m_client = new MyTCPClient(this);
    connect(m_client,SIGNAL(connected(QString,int)),this,SLOT(slot_connected(QString,int)));
    connect(m_client,SIGNAL(disconnected()),this,SLOT(slot_disconnected()));
}

void ClientMW::on_connectBut_clicked()
{
    //Pobranie i walidacja danych połączenia

    QString adr = composeIPAddres();
    int port = ui->portEdit->text().toInt();
    if(!validateConnectionData(adr, port))
        return;
    resetClient();
    m_client->connectTo(adr,port);

}

void ClientMW::slot_connected(QString adr, int port)
{
    ui->statusbar->showMessage("Connected to " + adr + " " + QString::number(port));
}

void ClientMW::slot_disconnected()
{
    ui->statusbar->showMessage("Disconnected");
}

void ClientMW::on_chkBut_clicked()
{
    if(m_client->isConnected())
        ui->statusbar->showMessage("Connected");
    else
        ui->statusbar->showMessage("Disconnected");
}

