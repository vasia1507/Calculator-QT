#include <gtk/gtk.h>

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
  button = gtk_button_new_with_label("AC");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

  button = gtk_button_new_with_label("+/-");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

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
  button = gtk_button_new_with_label("1");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);

  button = gtk_button_new_with_label("2");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);

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
