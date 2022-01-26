#include <QApplication>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QSlider>
#include <QVBoxLayout>

class ColorfulCircle : public QWidget
{
    Q_OBJECT
public:
    ColorfulCircle(QWidget *parent, QSlider *slider);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;

public slots:
    void setRed();
    void setYellow();
    void setGreen();

private:
    QPixmap mRedCircle;
    QPixmap mYellowCircle;
    QPixmap mGreenCircle;
    QPixmap mCurrentCircle;
};

ColorfulCircle::ColorfulCircle(QWidget *parent, QSlider *slider) {
    setParent(parent);
    QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mRedCircle = QPixmap("../redCircle.png");
    mYellowCircle = QPixmap("../yellowCircle.png");
    mGreenCircle = QPixmap("../greenCircle.png");
    mCurrentCircle = mGreenCircle;
    setGeometry(mCurrentCircle.rect()); // What does it do?
}

void ColorfulCircle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCircle);
}

QSize ColorfulCircle::minimumSizeHint() const
{
    return QSize(100, 100);
}

void ColorfulCircle::setRed() {
    mCurrentCircle = mRedCircle;
    update();
}

void ColorfulCircle::setYellow() {
    mCurrentCircle = mYellowCircle;
    update();
}

void ColorfulCircle::setGreen() {
    mCurrentCircle = mGreenCircle;
    update();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *window = new QWidget;

    auto *slider = new QSlider(Qt::Horizontal);

    auto *circle = new ColorfulCircle(window, slider); // I dont like it
    circle->setFixedSize(100, 100);
    QObject::connect(slider, &QSlider::valueChanged,
                     [circle](int newValue) {
                         if (newValue <= 33) { circle->setGreen(); }
                         else if (newValue <= 66) { circle->setYellow(); }
                         else { circle->setRed(); }
                     });


    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);

    window->setFixedSize(200, 200);
    window->move(1000, 500);
    window->show();

    return QApplication::exec();
}

#include "main.moc"

// Question: what is main.moc? Why we need it?
// Why is it included after the main code and bringing it in front produces compile error?
