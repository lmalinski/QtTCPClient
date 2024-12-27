#ifndef CLIENTMW_H
#define CLIENTMW_H

#include <QMainWindow>

class MyTCPClient;

QT_BEGIN_NAMESPACE
namespace Ui {
class ClientMW;
}
QT_END_NAMESPACE

class ClientMW : public QMainWindow
{
    Q_OBJECT

public:
    ClientMW(QWidget *parent = nullptr);
    ~ClientMW();

private slots:
    void on_connectBut_clicked();
    void slot_connected(QString adr, int port);
    void slot_disconnected();

    void on_chkBut_clicked();

private:
    QString composeIPAddres();
    bool validateConnectionData(QString adr, int port);
    void resetClient();
    Ui::ClientMW *ui;
    MyTCPClient *m_client = nullptr;
};
#endif // CLIENTMW_H
