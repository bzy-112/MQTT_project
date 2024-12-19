#include "lightui.h"
// #include "ui_lightui.h"
#include <QPainter>
#include <QFont>
#include <QProgressBar>
#include <QRect>
#include <QPalette>
#include <QPushButton>
//水平布局管理器
#include <QHBoxLayout>

LIGHTUI::LIGHTUI(QWidget *parent)
    : QWidget(parent), Light_Intensity(0),
      Carbom_Intensity(0), m_startAngle(90), m_endAngle(0)
{
    // ui->setupUi(this);
    /*背景图设置*/
    // QPixmap pixmap(":/backgruond.gif");
    // QPalette palette;
    // palette.setBrush(backgroundRole(), QBrush(pixmap));
    // setPalette(palette);
    // setAutoFillBackground(true);

    QPushButton* button = new QPushButton(this);
    button->setText("点我");
    connect(button, SIGNAL(clicked()), this, SLOT(clicked()));

    QPushButton* button1 = new QPushButton(this);
    button1->setText("傻逼");
    connect(button, SIGNAL(clicked()), this, SLOT(clicked1()));
    QHBoxLayout* hlayout = new QHBoxLayout(this);
    hlayout->addWidget(button);
    hlayout->addWidget(button1);

    animation = new QPropertyAnimation(this, "endAngle");
    animation->setDuration(500);
    animation->setStartValue(0); // 属性的起始值

    carbom = new QPropertyAnimation(this, "end");
    carbom->setDuration(500);
    carbom->setStartValue(0); // 属性的起始值

    setFixedSize(1024, 600);

    // 启动动画
    // animation->start();
}

void LIGHTUI::DrawText(QPainter& painter)
{
    painter.save();

    painter.translate(width() / 4, height() / 2);

    QRect rect2(-(height() / 6), -(height() / 6), (height() / 3), (height() / 3));
    QRect rect1(-(height() / 6), -(height() / 6), (height() / 3), (height() / 6));

    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);

    QFont font1("微软雅黑", 25);
    painter.setFont(font1);
    painter.drawText(rect1, Qt::AlignCenter, "光照强度");

    QFont font2("微软雅黑", 30);
    painter.setFont(font2);

    painter.drawText(rect2, Qt::AlignCenter, QString::number(m_light, 'g', 3) + "%");

    painter.translate(width() / 2, 0);

    painter.setFont(font1);
    painter.drawText(rect1, Qt::AlignCenter, "Co2浓度");
    painter.setFont(font2);
    painter.drawText(rect2, Qt::AlignCenter, QString::number(m_CO2, 'g', 3) + "%");

    painter.restore();
}

/*进度条颜色设置(根据百分比设置成不同的颜色)*/
void LIGHTUI::ProgressBarColorSet(QPainter& painter, float& num)
{
    QPen pen;
    pen.setWidth(20);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::RoundCap);

    num = (float)m_endAngle / 360 * 100;

    if(num <= 25)
    {
        pen.setColor(Qt::green);
    }
    else if(num > 25 && num <= 50)
    {
        pen.setColor(Qt::blue);
    }
    else if(num > 50 && num <= 75)
    {
        pen.setColor(Qt::yellow);
    }
    else
    {
        pen.setColor(Qt::red);
    }

    // if(Carbom_Intensity <= 25)
    // {
    // pen.setColor(Qt::green);
    // }
    // else if(Carbom_Intensity > 25 && Carbom_Intensity <= 50)
    // {
    // pen.setColor(Qt::blue);
    // }
    // else if(Carbom_Intensity > 50 && Carbom_Intensity <= 75)
    // {
    // pen.setColor(Qt::yellow);
    // }
    // else
    // {
    // pen.setColor(Qt::red);
    // }

    painter.setPen(pen);
}

void LIGHTUI::DrawCirque(QPainter& painter)
{
    painter.save();

    painter.translate(width() / 4, height() / 2);

    QPen pen;
    pen.setWidth(20);//设置笔的大小
    /*设置圆弧连接处为圆形*/
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::RoundCap);
    pen.setColor(Qt::gray);

    painter.setPen(pen);

    QRect rect(-(height() / 4), -(height() / 4), (height() / 2), (height() / 2));

    painter.drawArc(rect, 0, 360 * 16);/*外部圆弧*/

    ProgressBarColorSet(painter, Light_Intensity); //设置进度条颜色
    painter.drawArc(rect, m_startAngle * 16, -m_endAngle * 16);/*内部进度条*/

    painter.translate(width() / 2, 0);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    painter.drawArc(rect, 0, 360 * 16);/*外部圆弧*/

    ProgressBarColorSet(painter, Carbom_Intensity); //设置进度条颜色
    painter.drawArc(rect, m_startAngle * 16, -m_endAngle * 16);/*内部进度条*/

    painter.restore();
}

void LIGHTUI::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置抗锯齿

    DrawCirque(painter);//绘制圆环进度条

    DrawText(painter);//绘制文字
}

void LIGHTUI::clicked()
{
    animation->setStartValue(m_light); // 属性的起始值
    animation->setEndValue(m_light + 36); // 属性的结束值
    setEndAngle(m_light + 36);

    // 启动动画
    animation->start();
}

void LIGHTUI::clicked1()
{
    carbom->setStartValue(m_CO2); // 属性的起始值
    carbom->setEndValue(m_CO2 + 36); // 属性的结束值
    setCo2(m_CO2 + 36);

    // 启动动画
    carbom->start();
}

float LIGHTUI::GetLight_Intensity()
{
    return Light_Intensity;
}

float LIGHTUI::GetCarbom_Intensity()
{
    // 获取二氧化碳浓度

}

LIGHTUI::~LIGHTUI()
{
    // delete ui;
}
