#include "ledui.h"
#include "ui_ledui.h"

LEDUI::LEDUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LEDUI)
{
    ui->setupUi(this);
    set_btn_all();
}

LEDUI::~LEDUI()
{
    delete ui;
}

void LEDUI::set_btn_state(QPushButton *btn, bool &state)
{
    if(state) {
        QPixmap pixmap(":/icon/lightOff.png");
        QIcon icon(pixmap.scaled(QSize(127, 150), Qt::KeepAspectRatio));
        btn->setIcon(icon);
        btn->setIconSize(QSize(127, 150));
        state = !state;
    } else {
        QPixmap pixmap(":/icon/lightOn.png");
        QIcon icon(pixmap.scaled(QSize(127, 150), Qt::KeepAspectRatio));
        btn->setIcon(icon);
        btn->setIconSize(QSize(127, 150));
        state = !state;
    }
}

void LEDUI::set_btn_all()
{
    //将按键背景设置为透明
    ui->btn_living->setStyleSheet("QPushButton { background: transparent; border: none; }");
    ui->btn_kitchen->setStyleSheet("QPushButton { background: transparent; border: none; }");
    ui->btn_bedroom->setStyleSheet("QPushButton { background: transparent; border: none; }");
    ui->btn_bathe->setStyleSheet("QPushButton { background: transparent; border: none; }");

    QPixmap pixmap(":/icon/lightOff.png");
    QIcon icon(pixmap.scaled(QSize(127, 150), Qt::KeepAspectRatio));

    ui->btn_living->setIcon(icon);
    ui->btn_living->setIconSize(QSize(127, 150));

    ui->btn_bathe->setIcon(icon);
    ui->btn_bathe->setIconSize(QSize(127, 150));

    ui->btn_bedroom->setIcon(icon);
    ui->btn_bedroom->setIconSize(QSize(127, 150));

    ui->btn_kitchen->setIcon(icon);
    ui->btn_kitchen->setIconSize(QSize(127, 150));
}

void LEDUI::set_hs_state(QSlider *hs, bool &state)
{
    if(state) {
        hs->setValue(100);
    }
    else {
        hs->setValue(0);
    }
}

void LEDUI::on_btn_living_clicked()
{
    set_btn_state(ui->btn_living, living_state);
    set_hs_state(ui->hs_living, living_state);
}

void LEDUI::on_btn_kitchen_clicked()
{
    set_btn_state(ui->btn_kitchen, kitchen_state);
    set_hs_state(ui->hs_kitchen, kitchen_state);
}

void LEDUI::on_btn_bedroom_clicked()
{
    set_btn_state(ui->btn_bedroom, bedroom_state);
    set_hs_state(ui->hs_bedroom, bedroom_state);
}

void LEDUI::on_btn_bathe_clicked()
{
    set_btn_state(ui->btn_bathe, bathe_state);
    set_hs_state(ui->hs_bathe, bathe_state);
}

void LEDUI::on_hs_living_sliderReleased()
{
    if(!living_state && ui->hs_living->value() == 100) {
        set_btn_state(ui->btn_living, living_state);
    }
    else if(living_state && ui->hs_living->value() == 0) {
        set_btn_state(ui->btn_living, living_state);
    } else if(!living_state && ui->hs_living->value() != 0) {
        set_btn_state(ui->btn_living, living_state);
    }
}

void LEDUI::on_hs_kitchen_sliderReleased()
{
    if(!kitchen_state && ui->hs_kitchen->value() == 100) {
        set_btn_state(ui->btn_kitchen, kitchen_state);
    }
    else if(kitchen_state && ui->hs_kitchen->value() == 0) {
        set_btn_state(ui->btn_kitchen, kitchen_state);
    } else if(!kitchen_state && ui->hs_kitchen->value() != 0) {
        set_btn_state(ui->btn_kitchen, kitchen_state);
    }
}

void LEDUI::on_hs_bedroom_sliderReleased()
{
    if(!bedroom_state && ui->hs_bedroom->value() == 100) {
        set_btn_state(ui->btn_bedroom, bedroom_state);
    }
    else if(bedroom_state && ui->hs_bedroom->value() == 0) {
        set_btn_state(ui->btn_bedroom, bedroom_state);
    } else if(!bedroom_state && ui->hs_bedroom->value() != 0) {
        set_btn_state(ui->btn_bedroom, bedroom_state);
    }
}

void LEDUI::on_hs_bathe_sliderReleased()
{
    if(!bathe_state && ui->hs_bathe->value() == 100) {
        set_btn_state(ui->btn_bathe, bathe_state);
    }
    else if(bathe_state && ui->hs_bathe->value() == 0) {
        set_btn_state(ui->btn_bathe, bathe_state);
    } else if(!bathe_state && ui->hs_bathe->value() != 0) {
        set_btn_state(ui->btn_bathe, bathe_state);
    }
}

void LEDUI::setLiving()
{

    set_btn_state(ui->btn_living, living_state);
    set_hs_state(ui->hs_living, living_state);

    /*   QPixmap pixmap(":/icon/lightOn.png");
    QIcon icon(pixmap.scaled(QSize(127, 150), Qt::KeepAspectRatio));
    ui->btn_living->setIcon(icon);
    ui->btn_living->setIconSize(QSize(127, 150));
    // state = !state;    */
}

void LEDUI::setkitchen()
{
    set_btn_state(ui->btn_kitchen, kitchen_state);
    set_hs_state(ui->hs_kitchen, kitchen_state);
}

void LEDUI::setbedroom()
{
    set_btn_state(ui->btn_bedroom, bedroom_state);
    set_hs_state(ui->hs_bedroom, bedroom_state);
}

void LEDUI::setbathe()
{
    set_btn_state(ui->btn_bathe, bathe_state);
    set_hs_state(ui->hs_bathe, bathe_state);
}
