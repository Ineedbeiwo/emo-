#include <QMessageBox>
#include <QDebug>
#include "singledevicelogin.h"
//#include "ui_singledevicelogin.h"


SingleDeviceLogin::SingleDeviceLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleDeviceLogin)
{
   
    ui->setupUi(this);
    setWindowTitle(tr("Single Device Login"));
    clearParam();
}

SingleDeviceLogin::~SingleDeviceLogin()
{
    delete ui;
}

void SingleDeviceLogin::on_QuitButton_clicked()
{
    this->close();
}

void SingleDeviceLogin::on_OKButton_clicked()
{
    m_AcessToken = ui->Token_lineEdit->text();
    std::string act = m_AcessToken.toStdString();
    m_AppKey = ui->AppKey_lineEdit->text();
    m_DevSerial = ui->DevSerial_lineEdit->text();
 
    QString ChannelNo = ui->Channel_lineEdit->text();
 
    m_SuperSerial = ui->SuperSerial_lineEdit->text();
    qDebug()<<">>>>>>>>>>>>>>input m_SuperSerial:"<<m_SuperSerial;
    
    m_Channel = ChannelNo.toInt();

    this->close();

}

void SingleDeviceLogin::getTokenFromLogin(QString& acToken)
{
    acToken = m_AcessToken;
}

void SingleDeviceLogin::getAppKeyFromLogin(QString& appKey)
{
    appKey = m_AppKey;
}

void SingleDeviceLogin::getDevSerialFromLogin(QString& devSerial)
{
    devSerial = m_DevSerial;
}

void SingleDeviceLogin::getChannelFromLogin(int& channel)
{
    channel = m_Channel;
}

void SingleDeviceLogin::getSuperSerialFromLogin(QString& superSerial)
{
    qDebug()<<">>>>>>>>>>>>>>m_SuperSerial:"<<m_SuperSerial; 
    superSerial = m_SuperSerial;
}
void SingleDeviceLogin::clearParam()
{
    m_AcessToken.clear();
    m_AppKey.clear();
    m_DevSerial.clear();
    m_SuperSerial.clear();
    m_Channel = 0;
}
