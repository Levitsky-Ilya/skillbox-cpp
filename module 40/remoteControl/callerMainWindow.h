//
// Created by leviz on 09.03.2022.
//

#ifndef REMOTECONTROL_CALLERMAINWINDOW_H
#define REMOTECONTROL_CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CallerMainWindow : public QMainWindow {
Q_OBJECT

public:
    QLineEdit* channelDisplay = nullptr;
    QLineEdit* volumeDisplay = nullptr;

    CallerMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}

    void updateChannelDisplay() { channelDisplay->setText("Channel " + QString::number(m_channel)); };
    void updateVolumeDisplay() { volumeDisplay->setText("Volume " + QString::number(m_volume) + "%"); };

public slots:
    void select0()      { m_channel = 0; updateChannelDisplay(); };
    void select1()      { m_channel = 1; updateChannelDisplay(); };
    void select2()      { m_channel = 2; updateChannelDisplay(); };
    void select3()      { m_channel = 3; updateChannelDisplay(); };
    void select4()      { m_channel = 4; updateChannelDisplay(); };
    void select5()      { m_channel = 5; updateChannelDisplay(); };
    void select6()      { m_channel = 6; updateChannelDisplay(); };
    void select7()      { m_channel = 7; updateChannelDisplay(); };
    void select8()      { m_channel = 8; updateChannelDisplay(); };
    void select9()      { m_channel = 9; updateChannelDisplay(); };
    void channelUp()    { m_channel = (m_channel >= 9) ? 0 : m_channel + 1; updateChannelDisplay(); };
    void channelDown()  { m_channel = (m_channel <= 0) ? 9 : m_channel - 1; updateChannelDisplay(); };
    void volumeUp()     { m_volume  = (m_volume >= 100) ? 100 : m_volume + 10; updateVolumeDisplay(); };
    void volumeDown()   { m_volume  = (m_volume <= 0) ? 0 : m_volume - 10; updateVolumeDisplay(); };

private:
    int m_channel = 0;
    int m_volume = 50;
};



#endif //REMOTECONTROL_CALLERMAINWINDOW_H
