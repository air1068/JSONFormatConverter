#ifndef JSONFORMATCONVERTER_H
#define JSONFORMATCONVERTER_H

#include <QMainWindow>

namespace Ui {
class JSONFormatConverter;
}

class JSONFormatConverter : public QMainWindow
{
    Q_OBJECT

public:
    explicit JSONFormatConverter(QWidget *parent = 0);
    ~JSONFormatConverter();

private slots:
    void on_fileButton_clicked();

    void on_indentedButton_clicked();

    void on_compactButton_clicked();

private:
    Ui::JSONFormatConverter *ui;
};

#endif // JSONFORMATCONVERTER_H
