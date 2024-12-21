#ifndef TEMPHUM_H
#define TEMPHUM_H

#include <QWidget>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QTimer>
#include <QSplineSeries>

namespace Ui {
    class TempHum;
}

class TempHum : public QWidget
{
    Q_OBJECT

    QLineSeries* temp_series;
    QLineSeries* hum_series;
    QDateTimeAxis* ax;
    QVector<QPointF> temperatureData;
    QTimer* timer;

    void TempChart();
    void HumChart();

public:
    explicit TempHum(QWidget *parent = nullptr);
    ~TempHum();

private:
    Ui::TempHum* ui;

public:
    void setData(float tempnum, int humnum);
};

#endif // TEMPHUM_H
