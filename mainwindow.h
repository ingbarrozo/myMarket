#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void testMessage();

public slots:
    void focusChanged(QWidget* old, QWidget* now);

private:
    void inventorySection();
    void salesSection();
    void reportSection();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
