#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vlc/vlc.h>
#include <QFrame>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct libvlc_instance_t;
struct libvlc_media_player_t;

class QFrame;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    libvlc_instance_t *vlcInstance;
    libvlc_media_player_t *vlcMediaPlayer;
    QFrame *videoFrame;
};

#endif // MAINWINDOW_H
