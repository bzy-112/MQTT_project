#ifndef TEMPHUMTIYUI_H
#define TEMPHUMTIYUI_H

#include <QWidget>

namespace Ui {
class TEMPHUMTIYUI;
}

class TEMPHUMTIYUI : public QWidget
{
    Q_OBJECT

public:
    explicit TEMPHUMTIYUI(QWidget *parent = nullptr);
    ~TEMPHUMTIYUI();

private:
    Ui::TEMPHUMTIYUI *ui;
};

#endif // TEMPHUMTIYUI_H