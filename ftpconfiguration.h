#ifndef FTPCONFIGURATION_H
#define FTPCONFIGURATION_H

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QSettings>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>

class FTPConfiguration : public QWidget
{
    Q_OBJECT
public:
    explicit FTPConfiguration(QWidget *parent = 0);

protected:
    QSettings settings;

    const QString hostSettingName;
    const QString portSettingName;
    const QString usernameSettingName;
    const QString passwordSettingName;
    const QString basePathSettingName;
    const QString webPathSettingName;

    //Main layout and main form
    QVBoxLayout * layout;
    QGroupBox * mainGroupLayout;
    QFormLayout * formLayout;

    QLineEdit * host;
    QSpinBox * port;
    QLineEdit * username;
    QLineEdit * password;
    QLineEdit * basePath;
    QLineEdit * webPath;

    QHBoxLayout * validateLayout;
    QPushButton * validate;

    void setUpUI();

public slots :
    void hostSettingModified(QString);
    void portSettingModified(int);
    void usernameSettingModified(QString);
    void passwordSettingModified(QString);
    void basePathSettingModified(QString);
    void webPathSettingModified(QString);

};

#endif // FTPCONFIGURATION_H
