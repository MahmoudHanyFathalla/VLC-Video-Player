#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <vlc/vlc.h>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a Qt frame to hold the VLC video output
    videoFrame = new QFrame(this);
    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    layout->addWidget(videoFrame);

    // Create a line edit for entering the video path
    QLineEdit *videoPathLineEdit = new QLineEdit(this);
    videoPathLineEdit->setPlaceholderText("Enter video path...");
    layout->addWidget(videoPathLineEdit);

    // Create a button to load the video
    QPushButton *loadVideoButton = new QPushButton("Load Video", this);
    layout->addWidget(loadVideoButton);

    // Connect the button click to load the video
    connect(loadVideoButton, &QPushButton::clicked, [this, videoPathLineEdit]() {
        // Load the video from the entered path
        const char *videoPath = videoPathLineEdit->text().toStdString().c_str();
        libvlc_media_t *vlcMedia = libvlc_media_new_path(vlcInstance, videoPath);
        libvlc_media_player_set_media(vlcMediaPlayer, vlcMedia);

        // Play the video
        libvlc_media_player_play(vlcMediaPlayer);
    });

    // Initialize libVLC
    vlcInstance = libvlc_new(0, nullptr);
    vlcMediaPlayer = libvlc_media_player_new(vlcInstance);

    // Set up the VLC widget
    void *videoWidget = (void *)videoFrame->winId();
    libvlc_media_player_set_hwnd(vlcMediaPlayer, videoWidget);
}

MainWindow::~MainWindow()
{
    // Release libVLC resources
    libvlc_media_player_stop(vlcMediaPlayer);
    libvlc_media_player_release(vlcMediaPlayer);
    libvlc_release(vlcInstance);

    delete ui;
}
