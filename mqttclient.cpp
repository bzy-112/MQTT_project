#include "widget.h"

void Widget::clientMqtt() {
    //初始化MQTT
    client = new QMqttClient();

    //连接指定服务器
    QString host("192.169.137.1");
    //代理服务器端口
    quint16 port = 1883;
    client->setKeepAlive(120); //设置心跳
    client->setHostname(host); //设置IP地址
    client->setPort(port); //设置端口号

    //连接
    client->connectToHost();

    //在给定时间到达后触发一个槽函数
    //并且只触发一次
    // QMqttTopicFilter
    QTimer::singleShot(1000, this, [ = ]() {
        // client->subscribe()
    });

    /*
        QTimer::singleShot(1000, this, [ = ]()
        {
            client->subscribe("LED1", 0); // 订阅LED1主题
            client->subscribe("LED2", 0); // 订阅LED2主题
            client->subscribe("LED3", 0); // 订阅LED3主题
            client->subscribe("LED4", 0); // 订阅LED4主题
            client->subscribe("DHT11", 0);//订阅DHT11主题
            client->subscribe("fumes", 0);//订阅烟雾主题
            client->subscribe("light", 0);//订阅光照强度主题
            client->subscribe("CO2", 0);//订阅CO2主题
        });
    */
}
