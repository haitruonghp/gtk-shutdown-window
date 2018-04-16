#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


GtkWidget       *yes_btn;
GtkWidget       *cancel_btn;

typedef struct _ProgressBar {
	GtkWidget *processbar;
	int timer;
} ProgressBar;

static void end_progress(GtkWidget *widget, ProgressBar *progessdata)
{
	g_source_remove(progessdata->timer);
	progessdata->timer = 0;
	g_free(progessdata);
	gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;


 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "PowerOff.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "PowerOff"));
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two button Yes and Cancel
    yes_btn = GTK_WIDGET(gtk_builder_get_object(builder, "YesBtn"));
    cancel_btn = GTK_WIDGET(gtk_builder_get_object(builder, "CancelBtn"));



    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}


// called when YesBtn is clicked
void on_YesBtn_clicked()
{
    char command_poweroff[50];

    strcpy(command_poweroff, "poweroff");
    system(command_poweroff);
}

// called when CancelBtn is clicked
void on_CancelBtn_clicked()
{
    gtk_main_quit();
}
 
// called when window is closed
void on_PowerOff_destroy()
{
    gtk_main_quit();
}
