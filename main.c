#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct {
  GtkWidget *widget;
  char* text;
} data;

static void script_add_text_to_label(GtkWidget *button, gpointer my_tmp);
static void change_label(GtkWidget *button, GtkWidget *widget);
static void activate(GtkApplication *app, gpointer user_data);

static void script_add_text_to_label(GtkWidget *button, gpointer my_tmp) {
  data* tmp = (data*)(my_tmp);
  char* str = (char*)gtk_label_get_text(GTK_LABEL(tmp->widget));
  char* buff = calloc(strlen(str) + strlen(tmp->text) + 1, sizeof(char));
  strcat(buff, str);
  strcat(buff, tmp->text);
  gtk_label_set_text(GTK_LABEL(tmp->widget), buff);
  printf("%s\n%s\n", tmp->text, buff);
}

static void change_label(GtkWidget *button, GtkWidget *widget) {
  gtk_label_set_text(GTK_LABEL(widget), "Привет");
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "SmartCalc_v1.0");

  gtk_window_fullscreen(GTK_WINDOW(window));

  gtk_window_set_default_size (GTK_WINDOW (window), 1920, 1080);

  grid = gtk_grid_new();
  gtk_window_set_child(GTK_WINDOW(window), grid);
  /*
  button = gtk_button_new_with_label("Button 1");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 2);
  */

  // Первая строка
  GtkWidget *label = gtk_label_new("Hello world !");
  gtk_widget_set_size_request(label, 120 * 7, 120);
  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 7, 1);

  // Вторая строка
  GtkWidget *button_AC = gtk_button_new_with_label("AC");
  gtk_widget_set_size_request(button_AC, 120, 120);
  g_signal_connect(button_AC, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_AC, 0, 1, 1, 1);

  GtkWidget *button_plus_minus = gtk_button_new_with_label("+/-");
  gtk_widget_set_size_request(button_plus_minus, 120, 120);
  g_signal_connect(button_plus_minus, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_plus_minus, 1, 1, 1, 1);

  button = gtk_button_new_with_label("<-");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);

  button = gtk_button_new_with_label("/");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 1, 1, 1);

  button = gtk_button_new_with_label("(");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 1, 1, 1);

  button = gtk_button_new_with_label(")");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 1, 1, 1);

  button = gtk_button_new_with_label("X");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 1, 1, 1);

  // Третья строка
  button = gtk_button_new_with_label("7");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

  button = gtk_button_new_with_label("8");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

  button = gtk_button_new_with_label("9");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

  button = gtk_button_new_with_label("*");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 2, 1, 1);

  button = gtk_button_new_with_label("^");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 2, 1, 1);

  button = gtk_button_new_with_label("mod");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 2, 1, 1);

  button = gtk_button_new_with_label("log");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 2, 1, 1);

  // Четвертая строка
  button = gtk_button_new_with_label("4");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

  button = gtk_button_new_with_label("5");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);

  button = gtk_button_new_with_label("6");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 3, 1, 1);

  button = gtk_button_new_with_label("-");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);

  button = gtk_button_new_with_label("cos");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 3, 1, 1);

  button = gtk_button_new_with_label("sin");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 3, 1, 1);

  button = gtk_button_new_with_label("tan");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 3, 1, 1);

  // Пятая строка
  GtkWidget* button_1 = gtk_button_new_with_label("1");
  gtk_widget_set_size_request(button_1, 120, 120);
  data* tmp_1 = g_new(data, 1);
  tmp_1->widget = label;
  tmp_1->text = "1";
  g_signal_connect(button_1, "clicked", G_CALLBACK(script_add_text_to_label), tmp_1);
  gtk_grid_attach(GTK_GRID(grid), button_1, 0, 4, 1, 1);

  GtkWidget* button_2 = gtk_button_new_with_label("2");
  gtk_widget_set_size_request(button_2, 120, 120);
  data* tmp_2 = g_new(data, 1);
  tmp_2->widget = label;
  tmp_2->text = "2";
  g_signal_connect(button_2, "clicked", G_CALLBACK(script_add_text_to_label), tmp_2);
  gtk_grid_attach(GTK_GRID(grid), button_2, 1, 4, 1, 1);

  button = gtk_button_new_with_label("3");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);

  button = gtk_button_new_with_label("+");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 4, 1, 1);

  button = gtk_button_new_with_label("acos");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 4, 1, 1);

  button = gtk_button_new_with_label("asin");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 4, 1, 1);

  button = gtk_button_new_with_label("atan");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 4, 1, 1);

  // Шестая строка
  button = gtk_button_new_with_label("0");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 2, 1);

  button = gtk_button_new_with_label(".");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 5, 1, 1);

  button = gtk_button_new_with_label("=");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 3, 5, 1, 1);

  button = gtk_button_new_with_label("sqrt");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 4, 5, 1, 1);

  button = gtk_button_new_with_label("ln");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 5, 5, 1, 1);

  button = gtk_button_new_with_label("x");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 5, 1, 1);

  gtk_widget_show(window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
