#ifndef CAMREUI_H
#define CAMREUI_H

#include <QWidget>
#include <QCamera>
#include <QVideoWidget>
#include <QMediaCaptureSession>
#include <QMediaDevices>

namespace Ui {
    class CAMREUI;
}

class CAMREUI : public QWidget
{
    Q_OBJECT

    QCamera* m_camera;

    QMediaCaptureSession* m_captureSession;

    QVideoWidget* m_video;

public:
    explicit CAMREUI(QWidget *parent = nullptr);
    ~CAMREUI();

private:
    Ui::CAMREUI* ui;
};

#endif // CAMREUI_H
