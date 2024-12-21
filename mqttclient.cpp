#include "widget.h"

void Widget::clientMqtt() {
    //初始化MQTT
    client = new QMqttClient();

    //连接指定服务器
    QString host("192.168.137.1");
    // QHostAddress host("192.168.137.1"); // 代理服务器 IP
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
        client->subscribe(QMqttTopicFilter("LED1"), 0);
        client->subscribe(QMqttTopicFilter("LED2"), 0);
        client->subscribe(QMqttTopicFilter("LED3"), 0);
        client->subscribe(QMqttTopicFilter("LED4"), 0);

        client->subscribe(QMqttTopicFilter("DHT11"), 0);
        client->subscribe(QMqttTopicFilter("LIGHT"), 0);
        // client->subscribe(QMqttTopicFilter("CO2"), 0);
    });

    // connect(client, SIGNAL(messageReceived(QMqttMessage msg)), this, SLOT(MqttRecv(QMqttMessage message)));
    connect(client, &QMqttClient::messageReceived, this, &Widget::MqttRecv);
    // connect(client, SIGNAL(messageReceived(QMqttMessage msg)), this, SLOT(MqttRecv(QMqttMessage message)));
}

void Widget::MqttRecv(const QByteArray &message, const QMqttTopicName &topic)
{
    QString payload = QString::fromUtf8(message); // 负载消息
    qDebug() << "recv: " << topic << ":" << payload;

    // 处理订阅的消息
    if(topic.name() == "LED1") {
        m_ledui->setLiving();
    } else if(topic.name() == "LED2") {
        m_ledui->setkitchen();
    } else if(topic.name() == "LED3") {
        m_ledui->setbedroom();
    } else if(topic.name() == "LED4") {
        m_ledui->setbathe();
    } else if(topic.name() == "DHT11") {
        QStringList DHT11_data = payload.split(',');
        m_temphumtiyui->temphum->setData(DHT11_data[0].toDouble(), DHT11_data[1].toDouble());
    } else if(topic.name() == "LIGHT") {
        QStringList light_data = payload.split(',');
        m_lightui->setEndAngle(light_data[0].toInt());
        m_lightui->setEndCo2(light_data[1].toInt());
    }
}
