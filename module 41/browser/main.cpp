#include <QApplication>
#include <QtGui/QtGui>

#include <QWebEngineView>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *webView = new QWebEngineView;
    webview->setHtml("<H1>Hello Skillbox</H1>");
    return QApplication::exec();
}

#include <main.moc>