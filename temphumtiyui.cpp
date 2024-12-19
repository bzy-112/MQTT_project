#include "temphumtiyui.h"
#include "ui_temphumtiyui.h"

TEMPHUMTIYUI::TEMPHUMTIYUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TEMPHUMTIYUI)
{
    ui->setupUi(this);
}

TEMPHUMTIYUI::~TEMPHUMTIYUI()
{
    delete ui;
}
