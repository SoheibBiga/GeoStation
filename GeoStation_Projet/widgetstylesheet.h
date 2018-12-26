#ifndef WIDGETSTYLESHEET_H
#define WIDGETSTYLESHEET_H

#include <QWidget>
#include <QTableView>
#include <QTimer>

class WidgetStyleSheet : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetStyleSheet(QWidget *parent = nullptr);

signals:

public slots:
    void InitQwidgets();
};

#endif // WIDGETSTYLESHEET_H
