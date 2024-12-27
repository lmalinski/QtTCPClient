#ifndef CLIENTMW_H
#define CLIENTMW_H

#include <QMainWindow>

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

private:
    Ui::ClientMW *ui;
};
#endif // CLIENTMW_H
