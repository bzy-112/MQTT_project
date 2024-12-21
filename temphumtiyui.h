#ifndef TEMPHUMTIYUI_H
#define TEMPHUMTIYUI_H

#include <QWidget>
#include "TempHum.h"

namespace Ui {
    class TEMPHUMTIYUI;
}

class TEMPHUMTIYUI : public QWidget
{
    Q_OBJECT

public:
    explicit TEMPHUMTIYUI(QWidget *parent = nullptr);
    ~TEMPHUMTIYUI();

    void LineChart();
    void PieChart();
    void BarChart();
    TempHum* temphum;

private:
    Ui::TEMPHUMTIYUI* ui;
};

#endif // TEMPHUMTIYUI_H
