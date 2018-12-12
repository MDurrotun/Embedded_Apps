#ifndef HOMELAYOUT_H
#define HOMELAYOUT_H
#pragma once

#include <QDialog>
#include "Notifications/NotificationLayout.h"
#include "QAbstractButton"

namespace Ui {
class homeLayout;
}

class homeLayout : public QDialog
{
    Q_OBJECT

public:
    explicit homeLayout(QWidget *parent = 0);
    ~homeLayout();
    void animation(QAbstractButton *PushButton);

private slots:

    void on_PushButtonHistory_clicked();
    void on_PushButtonFeedback_clicked();
    void fadeOut();
    void on_PushButtonAbout_clicked();
    void on_PushButtonLevel_clicked();
    void on_PushButtonMaps_clicked();
    void on_PushButtonHome_clicked();
    void playSound();
    void playVideo();
    void on_PushButtonReboot_clicked();

private:
    Ui::homeLayout *ui;
    NotificationLayout notificationLayout;

};

#endif // HOMELAYOUT_H
