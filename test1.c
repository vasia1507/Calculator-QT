#include<gtk/gtk.h>

int main(int argc, char *argv[]) {
  gtk_init();
  gboolean done = FALSE;

  GtkWidget *window, *button;
  window = gtk_window_new();
  button = gtk_button_new_with_label("Click me");

  gtk_container_add(GTK_CONTAINER(window), button);

  gtk_widget_show(window);

  while (!done) {
    g_main_context_iteration(NULL, TRUE);
  }

  return 0;
}
