#include <QApplication>
#include "callerMainWindow.h"
#include "./ui_caller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);

    window.lineEdit = caller.lineEdit;
    window.lineEdit_2 = caller.lineEdit_2;
    window.lineEdit_3 = caller.lineEdit_3;

    window.resize(480,640);
    window.show();
    return QApplication::exec();
}
