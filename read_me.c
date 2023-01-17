1) checker les erreurs et gerer les leaks
- erreurs nbr arg
- malloc structure "game"
- extension fichier (.ber pour les maps)
- mlx_init() -> gerer les erreurs
- ouverture de fichier lecture de map: get_next_line(), open(), close()
- si la map est rectangle
- si les caracteres sont correctes
- que des murs autours
- que toutes les xpm soit ok 
mlx_new_window(), mlx_xpm_file_to_image() -> aller chercher des images au format png, puis redimensionner sur paint en pixel 50/50
traduire des images en xpm

en fonction du besoin exit() ->
- window : mlx_destroy_window()
- mlx : mlx_destroy_display() + free()
- sprites (ceux sont les xmp) : mlx_destroy_image()

free();

2) initialisation des structures
- a NULL 0 ou la mlx mlx_init()

3) render
- analyser la map et afficher en de 1 element mlx_put_image_to_window()

4) Checker si une solution est possible dans la map
- utiliser algo floodfil

5) interactions avec le clavier
- mlx_key_hook(), choisir une fonction a implementer ex : ft_event_key()

inserer le code pour :
- autorisation avancer personnage ou pas,et action si ok

bonus : mlx_string_put() : afficher sr l ecran le nb de mouvement

5) appararaite le images en boucle
- mlx_loop()
- mlx_hook(), perment d inserer une fonction pour fermer la fenetre avec croix