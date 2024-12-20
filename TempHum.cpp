#include "TempHum.h"
#include "ui_TempHum.h"
#include <QValueAxis>
#include <QDateTime>
#include <QDebug>

TempHum::TempHum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TempHum)
{
    ui->setupUi(this);

    /*显示温度湿度曲线*/
    TempChart();

    // timer = new QTimer(this);
    // timer->start(1000);
    // connect(timer, SIGNAL(timeout()), this, SLOT(updateTemp()));
    // connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(updateTemp()));

}

void TempHum::TempChart()
{
    QChart * chart = new QChart();

    chart->setTitle("温度(°C)/湿度(%)");/*设置图例标题*/
    ui->Temp->setRenderHint(QPainter::Antialiasing, true);/*抗锯齿*/
    ui->Temp->setChart(chart);

    /*x轴*/
    ax = new QDateTimeAxis();
    ax->setTitleText("times");
    ax->setTickCount(15);
    ax->setLineVisible(true);
    ax->setGridLineVisible(true);
    ax->setFormat("hh:mm:ss");
    ax->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(15));

    /*y轴*/
    QValueAxis *ay = new QValueAxis();
    ay->setTitleText("template/humidity");
    ay->setTickCount(15);
    ay->setLabelFormat("%.1f");//让y轴显示出小数部分
    ay->setRange(0, 100);
    ay->setLineVisible(true);
    ay->setGridLineVisible(true);

    /*温度曲线*/
    temp_series = new QLineSeries();
    temp_series->setName("温度");
    temp_series->setColor(QColor(255, 200, 20));
    /*设置初始值*/
    temp_series->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), 30);

    /*湿度曲线*/
    hum_series = new QLineSeries();
    hum_series->setName("湿度");
    hum_series->setColor(QColor(150, 100, 200));
    /*设置初始值*/
    hum_series->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), 50);

    /*将温度曲线添加进chart*/
    chart->addSeries(temp_series);
    chart->setAxisX(ax, temp_series);
    chart->setAxisY(ay, temp_series);

    /*将湿度曲线添加进chart*/
    chart->addSeries(hum_series);
    chart->setAxisX(ax, hum_series);
    chart->setAxisY(ay, hum_series);

    //chart->legend()->hide();//隐藏图标
}

void TempHum::setData(float tempnum, int humnum)
{
    // 更新温度曲线数据
    qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
    float temperature = tempnum;

    // 更新湿度数据
    int hum = humnum;

    /*显示当前温度和湿度*/
    QString TempHum = QString("当前温度:") + QString::number(temperature, 'f', 1) + "°C"
                      + QString("当前湿度:") + QString::number(hum, 'f', 1) + "%";

    ui->TempHumlbl->setText(TempHum);

    /*添加当前时间点的温度和湿度*/
    if (temp_series != nullptr && hum_series != nullptr)
    {
        temp_series->append(timestamp, temperature);
        hum_series->append(timestamp, hum);
        qDebug() << temp_series->count();

        if (temp_series->count() > 16)
        {
            /*移除第一个点*/
            temp_series->removePoints(0, 1);

            hum_series->removePoints(0, 1);

        }

        qDebug() << temp_series->count();

        // 调整温度曲线的 x 轴范围
        if (temp_series->count() > 15)
        {
            ax->setRange(QDateTime::fromMSecsSinceEpoch(temp_series->at(0).x()),
                         QDateTime::fromMSecsSinceEpoch(temp_series->at(temp_series->count() - 1).x()));
        }
    }
}

TempHum::~TempHum()
{
    delete ui;
}
