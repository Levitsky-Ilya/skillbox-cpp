//
// Created by leviz on 20.02.2022.
//

#ifndef CALCULATOR_CALLERMAINWINDOW_H
#define CALCULATOR_CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

class CallerMainWindow : public QMainWindow {
    Q_OBJECT

public:
    QLineEdit* lineEdit = nullptr;
    QLineEdit* lineEdit_2 = nullptr;
    QLineEdit* lineEdit_3 = nullptr;

    CallerMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}

private:
    bool getArgs(double& a, double& b) {
        bool flagA = true, flagB = true;
        if (lineEdit_2->text().isEmpty()) {
            a = 0.0;
        } else {
            a = lineEdit_2->text().toDouble(&flagA);
        }

        if (lineEdit_3->text().isEmpty()) {
            b = 0.0;
        } else {
            b = lineEdit_3->text().toDouble(&flagB);
        }

        return flagA & flagB;
    }

public slots:
    void calcAdd() {
        double a, b;
        lineEdit->setText(getArgs(a, b) ? QString::number(a + b) : "ERROR!" );
    };
    void calcSub() {
        double a, b;
        lineEdit->setText(getArgs(a, b) ? QString::number(a - b) : "ERROR!");
    };
    void calcMul() {
        double a, b;
        lineEdit->setText(getArgs(a, b) ? QString::number(a * b) : "ERROR!");
    };
    void calcDiv() {
        double a, b;
        lineEdit->setText(
                !getArgs(a, b) ? "ERROR!" :
                (b == 0) ? "ERROR!" :
                QString::number(a / b));
    };
};

#endif //CALCULATOR_CALLERMAINWINDOW_H
