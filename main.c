#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  GtkWidget* widget;
  char* text;
} data;

static void script_add_text_to_label(GtkWidget* button, gpointer my_tmp);
static void change_label(GtkWidget* button, GtkWidget* widget);
static void activate(GtkApplication* app, gpointer user_data);

static void script_add_text_to_label(GtkWidget* button, gpointer my_tmp) {
  data* tmp = (data*)(my_tmp);
  char* str = (char*)gtk_label_get_text(GTK_LABEL(tmp->widget));
  char* buff = calloc(strlen(str) + strlen(tmp->text) + 1, sizeof(char));
  strcat(buff, str);
  strcat(buff, tmp->text);
  gtk_label_set_text(GTK_LABEL(tmp->widget), buff);
  printf("%s\n%s\n", tmp->text, buff);
}

static void change_label(GtkWidget* button, GtkWidget* widget) {
  gtk_label_set_text(GTK_LABEL(widget), "Expression : ");
}

static void activate(GtkApplication* app, gpointer user_data) {
  GtkWidget* window;
  GtkWidget* grid;
  GtkWidget* button;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "SmartCalc_v1.0");
  //  gtk_window_fullscreen(GTK_WINDOW(window));
  gtk_window_set_default_size(GTK_WINDOW(window), 840, 720);

  grid = gtk_grid_new();
  gtk_window_set_child(GTK_WINDOW(window), grid);

  // Первая строка
  GtkWidget* label = gtk_label_new("Expression : ");
  gtk_widget_set_size_request(label, 120 * 7, 60);
  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 7, 1);

  GtkWidget* label_answer = gtk_label_new("Answer : ");
  gtk_widget_set_size_request(label_answer, 120 * 7, 60);
  gtk_grid_attach(GTK_GRID(grid), label_answer, 0, 1, 7, 1);

  // Вторая строка
  GtkWidget* button_AC = gtk_button_new_with_label("AC");
  gtk_widget_set_size_request(button_AC, 120, 120);
  g_signal_connect(button_AC, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_AC, 0, 2, 1, 1);

  GtkWidget* button_plus_minus = gtk_button_new_with_label("+/-");
  gtk_widget_set_size_request(button_plus_minus, 120, 120);
  g_signal_connect(button_plus_minus, "clicked", G_CALLBACK(change_label),
                   label);
  gtk_grid_attach(GTK_GRID(grid), button_plus_minus, 1, 2, 1, 1);

  button = gtk_button_new_with_label("<-");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

  button = gtk_button_new_with_label("/");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 2, 1, 1);

  button = gtk_button_new_with_label("(");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 2, 1, 1);

  button = gtk_button_new_with_label(")");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 2, 1, 1);

  button = gtk_button_new_with_label("X");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 2, 1, 1);

  // Третья строка
  button = gtk_button_new_with_label("7");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

  button = gtk_button_new_with_label("8");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);

  button = gtk_button_new_with_label("9");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 3, 1, 1);

  button = gtk_button_new_with_label("*");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);

  button = gtk_button_new_with_label("^");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 3, 1, 1);

  button = gtk_button_new_with_label("mod");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 3, 1, 1);

  button = gtk_button_new_with_label("log");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 3, 1, 1);

  // Четвертая строка
  button = gtk_button_new_with_label("4");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);

  button = gtk_button_new_with_label("5");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);

  button = gtk_button_new_with_label("6");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);

  button = gtk_button_new_with_label("-");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 4, 1, 1);

  button = gtk_button_new_with_label("cos");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 4, 1, 1);

  button = gtk_button_new_with_label("sin");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 4, 1, 1);

  button = gtk_button_new_with_label("tan");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 4, 1, 1);

  // Пятая строка
  GtkWidget* button_1 = gtk_button_new_with_label("1");
  gtk_widget_set_size_request(button_1, 120, 120);
  data* tmp_1 = g_new(data, 1);
  tmp_1->widget = label;
  tmp_1->text = "1";
  g_signal_connect(button_1, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_1);
  gtk_grid_attach(GTK_GRID(grid), button_1, 0, 5, 1, 1);

  GtkWidget* button_2 = gtk_button_new_with_label("2");
  gtk_widget_set_size_request(button_2, 120, 120);
  data* tmp_2 = g_new(data, 1);
  tmp_2->widget = label;
  tmp_2->text = "2";
  g_signal_connect(button_2, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_2);
  gtk_grid_attach(GTK_GRID(grid), button_2, 1, 5, 1, 1);

  GtkWidget* button_3 = gtk_button_new_with_label("3");
  gtk_widget_set_size_request(button_3, 120, 120);
  data* tmp_3 = g_new(data, 1);
  tmp_3->widget = label;
  tmp_3->text = "3";
  g_signal_connect(button_3, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_3);
  gtk_grid_attach(GTK_GRID(grid), button_3, 2, 5, 1, 1);

  GtkWidget* button_plus = gtk_button_new_with_label("+");
  gtk_widget_set_size_request(button_plus, 120, 120);
  data* tmp_plus = g_new(data, 1);
  tmp_plus->widget = label;
  tmp_plus->text = "+";
  g_signal_connect(button_plus, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_plus);
  gtk_grid_attach(GTK_GRID(grid), button_plus, 3, 5, 1, 1);

  GtkWidget* button_acos = gtk_button_new_with_label("acos");
  gtk_widget_set_size_request(button_acos, 120, 120);
  g_signal_connect(button_acos, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_acos, 4, 5, 1, 1);

  GtkWidget* button_asin = gtk_button_new_with_label("asin");
  gtk_widget_set_size_request(button_asin, 120, 120);
  g_signal_connect(button_asin, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_asin, 5, 5, 1, 1);

  GtkWidget* button_atan = gtk_button_new_with_label("atan");
  gtk_widget_set_size_request(button_atan, 120, 120);
  g_signal_connect(button_atan, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_atan, 6, 5, 1, 1);

  // Шестая строка
  GtkWidget* button_zero = gtk_button_new_with_label("0");
  gtk_widget_set_size_request(button_zero, 120, 120);
  g_signal_connect(button_zero, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_zero, 0, 6, 2, 1);

  GtkWidget* button_dot = gtk_button_new_with_label(".");
  gtk_widget_set_size_request(button_dot, 120, 120);
  g_signal_connect(button_dot, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_dot, 2, 6, 1, 1);

  GtkWidget* button_equal = gtk_button_new_with_label("=");
  gtk_widget_set_size_request(button_equal, 120, 120);
  g_signal_connect(button_equal, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_equal, 3, 6, 1, 1);

  GtkWidget* button_sqrt = gtk_button_new_with_label("sqrt");
  gtk_widget_set_size_request(button_sqrt, 120, 120);
  g_signal_connect(button_sqrt, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_sqrt, 4, 6, 1, 1);

  GtkWidget* button_ln = gtk_button_new_with_label("ln");
  gtk_widget_set_size_request(button_ln, 120, 120);
  g_signal_connect(button_ln, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_ln, 5, 6, 1, 1);

  GtkWidget* button_iks = gtk_button_new_with_label("x");
  gtk_widget_set_size_request(button_iks, 120, 120);
  g_signal_connect(button_iks, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_iks, 6, 6, 1, 1);

  gtk_widget_show(window);
}

int main(int argc, char** argv) {
  GtkApplication* app;
  int status;

  app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
