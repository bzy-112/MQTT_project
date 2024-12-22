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

}

void TEMPHUMTIYUI::BarChart()
{

}
