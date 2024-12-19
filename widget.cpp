#include "widget.h"
//垂直布局管理器
#include <QVBoxLayout>
//水平布局管理器
#include <QHBoxLayout>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建窗口
    QVBoxLayout* vlayout = new QVBoxLayout();
    LEDButton = new QPushButton();
    TempHumtiyButton = new QPushButton();
    LightButton = new QPushButton();
    Camre = new QPushButton();

    //把按键全部放入垂直布局管理器
    vlayout->addWidget(LEDButton);
    vlayout->addWidget(TempHumtiyButton);
    vlayout->addWidget(LightButton);
    vlayout->addWidget(Camre);

    //创建栈式布局管理器 把创建的窗口添加进栈式布局管理器
    m_stacklayout = new QStackedLayout();
    m_ledui = new LEDUI();
    m_camreui = new CAMREUI();
    m_lightui = new LIGHTUI();
    m_temphumtiyui = new TEMPHUMTIYUI();
    m_stacklayout->addWidget(m_ledui);
    m_stacklayout->addWidget(m_temphumtiyui);
    m_stacklayout->addWidget(m_lightui);
    m_stacklayout->addWidget(m_camreui);

    //创建垂直布局管理器  将栈式布局管理器和垂直布局管理器添加进
    QHBoxLayout* hlayout = new QHBoxLayout(this);
    hlayout->addLayout(vlayout);
    hlayout->addLayout(m_stacklayout);

    //将按键与栈式布局管理器链接 配置按键信息
    setButton();

    //设置窗口的背景图片大小 以及设置分割线
    setBackgroundWindow();

}

Widget::~Widget() {}

void Widget::on_m_ledui_clicked()
{
    m_stacklayout->setCurrentWidget(m_ledui);
}

void Widget::on_m_camreui_clicked()
{
    m_stacklayout->setCurrentWidget(m_camreui);
}

void Widget::on_m_lightui_clicked()
{
    m_stacklayout->setCurrentWidget(m_lightui);
}

void Widget::on_m_temphumtiyui_clicked()
{
    m_stacklayout->setCurrentWidget(m_temphumtiyui);
}

void Widget::setButton()
{
    //设置按键文本
    LEDButton->setText("灯光");
    TempHumtiyButton->setText("温湿度");
    LightButton->setText("光照");
    Camre->setText("监控");

    // LEDButton
    // TempHumtiyButton
    // LightButton
    // Camre
    // 按键长度为150 宽50
    LEDButton->setFixedSize(150, 50);
    TempHumtiyButton->setFixedSize(150, 50);
    LightButton->setFixedSize(150, 50);
    Camre->setFixedSize(150, 50);

    // //设置默认选择按键
    // LEDButton->setAutoDefault(true);
    // TempHumtiyButton->setAutoDefault(true);
    // LightButton->setAutoDefault(true);
    // Camre->setAutoDefault(true);

    //设置按键为圆角
    // LEDButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

    connect(LEDButton, SIGNAL(clicked()), this, SLOT(on_m_ledui_clicked()));
    connect(TempHumtiyButton, SIGNAL(clicked()), this, SLOT(on_m_temphumtiyui_clicked()));
    connect(LightButton, SIGNAL(clicked()), this, SLOT(on_m_lightui_clicked()));
    connect(Camre, SIGNAL(clicked()), this, SLOT(on_m_camreui_clicked()));
}

void Widget::setBackgroundWindow()
{
    //给窗口添加背景图
    QPixmap Images(":/icon/picture.png");
    QPalette Palette = this->palette();
    Palette.setBrush(QPalette::Window, Images);
    this->setPalette(Palette);

    //创建一个线将窗口和操作区分隔开
    // QPainter painter(this);
    // QLine line(LEDButton->pos().x() + 150, LEDButton->pos().y() - 20, Camre->pos().x() + 150, Camre->pos().y() + 40);
    // painter.setBackground(QBrush(QColor(0, 0, 0)));
    // painter.drawLine(line);

}

QSize Widget::sizeHint() const
{
    //通过重写父类函数 设置主窗口的大小默认为背景图片的大小
    return QSize(1814, 1080);
}
