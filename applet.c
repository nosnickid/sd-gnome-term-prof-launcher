#include <string.h>

#include <panel-applet.h>
#include <gtk/gtklabel.h>

static void
display_about_dialog (BonoboUIComponent *uic, struct MultiRes *applet) {
}

static const char Context_menu_xml [] =
   "<popup name=\"button3\">\n"
   "   <menuitem name=\"Properties Item\" "
   "         verb=\"ExampleProperties\" "
   "           _label=\"_Preferences...\"\n"
   "          pixtype=\"stock\" "
   "          pixname=\"gtk-properties\"/>\n"
   "   <menuitem name=\"About Item\" "
   "             verb=\"ExampleAbout\" "
   "           _label=\"_About...\"\n"
   "          pixtype=\"stock\" "
   "          pixname=\"gnome-stock-about\"/>\n"
   "</popup>\n";

static const BonoboUIVerb myexample_menu_verbs [] = {
//      BONOBO_UI_VERB ("ExampleProperties", display_properties_dialog),
        BONOBO_UI_VERB ("ExampleAbout", display_about_dialog),
        BONOBO_UI_VERB_END
};

static gboolean
myexample_applet_fill (PanelApplet *applet,
   const gchar *iid,
   gpointer data)
{
    GtkWidget *label;

    if (strcmp (iid, "OAFIID:ExampleApplet") != 0)
        return FALSE;

    label = gtk_label_new ("Hello World");
    gtk_container_add (GTK_CONTAINER (applet), label);

    gtk_widget_show_all (GTK_WIDGET (applet));

    panel_applet_setup_menu (PANEL_APPLET (applet), 
        Context_menu_xml, 
        myexample_menu_verbs,
        applet
   );

    return TRUE;
}
PANEL_APPLET_BONOBO_FACTORY ("OAFIID:ExampleApplet_Factory",
                             PANEL_TYPE_APPLET,
                             "The Hello World Applet",
                             "0",
                             myexample_applet_fill,
                             NULL);
