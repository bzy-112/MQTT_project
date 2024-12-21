#ifndef LEDUI_H
#define LEDUI_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>

namespace Ui {
    class LEDUI;
}

class LEDUI : public QWidget
{
    Q_OBJECT

public:
    explicit LEDUI(QWidget *parent = nullptr);
    ~LEDUI();

private slots:
    void on_btn_living_clicked();

    void on_btn_kitchen_clicked();

    void on_btn_bedroom_clicked();

    void on_btn_bathe_clicked();

    void on_hs_living_sliderReleased();

    void on_hs_kitchen_sliderReleased();

    void on_hs_bedroom_sliderReleased();

    void on_hs_bathe_sliderReleased();

private:
    Ui::LEDUI* ui;

private:
    // 设置并且每个按键的初始状态
    bool living_state = false;
    bool kitchen_state = false;
    bool bedroom_state = false;
    bool bathe_state = false;

public:
    // 接口函数
    void setLiving();
    void setkitchen();
    void setbedroom();
    void setbathe();
private:
    // 切换按键状态
    void set_btn_state(QPushButton* btn, bool &state);
    // 设置全部按键
    void set_btn_all();
    // 按键按下设置滑块的状态
    void set_hs_state(QSlider* hs, bool &state);
};

#endif // LEDUI_H
