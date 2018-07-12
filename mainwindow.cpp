#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::MakePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakePlot()
{
    // generate some data:
    QVector<double> x(101), y(101), yTwo(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
     // y[i] = qSin(2*M_PI*x[i]); // plot a sin function
     //y[i] = qExp(-x[i]); //plot exponential
      y[i] = qExp(-x[i])*qSin(2*M_PI*x[i]);
      yTwo[i] = qExp(-x[i]);
    }
    // create graph and assign data to it:
    ui->CustomPlot->addGraph();//add a graph
    ui->CustomPlot->graph(0)->setData(x, y);
    ui->CustomPlot->addGraph();
    ui->CustomPlot->graph(1)->setData(x,yTwo);
    // give the axes some labels:
    ui->CustomPlot->xAxis->setLabel("x");
    ui->CustomPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->CustomPlot->xAxis->setRange(-1, 1);
    ui->CustomPlot->yAxis->setRange(-10, 10);
    ui->CustomPlot->replot();
}
