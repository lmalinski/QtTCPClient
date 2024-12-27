#include "clientmw.h"
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
