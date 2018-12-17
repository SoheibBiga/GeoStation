#ifndef MAINWINDOWGHANIA_H
#define MAINWINDOWGHANIA_H

#include <QMainWindow>

namespace Ui {
class MainWindowGhania;
}

class MainWindowGhania : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowGhania(QWidget *parent = 0);
    ~MainWindowGhania();

private:
    Ui::MainWindowGhania *ui;
};

#endif // MAINWINDOWGHANIA_H
