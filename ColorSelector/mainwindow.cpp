#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->redSlider->setRange(0, 255);
    ui->greenSlider->setRange(0, 255);
    ui->blueSlider->setRange(0, 255);

    ui->redSlider->setValue(0);
    ui->greenSlider->setValue(0);
    ui->blueSlider->setValue(0);

    ui->redDial->setRange(0, 255);
    ui->greenDial->setRange(0, 255);
    ui->blueDial->setRange(0, 255);

    ui->redDial->setValue(0);
    ui->greenDial->setValue(0);
    ui->blueDial->setValue(0);

    ui->redEdit->setText("0");
    ui->greenEdit->setText("0");
    ui->blueEdit->setText("0");

    QRegExpValidator* numValidater = new QRegExpValidator(QRegExp("\\d*"));
    ui->redEdit->setValidator(numValidater);
    ui->greenEdit->setValidator(numValidater);
    ui->blueEdit->setValidator(numValidater);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->colorView->setScene(scene);
    colorRectangle = scene->addRect(0, 0, ui->colorView->width(), ui->colorView->height(), QPen(Qt::black), QBrush(Qt::black));
    colorRectangle->update();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updatePreview() {
    colorRectangle->setBrush(QBrush(QColor(ui->redSlider->value(),
                                           ui->greenSlider->value(),
                                           ui->blueSlider->value())));
    colorRectangle->update();
}

void MainWindow::updateValues(QLineEdit* edit, QSlider* slider) {
    int value = edit->text().toInt();
    if (value > 255) {
        edit->setText("255");
        value = 255;
    } else if (value < 0) {
        edit->setText("0");
        value = 0;
    }

    slider->setValue(value);
}

void MainWindow::editUpdate() {
    updateValues(ui->redEdit, ui->redSlider);
    updateValues(ui->greenEdit, ui->greenSlider);
    updateValues(ui->blueEdit, ui->blueSlider);
    updatePreview();
}

void MainWindow::sliderUpdate() {
    ui->redEdit->setText(QString::number(ui->redSlider->value()));
    ui->greenEdit->setText(QString::number(ui->greenSlider->value()));
    ui->blueEdit->setText(QString::number(ui->blueSlider->value()));
    updatePreview();
}

void MainWindow::buttonClicked() {

}

