#include "camreui.h"
#include "ui_camreui.h"

CAMREUI::CAMREUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CAMREUI)
{
    ui->setupUi(this);

    //初始化按键

    //初始化摄像头
    m_camera = new QCamera(QMediaDevices::defaultVideoInput());
    connect(m_camera, &QCamera::errorOccurred, [this]() {
        qDebug() << "camera error occurred" << this->m_camera->errorString();
    });

    //初始化摄像头会话管理
    m_captureSession = new QMediaCaptureSession(this);

    m_captureSession->setCamera(m_camera);
    m_captureSession->setVideoOutput(ui->widget);

    m_camera->start();
}

CAMREUI::~CAMREUI()
{
    delete ui;
}
