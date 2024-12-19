#ifndef LIGHTUI_H
#define LIGHTUI_H

#include <QWidget>
#include <QPaintEvent>
#include <QPen>
#include <QPropertyAnimation>
#include <QDebug>

namespace Ui {
    class LIGHTUI;
}

class LIGHTUI : public QWidget
{
    Q_OBJECT
    /*定义一个可读(READ)并且可写(WRITE)的属性，并且可以通过属性名称进行访问*/
    Q_PROPERTY(int endAngle READ endAngle WRITE setEndAngle NOTIFY endAngleChanged)

    float Light_Intensity;//光照强度
    float Carbom_Intensity;//二氧化碳浓度
    int m_startAngle;
    int m_endAngle;

    int m_light = 0;
    int m_CO2 = 0;

    QPropertyAnimation* animation; // 光照强度
    QPropertyAnimation* carbom; // 二氧化碳浓度

    void DrawCirque(QPainter& painter);
    void DrawText(QPainter& painter);
    void ProgressBarColorSet(QPainter& painter, float& num);

public:
    LIGHTUI(QWidget *parent = nullptr);
    ~LIGHTUI();
    float GetLight_Intensity();//获取光照强度
    float GetCarbom_Intensity();//获取光照强度

    // 外界读取数据函数
    int endAngle() const
    {
        return m_endAngle;
    }

    void setEndAngle(const int& endAngle)
    {
        m_light = endAngle;
        update();
    }

    void setCo2(const int& num) {
        m_CO2 = num;
        update();
    }

protected:
    void paintEvent(QPaintEvent* event);

signals:
    void endAngleChanged(int Angle);

protected slots:
    void clicked();
    void clicked1();

};

#endif // LIGHTUI_H