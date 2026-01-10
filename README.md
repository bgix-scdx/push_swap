*This project has been created as part of the 42 curriculum by <bgix>,<vgerthof>*

**Description :**
	Description

**Instructions :**
	Instructions

**Resources :**
	Resources






//  █████  ████████ ████████ ███████ ███    ██ ████████ ██  ██████  ███    ██     ██ ██ 
// ██   ██    ██       ██    ██      ████   ██    ██    ██ ██    ██ ████   ██     ██ ██ 
// ███████    ██       ██    █████   ██ ██  ██    ██    ██ ██    ██ ██ ██  ██     ██ ██ 
// ██   ██    ██       ██    ██      ██  ██ ██    ██    ██ ██    ██ ██  ██ ██           
// ██   ██    ██       ██    ███████ ██   ████    ██    ██  ██████  ██   ████     ██ ██ 
je met ici quelques expliquation a propos de la maniere dont sont stocker les nombres de coups et les flags



Les flags sont lu par la fonction parseur et sont automiatiqquement ranger dans la struture all

all.list_flags contient les valeurs 0 ou 1 selon la presence ou non d'un flag. Elle est organiser de la maniere suivante:

list_flags = [--simple][--medium][--compex][--adapt][--bench]

par exemple si list_flags = 00101 alors le programe devra utiliser les fonctions correspondant au flags complex et bench


Les moves sont compter dans all.list_move

elle est organiser selon le shema si dessou

list_move = [sa][sb][ss][pa][pb][ra][rb][rr][rra][rrb][rrr]

la variable all.move correspond quand a elle aux nombre de coup total , elle peut etre simplement calculer par count_moves() (fonction de debbugage)