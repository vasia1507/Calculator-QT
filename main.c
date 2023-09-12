#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  GtkWidget* widget;
  char* text;
} data;

static void draw(GtkDrawingArea* area, cairo_t* cr, int width, int height,
                 gpointer data);
static void script_add_text_to_label(GtkWidget* button, gpointer my_tmp);
static void change_label(GtkWidget* button, GtkWidget* widget);
static void activate(GtkApplication* app, gpointer user_data);

static void script_equal(GtkWidget* expression, GtkWidget* answer) {
  char* str = (char*)gtk_label_get_text(GTK_LABEL(expression));
  char* tmp = calculate(str);
  strcat();
}

static void draw(GtkDrawingArea* area, cairo_t* cr, int width, int height,
                 gpointer data) {
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, 1.0);
  // Начало линии
  cairo_move_to(cr, 10, 10);
  // Конец линии
  cairo_line_to(cr, 190, 190);
  // Рисование линии
  cairo_stroke(cr);
}

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

  button = gtk_button_new_with_label("+/-");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

  button = gtk_button_new_with_label("<-");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

  GtkWidget* button_div = gtk_button_new_with_label("/");
  gtk_widget_set_size_request(button_div, 120, 120);
  data* tmp_div = g_new(data, 1);
  tmp_div->widget = label;
  tmp_div->text = "/";
  g_signal_connect(button_div, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_div);
  gtk_grid_attach(GTK_GRID(grid), button_div, 3, 2, 1, 1);

  GtkWidget* button_open_bracket = gtk_button_new_with_label("(");
  gtk_widget_set_size_request(button_open_bracket, 120, 120);
  data* tmp_open_bracket = g_new(data, 1);
  tmp_open_bracket->widget = label;
  tmp_open_bracket->text = "(";
  g_signal_connect(button_open_bracket, "clicked",
                   G_CALLBACK(script_add_text_to_label), tmp_open_bracket);
  gtk_grid_attach(GTK_GRID(grid), button_open_bracket, 4, 2, 1, 1);

  GtkWidget* button_close_bracket = gtk_button_new_with_label(")");
  gtk_widget_set_size_request(button_close_bracket, 120, 120);
  data* tmp_close_bracket = g_new(data, 1);
  tmp_close_bracket->widget = label;
  tmp_close_bracket->text = ")";
  g_signal_connect(button_close_bracket, "clicked",
                   G_CALLBACK(script_add_text_to_label), tmp_close_bracket);
  gtk_grid_attach(GTK_GRID(grid), button_close_bracket, 5, 2, 1, 1);

  button = gtk_button_new_with_label("X");
  gtk_widget_set_size_request(button, 120, 120);
  g_signal_connect(button, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button, 6, 2, 1, 1);

  // Третья строка
  GtkWidget* button_seven = gtk_button_new_with_label("7");
  gtk_widget_set_size_request(button_seven, 120, 120);
  data* tmp_seven = g_new(data, 1);
  tmp_seven->widget = label;
  tmp_seven->text = "7";
  g_signal_connect(button_seven, "clicked",
                   G_CALLBACK(script_add_text_to_label), tmp_seven);
  gtk_grid_attach(GTK_GRID(grid), button_seven, 0, 3, 1, 1);

  GtkWidget* button_eight = gtk_button_new_with_label("8");
  gtk_widget_set_size_request(button_eight, 120, 120);
  data* tmp_eight = g_new(data, 1);
  tmp_eight->widget = label;
  tmp_eight->text = "8";
  g_signal_connect(button_eight, "clicked",
                   G_CALLBACK(script_add_text_to_label), tmp_eight);
  gtk_grid_attach(GTK_GRID(grid), button_eight, 1, 3, 1, 1);

  GtkWidget* button_nine = gtk_button_new_with_label("9");
  gtk_widget_set_size_request(button_nine, 120, 120);
  data* tmp_nine = g_new(data, 1);
  tmp_nine->widget = label;
  tmp_nine->text = "9";
  g_signal_connect(button_nine, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_nine);
  gtk_grid_attach(GTK_GRID(grid), button_nine, 2, 3, 1, 1);

  GtkWidget* button_mul = gtk_button_new_with_label("*");
  gtk_widget_set_size_request(button_mul, 120, 120);
  data* tmp_mul = g_new(data, 1);
  tmp_mul->widget = label;
  tmp_mul->text = "*";
  g_signal_connect(button_mul, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_mul);
  gtk_grid_attach(GTK_GRID(grid), button_mul, 3, 3, 1, 1);

  GtkWidget* button_pow = gtk_button_new_with_label("^");
  gtk_widget_set_size_request(button_pow, 120, 120);
  data* tmp_pow = g_new(data, 1);
  tmp_pow->widget = label;
  tmp_pow->text = "^";
  g_signal_connect(button_pow, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_pow);
  gtk_grid_attach(GTK_GRID(grid), button_pow, 4, 3, 1, 1);

  GtkWidget* button_mod = gtk_button_new_with_label("mod");
  gtk_widget_set_size_request(button_mod, 120, 120);
  data* tmp_mod = g_new(data, 1);
  tmp_mod->widget = label;
  tmp_mod->text = "mod(";
  g_signal_connect(button_mod, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_mod);
  gtk_grid_attach(GTK_GRID(grid), button_mod, 5, 3, 1, 1);

  GtkWidget* button_iks = gtk_button_new_with_label("x");
  gtk_widget_set_size_request(button_iks, 120, 120);
  data* tmp_iks = g_new(data, 1);
  tmp_iks->widget = label;
  tmp_iks->text = "x";
  g_signal_connect(button_iks, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_iks);
  gtk_grid_attach(GTK_GRID(grid), button_iks, 6, 3, 1, 1);

  // Четвертая строка
  GtkWidget* button_four = gtk_button_new_with_label("4");
  gtk_widget_set_size_request(button_four, 120, 120);
  data* tmp_four = g_new(data, 1);
  tmp_four->widget = label;
  tmp_four->text = "4";
  g_signal_connect(button_four, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_four);
  gtk_grid_attach(GTK_GRID(grid), button_four, 0, 4, 1, 1);

  GtkWidget* button_five = gtk_button_new_with_label("5");
  gtk_widget_set_size_request(button_five, 120, 120);
  data* tmp_five = g_new(data, 1);
  tmp_five->widget = label;
  tmp_five->text = "5";
  g_signal_connect(button_five, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_five);
  gtk_grid_attach(GTK_GRID(grid), button_five, 1, 4, 1, 1);

  GtkWidget* button_six = gtk_button_new_with_label("6");
  gtk_widget_set_size_request(button_six, 120, 120);
  data* tmp_six = g_new(data, 1);
  tmp_six->widget = label;
  tmp_six->text = "6";
  g_signal_connect(button_six, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_six);
  gtk_grid_attach(GTK_GRID(grid), button_six, 2, 4, 1, 1);

  GtkWidget* button_minus = gtk_button_new_with_label("-");
  gtk_widget_set_size_request(button_minus, 120, 120);
  data* tmp_minus = g_new(data, 1);
  tmp_minus->widget = label;
  tmp_minus->text = "-";
  g_signal_connect(button_minus, "clicked",
                   G_CALLBACK(script_add_text_to_label), tmp_minus);
  gtk_grid_attach(GTK_GRID(grid), button_minus, 3, 4, 1, 1);

  GtkWidget* button_cos = gtk_button_new_with_label("cos");
  gtk_widget_set_size_request(button_cos, 120, 120);
  data* tmp_cos = g_new(data, 1);
  tmp_cos->widget = label;
  tmp_cos->text = "cos(";
  g_signal_connect(button_cos, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_cos);
  gtk_grid_attach(GTK_GRID(grid), button_cos, 4, 4, 1, 1);

  GtkWidget* button_sin = gtk_button_new_with_label("sin");
  gtk_widget_set_size_request(button_sin, 120, 120);
  data* tmp_sin = g_new(data, 1);
  tmp_sin->widget = label;
  tmp_sin->text = "sin(";
  g_signal_connect(button_sin, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_sin);
  gtk_grid_attach(GTK_GRID(grid), button_sin, 5, 4, 1, 1);

  GtkWidget* button_tan = gtk_button_new_with_label("tan");
  gtk_widget_set_size_request(button_tan, 120, 120);
  data* tmp_tan = g_new(data, 1);
  tmp_tan->widget = label;
  tmp_tan->text = "tan(";
  g_signal_connect(button_tan, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_tan);
  gtk_grid_attach(GTK_GRID(grid), button_tan, 6, 4, 1, 1);

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
  data* tmp_acos = g_new(data, 1);
  tmp_acos->widget = label;
  tmp_acos->text = "acos(";
  g_signal_connect(button_acos, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_acos);
  gtk_grid_attach(GTK_GRID(grid), button_acos, 4, 5, 1, 1);

  GtkWidget* button_asin = gtk_button_new_with_label("asin");
  gtk_widget_set_size_request(button_asin, 120, 120);
  data* tmp_asin = g_new(data, 1);
  tmp_asin->widget = label;
  tmp_asin->text = "asin(";
  g_signal_connect(button_asin, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_asin);
  gtk_grid_attach(GTK_GRID(grid), button_asin, 5, 5, 1, 1);

  GtkWidget* button_atan = gtk_button_new_with_label("atan");
  gtk_widget_set_size_request(button_atan, 120, 120);
  data* tmp_atan = g_new(data, 1);
  tmp_atan->widget = label;
  tmp_atan->text = "atan(";
  g_signal_connect(button_atan, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_atan);
  gtk_grid_attach(GTK_GRID(grid), button_atan, 6, 5, 1, 1);

  // Шестая строка
  GtkWidget* button_zero = gtk_button_new_with_label("0");
  gtk_widget_set_size_request(button_zero, 120, 120);
  data* tmp_zero = g_new(data, 1);
  tmp_zero->widget = label;
  tmp_zero->text = "0";
  g_signal_connect(button_zero, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_zero);
  gtk_grid_attach(GTK_GRID(grid), button_zero, 0, 6, 2, 1);

  GtkWidget* button_dot = gtk_button_new_with_label(".");
  gtk_widget_set_size_request(button_dot, 120, 120);
  data* tmp_dot = g_new(data, 1);
  tmp_dot->widget = label;
  tmp_dot->text = ".";
  g_signal_connect(button_dot, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_dot);
  gtk_grid_attach(GTK_GRID(grid), button_dot, 2, 6, 1, 1);

  GtkWidget* button_equal = gtk_button_new_with_label("=");
  gtk_widget_set_size_request(button_equal, 120, 120);
  g_signal_connect(button_equal, "clicked", G_CALLBACK(change_label), label);
  gtk_grid_attach(GTK_GRID(grid), button_equal, 3, 6, 1, 1);

  GtkWidget* button_sqrt = gtk_button_new_with_label("sqrt");
  gtk_widget_set_size_request(button_sqrt, 120, 120);
  data* tmp_sqrt = g_new(data, 1);
  tmp_sqrt->widget = label;
  tmp_sqrt->text = "sqrt(";
  g_signal_connect(button_sqrt, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_sqrt);
  gtk_grid_attach(GTK_GRID(grid), button_sqrt, 4, 6, 1, 1);

  GtkWidget* button_ln = gtk_button_new_with_label("ln");
  gtk_widget_set_size_request(button_ln, 120, 120);
  data* tmp_ln = g_new(data, 1);
  tmp_ln->widget = label;
  tmp_ln->text = "ln(";
  g_signal_connect(button_ln, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_ln);
  gtk_grid_attach(GTK_GRID(grid), button_ln, 5, 6, 1, 1);

  GtkWidget* button_log = gtk_button_new_with_label("log");
  gtk_widget_set_size_request(button_log, 120, 120);
  data* tmp_log = g_new(data, 1);
  tmp_log->widget = label;
  tmp_log->text = "log(";
  g_signal_connect(button_log, "clicked", G_CALLBACK(script_add_text_to_label),
                   tmp_log);
  gtk_grid_attach(GTK_GRID(grid), button_log, 6, 6, 1, 1);

  /*
    GtkWidget* window2;
    GtkWidget* drawing_area;
    window2 = gtk_application_window_new(app);
    drawing_area = gtk_drawing_area_new();
    gtk_window_set_title(GTK_WINDOW(window2), "test");
    gtk_window_set_default_size(GTK_WINDOW(window2), 200, 200);
    gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(drawing_area), 200);
    gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(drawing_area), 200);
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), draw, NULL,
                                   NULL);
    g_signal_connect(drawing_area, "draw", G_CALLBACK(draw), NULL);
    gtk_window_set_child(GTK_WINDOW(window2), drawing_area);
    gtk_widget_show(window2);
  */

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
