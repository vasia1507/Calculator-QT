#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
  g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 1920, 1080);

  grid = gtk_grid_new();
  gtk_window_set_child(GTK_WINDOW(window), grid);
  /*
  button = gtk_button_new_with_label("Button 1");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 2);
  */
  GtkWidget *label = gtk_label_new("Hello, World!");
  gtk_widget_set_size_request(label, 910, 180);
  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 6, 1);
  int row = 0, col = 0;
  for (row = 1; row < 6; row++) {
    for (col = 0; col < 7; col++) {
      if (row == 5 && col == 0) {
        GtkWidget *button = gtk_button_new_with_label("Button");
        gtk_widget_set_size_request(button, 260, 180);
        gtk_grid_attach(GTK_GRID(grid), button, col, row, 2, 1);
        col++;
      } else {
        GtkWidget *button = gtk_button_new_with_label("Button");
        gtk_widget_set_size_request(button, 130, 180);
        gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
      }
    }
  }

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
