#include "temphumtiyui.h"
#include "ui_temphumtiyui.h"
// Qchar

#include <QtCharts>

TEMPHUMTIYUI::TEMPHUMTIYUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TEMPHUMTIYUI)
{
    ui->setupUi(this);
    setWindowTitle("Template and Hum");
    setFixedSize(1024, 600);

    temphum = new TempHum(this);
    temphum->show();
    temphum->setFixedSize(this->width(), this->height());

}

TEMPHUMTIYUI::~TEMPHUMTIYUI()
{
    delete ui;
}

void TEMPHUMTIYUI::LineChart()
{

}

void TEMPHUMTIYUI::PieChart()
{
    QChart *chart = new QChart();

    chart->setTitle("降雨量");

    //ui->graphicsView_2->setRenderHint(QPainter::Antialiasing, true);
    //ui->graphicsView_2->setChart(chart);

    QPieSeries *pieser = new QPieSeries();
    pieser->append("50ml :20%", 20);
    pieser->append("150ml :25%", 25);
    pieser->append("80ml :10%", 10);
    pieser->append("100ml :30%", 30);
    pieser->append("280ml :15%", 15);
    pieser->setLabelsVisible(true);

    QPieSlice *sred = pieser->slices().at(0);
    QPieSlice *sgreen = pieser->slices().at(1);
    QPieSlice *sblue = pieser->slices().at(2);
    QPieSlice *sblack = pieser->slices().at(3);
    QPieSlice *swhithe = pieser->slices().at(4);

    sred->setColor(QColor(255, 0, 0, 255));
    sgreen->setColor(QColor(0, 255, 0, 255));
    sblue->setColor(QColor(0, 0, 255, 255));
    sblack->setColor(QColor(0, 0, 0, 255));
    swhithe->setColor(QColor(255, 255, 0, 255));

    chart->addSeries(pieser);

}

void TEMPHUMTIYUI::BarChart()
{
    QChart *chart = new QChart();

    chart->setTitle("高考成绩");

    //ui->graphicsView_3->setRenderHint(QPainter::Antialiasing, true);
    //ui->graphicsView_3->setChart(chart);

    QBarSet *ba = new QBarSet("bar");

    *ba << 560 << 710 << 599 << 688 << 701;

    QStackedBarSeries *Barser = new QStackedBarSeries();
    Barser->append(ba);

    QStringList strlist = {"小王", "小李", "小吴", "小张", "小赵"};

    // 通过QBarCategoryAxis类将类型添加到图表的轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(strlist);
    axisX->setTitleText("考生姓名");
    chart->addAxis(axisX, Qt::AlignBottom);

    // 通过QBarCategoryAxis类将类型添加到图表的轴
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 750);
    axisY->setTitleText("高考总分阶梯");
    chart->addAxis(axisY, Qt::AlignLeft);

    Barser->attachAxis(axisX);
    Barser->attachAxis(axisY);

    chart->addSeries(Barser);
    // 图例
    chart->legend()->setVisible(false); // 设置绘图区与图表边界
    chart->legend()->setAlignment(Qt::AlignBottom);
}
