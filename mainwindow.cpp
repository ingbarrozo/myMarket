#include "mainwindow.h"
#include <iostream>
#include <typeinfo>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //resize to maximized screen
    showFullScreen();
    showMaximized();

    QDockWidget* invetoriWidget = inventorySection();
    salesSection(invetoriWidget);
    reportSection();

    //mainWidget
    setCentralWidget(setMainWidget());

    setDockOptions(AllowTabbedDocks);
    setDockOptions(ForceTabbedDocks);
}

MainWindow::~MainWindow()
{
    cout << "MainWindow destroyed." <<endl;
}

QDockWidget *MainWindow::inventorySection()
{
    //QPushButton
    QPushButton *btnOpenReport = new QPushButton("Report");
    connect(btnOpenReport, SIGNAL(clicked()), this, SLOT(testMessage()));

    QFormLayout *layout = new QFormLayout;
    layout->addRow(btnOpenReport);

    //QWidget
    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    QDockWidget *dockWidget = new QDockWidget(tr("Inventario"), this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
    dockWidget->setWidget(widget);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    return dockWidget;
}

void MainWindow::salesSection(QDockWidget *firstWidget)
{
    //TextBox
    QLineEdit *lnNum1 = new QLineEdit;

    //Button
    QPushButton *btnOpenReport = new QPushButton("Report");
    connect(btnOpenReport, SIGNAL(clicked()), this, SLOT(testMessage()));

    //table
    QStandardItemModel *model = new QStandardItemModel(2,3,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(tr("hHeader 1")));
    model->setHorizontalHeaderItem(1,new QStandardItem(tr("hHeader 2")));
    model->setHorizontalHeaderItem(2,new QStandardItem(tr("hHeader 3")));

    for (int y = 0; y < 100; ++y) {
        for (int x = 0; x < 10; ++x) {
            QStandardItem *father = new QStandardItem( tr("nomas"));
            model->setItem(y,x,father);
        }
    }

    QTableView *table = new QTableView;
    table->setModel(model);

    //New Layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lnNum1);
    layout->addWidget(btnOpenReport);
    layout->addWidget(table);

    //New Widget
    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    QDockWidget *dockWidget = new QDockWidget(tr("Venta"), this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
    dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
    dockWidget->setWidget(widget);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    tabifyDockWidget(dockWidget, firstWidget);
    dockWidget->setVisible(true);
    dockWidget->setFocus();
    dockWidget->raise();
}

void MainWindow::reportSection()
{
    //QPushButton
    QPushButton *btnOpenReport = new QPushButton("Report");
    connect(btnOpenReport, SIGNAL(clicked()), this, SLOT(testMessage()));

    QFormLayout *layout = new QFormLayout;
    layout->addRow(btnOpenReport);

    //QWidget
    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    QDockWidget *dockWidget = new QDockWidget(tr("Report"), this);
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    dockWidget->setWidget(widget);
    addDockWidget(Qt::TopDockWidgetArea, dockWidget);
}

QWidget *MainWindow::setMainWidget()
{
    //TextBox
    QLineEdit *lnNum1 = new QLineEdit;

    //Button
    QPushButton *btnOpenReport = new QPushButton("Report");
    connect(btnOpenReport, SIGNAL(clicked()), this, SLOT(testMessage()));

    //table
    QStandardItemModel *model = new QStandardItemModel(2,3,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(tr("hHeader 1")));
    model->setHorizontalHeaderItem(1,new QStandardItem(tr("hHeader 2")));
    model->setHorizontalHeaderItem(2,new QStandardItem(tr("hHeader 3")));

    for (int y = 0; y < 100; ++y) {
        for (int x = 0; x < 10; ++x) {
            QStandardItem *father = new QStandardItem( tr("nomas"));
            model->setItem(y,x,father);
        }
    }

    QTableView *table = new QTableView;
    table->setModel(model);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    //New Layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lnNum1);
    layout->addWidget(btnOpenReport);
    layout->addWidget(table);

    //New Widget
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    return widget;
}

void MainWindow::testMessage()
{
    QMessageBox::about(this, tr("Report"), tr("Calling report section."));
}

void MainWindow::focusChanged(QWidget* old, QWidget* now)
{
//    QWidget *wid = QApplication::focusWidget();
//    QDockWidget *dock = 0;

//    dock = qobject_cast<QDockWidget*>(now);
//    if (!dock)
//    {
//        cout << "noup" <<endl;
//        QWidget *widget2 = qobject_cast<QWidget *>(now->parent());
//        string s = typeid(widget2).name();
//        cout << s <<endl;
//    }
}
