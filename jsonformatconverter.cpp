#include "jsonformatconverter.h"
#include "ui_jsonformatconverter.h"
#include <QFileDialog>
#include <QJsonDocument>

JSONFormatConverter::JSONFormatConverter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JSONFormatConverter)
{
    ui->setupUi(this);
}

JSONFormatConverter::~JSONFormatConverter()
{
    delete ui;
}

QString setjson(QString filename, bool indentify) {
    QFile f(filename);
    if (!f.exists()) {
        return "ERROR: File does not exist.";
    }
    QJsonParseError jError;
    f.open(QIODevice::ReadOnly);
    QJsonDocument j = QJsonDocument::fromJson(f.readAll(), &jError);
    f.close();
    if (j.isNull()) {
        f.close();
        return "ERROR: "+jError.errorString();
    }
    f.open(QIODevice::WriteOnly|QIODevice::Truncate);
    if (indentify) {
        f.write(j.toJson(QJsonDocument::Indented));
        f.close();
        return "JSON rewritten as: Indented.";
    }
    f.write(j.toJson(QJsonDocument::Compact));
    f.close();
    return "JSON rewritten as: Compact.";
}

void JSONFormatConverter::on_fileButton_clicked()
{
    ui->filename->setText(QFileDialog::getOpenFileName(this, tr("Open JSON file"), QDir::homePath(), tr("JSON Files (*.json)")));
    ui->statusBar->showMessage("File selected.");
}

void JSONFormatConverter::on_indentedButton_clicked()
{
    ui->statusBar->showMessage(setjson(ui->filename->text(), true));
}

void JSONFormatConverter::on_compactButton_clicked()
{
    ui->statusBar->showMessage(setjson(ui->filename->text(), false));
}
