#include <gtk/gtk.h>

static void print_hello( GtkWidget *widget, gpointer data){
    g_print("Hello world!\n");
}

int main( int argc, char *argv[] ){
    GtkBuilder *builder;
    GObject *window, *button;

    gtk_init( &argc, &argv );

    builder = gtk_builder_new();
    gtk_builder_add_from_file( builder, "./ui/main.ui", NULL );

    window = gtk_builder_get_object( builder, "sdm_main" );
    g_signal_connect( window, "destroy", G_CALLBACK( gtk_main_quit ), NULL );

    //button = gtk_builder_get_object( builder, "quit" );
    //g_signal_connect( button, "clicked", G_CALLBACK( gtk_main_quit ), NULL );

    gtk_main();

    return 0;
}