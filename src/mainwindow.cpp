#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "datatypes.h"
#include "rpn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_AC_clicked() { ui->label->setText(""); }

void MainWindow::on_pushButton_upBracket_clicked() {
  ui->label->setText(ui->label->text() + "(");
}

void MainWindow::on_pushButton_downBracket_clicked() {
  ui->label->setText(ui->label->text() + ")");
}

void MainWindow::on_pushButton_mod_clicked() {
  ui->label->setText(ui->label->text() + "mod(");
}

void MainWindow::on_pushButton_asin_clicked() {
  ui->label->setText(ui->label->text() + "asin(");
}

void MainWindow::on_pushButton_sin_clicked() {
  ui->label->setText(ui->label->text() + "sin(");
}

void MainWindow::on_pushButton_percent_clicked() {
  ui->label->setText(ui->label->text() + "%");
}

void MainWindow::on_pushButton_1_clicked() {
  ui->label->setText(ui->label->text() + "1");
}

void MainWindow::on_pushButton_2_clicked() {
  ui->label->setText(ui->label->text() + "2");
}

void MainWindow::on_pushButton_3_clicked() {
  ui->label->setText(ui->label->text() + "3");
}

void MainWindow::on_pushButton_divide_clicked() {
  ui->label->setText(ui->label->text() + "/");
}

void MainWindow::on_pushButton_acos_clicked() {
  ui->label->setText(ui->label->text() + "acos(");
}

void MainWindow::on_pushButton_cos_clicked() {
  ui->label->setText(ui->label->text() + "cos(");
}

void MainWindow::on_pushButton_power_clicked() {
  ui->label->setText(ui->label->text() + "^");
}

void MainWindow::on_pushButton_4_clicked() {
  ui->label->setText(ui->label->text() + "4");
}

void MainWindow::on_pushButton_5_clicked() {
  ui->label->setText(ui->label->text() + "5");
}

void MainWindow::on_pushButton_6_clicked() {
  ui->label->setText(ui->label->text() + "6");
}

void MainWindow::on_pushButton_multiply_clicked() {
  ui->label->setText(ui->label->text() + "*");
}

void MainWindow::on_pushButton_atan_clicked() {
  ui->label->setText(ui->label->text() + "atan(");
}

void MainWindow::on_pushButton_tan_clicked() {
  ui->label->setText(ui->label->text() + "tan(");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  ui->label->setText(ui->label->text() + "sqrt(");
}

void MainWindow::on_pushButton_7_clicked() {
  ui->label->setText(ui->label->text() + "7");
}

void MainWindow::on_pushButton_8_clicked() {
  ui->label->setText(ui->label->text() + "8");
}

void MainWindow::on_pushButton_9_clicked() {
  ui->label->setText(ui->label->text() + "9");
}

void MainWindow::on_pushButton_minus_clicked() {
  ui->label->setText(ui->label->text() + "-");
}

void MainWindow::on_pushButton_log_clicked() {
  ui->label->setText(ui->label->text() + "log(");
}

void MainWindow::on_pushButton_ln_clicked() {
  ui->label->setText(ui->label->text() + "ln(");
}

void MainWindow::on_pushButton_x_clicked() {
  ui->label->setText(ui->label->text() + "x");
}

void MainWindow::on_pushButton_0_clicked() {
  ui->label->setText(ui->label->text() + "0");
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->label->setText(ui->label->text() + ".");
}

void MainWindow::on_pushButton_plus_clicked() {
  ui->label->setText(ui->label->text() + "+");
}

void MainWindow::on_pushButton_Backspace_clicked() {
  QString A = ui->label->text();
  A.removeLast();
  ui->label->setText(A);
}

void MainWindow::on_pushButton_equal_clicked() {
  double result = 0;
  QString str1 = ui->label->text();
  QByteArray ba = str1.toLocal8Bit();
  char *str = ba.data();
  if (str != NULL) {
      stack *res = parse(str);
      stack *copy = s_copy(res);
      result = calcExp(copy, 0);
      s_destroy(res);
  }
  ui->label->setText(QString::number(result));
}

void MainWindow::on_pushButton_Graph_clicked() {
  double xBegin = ui->doubleSpinBox->value();
  double xEnd = ui->doubleSpinBox_2->value();
  double yBegin = ui->doubleSpinBox_3->value();
  double yEnd = ui->doubleSpinBox_4->value();

  ui->widgetPlot->xAxis->setRange(xBegin, xEnd);
  ui->widgetPlot->yAxis->setRange(yBegin, yEnd);

  QString str1 = ui->label->text();
  QByteArray ba = str1.toLocal8Bit();
  char *str = ba.data();
  stack *res = parse(str);
  QVector<double> x, y;
  for (double i = xBegin; i <= xEnd; i += (xEnd - xBegin) / 100.) {
    x.push_back(i);
    stack *copy = s_copy(res);
    y.push_back(calcExp(copy, i));
    s_destroy(copy);
  }
  ui->widgetPlot->clearGraphs();
  ui->widgetPlot->addGraph();
  ui->widgetPlot->graph(0)->addData(x, y);
  ui->widgetPlot->replot();
  x.clear();
  y.clear();
  s_destroy(res);
}
