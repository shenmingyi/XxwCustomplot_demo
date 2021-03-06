﻿#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plot = new XxwCustomPlot(ui->label);
    plot->showTracer(true);

    QVector<double> x,y;
    for(int i = 0;i<5;i++)
    {
        x<<i;
        y<<i;
    }

    plot->xAxis->setLabelColor(Qt::white);
    plot->yAxis->setLabelColor(Qt::white);



    plot->addGraph();

    plot->graph(0)->setData(x,y);
    plot->graph(0)->setPen(QPen(Qt::yellow,1));

    QCPScatterStyle sty;
    sty.setBrush(QBrush(Qt::green));
    sty.setShape(QCPScatterStyle::ssDisc);
    sty.setSize(10);
    sty.setPen(QPen(Qt::green));


    plot->graph(0)->setScatterStyle(
                sty);


    plot->xAxis->grid()->setPen(QPen(Qt::white));
    plot->yAxis->grid()->setPen(QPen(Qt::white));


    plot->xAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setTickLabelColor(Qt::white);

    plot->xAxis->setBasePen(QPen(Qt::white,1));
    plot->yAxis->setBasePen(QPen(Qt::white,1));

    plot->xAxis->setTickPen(QPen(Qt::white,1));
    plot->yAxis->setTickPen(QPen(Qt::white,1));

    plot->xAxis->setSubTickPen(QPen(Qt::white,1));
    plot->yAxis->setSubTickPen(QPen(Qt::white,1));


    QLinearGradient plotG;

    plotG.setStart(0,0);
    plotG.setFinalStop(0,350);
    plotG.setColorAt(0,QColor(80,80,80));
    plotG.setColorAt(1,QColor(30,30,30));

    plot->setBackground(plotG);

    plot->legend->setVisible(true);


    plot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                      QCP::iSelectLegend | QCP::iSelectPlottables);

    plot->legend->setSelectableParts(QCPLegend::spItems);



    plot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    plot->resize(650,480);
}
