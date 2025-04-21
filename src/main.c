#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
    g_print("Hello, World!\n");
}

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *button = gtk_button_new_with_label("Hello World!");

    gtk_window_set_title(GTK_WINDOW(window), "GTK App");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    gtk_widget_set_size_request(button, 100, 50);
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

    gtk_box_append(GTK_BOX(box), button);
    gtk_window_set_child(GTK_WINDOW(window), box);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("com.example.GtkApp", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
