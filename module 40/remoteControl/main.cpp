#include <QApplication>
#include "callerMainWindow.h"
#include "./ui_caller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.channelDisplay = caller.channelDisplay;
    window.volumeDisplay = caller.volumeDisplay;
    window.updateChannelDisplay();
    window.updateVolumeDisplay();
    window.show();
    return QApplication::exec();
    // Why sizePolicy = Fixed does not work for QMainWindow to stay fixed in size?
    // Only setting maximumSize=MinimumSize helped.
    // Moreover, the arrows showing that window can be resized are still appearing. Though, they have no effect.
}
