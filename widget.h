#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
//栈式布局管理器
#include <QStackedLayout>
#include "ledui.h"
#include "camreui.h"
#include "lightui.h"
#include "temphumtiyui.h"
#include "QtMqtt/QMqttClient"
#include <qmqttmessage.h>
#include <QtNetwork>
#include <QHostAddress>

class Widget : public QWidget
{
    Q_OBJECT

    QPushButton* LEDButton;
    QPushButton* TempHumtiyButton;
    QPushButton* LightButton;
    QPushButton* Camre;

    QStackedLayout* m_stacklayout;
    LEDUI* m_ledui;
    CAMREUI* m_camreui;
    LIGHTUI* m_lightui;
    TEMPHUMTIYUI* m_temphumtiyui;

    //Mqtt
    QMqttClient *client;


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_m_ledui_clicked();
    void on_m_camreui_clicked();
    void on_m_lightui_clicked();
    void on_m_temphumtiyui_clicked();

private:
    // 配置按键
    void setButton();
    // 设置主窗口背景图片
    void setBackgroundWindow();
    // 初始化MQTT客户端
    void clientMqtt();

protected:
    QSize sizeHint()const;
};

#endif // WIDGET_H
