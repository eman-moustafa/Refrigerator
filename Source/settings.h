#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE

namespace Ui {
class Settings;
}

class QIntValidator;
QT_END_NAMESPACE


class Settings : public QDialog
{
    Q_OBJECT

public:

    struct Setting {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };

    explicit Settings(QWidget *parent = nullptr);
    void showSettings();
    ~Settings();

      Setting settings() const;
private slots:
      void showPortInfo(int index);
      void apply();
      void checkCustomDevicePathPolicy(int index);

private:
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();

private:
    Ui::Settings *ui= nullptr;
    Setting currentSettings;
    QIntValidator *intValidator = nullptr;
};

#endif // SETTINGS_H
