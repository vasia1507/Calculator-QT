#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 private slots:
  void on_pushButton_AC_clicked();
  void on_pushButton_upBracket_clicked();
  void on_pushButton_downBracket_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_sin_clicked();
  void on_pushButton_percent_clicked();
  void on_pushButton_1_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_divide_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_cos_clicked();
  void on_pushButton_power_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_multiply_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();
  void on_pushButton_minus_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_0_clicked();
  void on_pushButton_dot_clicked();
  void on_pushButton_plus_clicked();
  void on_pushButton_Backspace_clicked();

  void on_pushButton_equal_clicked();

  void on_pushButton_Graph_clicked();

  private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
