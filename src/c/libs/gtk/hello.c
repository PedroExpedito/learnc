 #include <gtk/gtk.h>

 //Uma novidade que vem do c..
 //Os comentarios podem ser escritos com // ou  /*  */

 /* Esta é uma função callback. Os argumentos de dados são ignorados
  * neste exemplo. Mais sobre callbacks abaixo. */
 static void hello( GtkWidget *widget,
                    gpointer   data )
 {
     g_print ("Hello World\n");
 }

 static gboolean delete_event( GtkWidget *widget,
                               GdkEvent  *event,
                               gpointer   data )
 {
     /* Se você retornar FALSE no tratador do sinal "delete_event",
      * o GTK emitirá o sinal "destroy". Retornar TRUE significa
      * que você não quer que a janela seja destruída.
      * Isso é útil para exibir diálogos do tipo 'tem certeza de
      * que deseja sair?'. */

     g_print ("evento 'delete' ocorreu\n");

     /* Mude TRUE para FALSE e a janela principal será destruída com um
      * "delete_event". */

     return TRUE;
 }

 /* Outro callback */
 static void destroy( GtkWidget *widget,
                      gpointer   data )
 {
     gtk_main_quit ();
 }

 int main( int   argc,
           char *argv[] )
 {
     /* GtkWidget é o tipo de dado para os widgets */
     GtkWidget *window;
     GtkWidget *button;

     /* Esta função é chamada em todas as aplicações GTK. Argumentos da linha
      * de comando são interpretados e retornados à aplicação. */
     gtk_init (&argc, &argv);

     /* criar uma nova janela */
     window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

     /* Quando a janela recebe o sinal "delete_event" (dado pelo gerenciador
      * de janelas, geralmente pela opção "fechar", ou na barra de título),
      * nós pedimos que ela chame a função delete_event () como definido
      * acima. Os dado passado para a função callback é NULL e é ignorado. */
     g_signal_connect (G_OBJECT (window), "delete_event",
 		      G_CALLBACK (delete_event), NULL);

     /* Aqui conectamos o evento "destroy" a um tratador de sinal. Esse
      * evento ocorre quando chamamos gtk_widget_destroy() na janela, ou
      * se retornamos FALSE no callback "delete_event". */
     g_signal_connect (G_OBJECT (window), "destroy",
 		      G_CALLBACK (destroy), NULL);

     /* Ajusta a largura da borda da janela. */
     gtk_container_set_border_width (GTK_CONTAINER (window), 10);

     //Coloca um nome na janela
     gtk_window_set_title (GTK_WINDOW (window), "Aqui o nome da Janela");

     /* Cria um novo botão com o texto "Hello World". */
     button = gtk_button_new_with_label ("Hello World");

     /* Quando o botão recebe o sinal "clicked", chamará a função hello()
      * passando NULL como argumento. hello() é definida acima. */
     g_signal_connect (G_OBJECT (button), "clicked",
 		      G_CALLBACK (hello), NULL);

     /* Isso fará com que a janela será destruída pela chamada
      * gtk_widget_destroy(window) quando o botão for clicado ("clicked").
      * Novamente, o sinal destroy poderia vir daqui ou do gerenciador
      * de janelas. */
     g_signal_connect_swapped (G_OBJECT (button), "clicked",
 			      G_CALLBACK (gtk_widget_destroy),
                               G_OBJECT (window));

     /* Isto empacota o botão na janela (um recipiente gtk). */
     gtk_container_add (GTK_CONTAINER (window), button);

     /* O passo final é exibir o widget recém-criado. */
     gtk_widget_show (button);

     /* e a janela */
     gtk_widget_show (window);

     /* Toda aplicação GTK deve ter uma chamada gtk_main(). O controle
      * termina aqui e espera por um evento (como um apertamento de tecla
      * ou evento do mouse). */
     gtk_main ();

     return 0;
 }
