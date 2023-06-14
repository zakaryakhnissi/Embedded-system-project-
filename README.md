# Projet-de-systeme-embarquee

Ce projet est un programme de microcontrôleur écrit en C++ pour un microcontrôleur AVR. Il utilise divers modules et composants pour effectuer des lectures de capteurs et contrôler les moteurs en fonction des données des capteurs

## Description de la structure du code et de on fonctionnement
### Code principal

En ce qui concerne la fonction main(), on a jugé que la méthode de scrutation convient mieux
à nos besoins pour des raisons de performance ainsi que la simplicité de code qui rend le
débogage beaucoup plus facile. Compte tenu des nombreuses possibilités d’appuis sur le
clavier, le main() est munie d’une instruction switch qui permet d'exécuter le code
correspondant à l’appui d’une touche donnée. Pour l’implémentation de notre programme,
l’utilisation d’une deuxième instruction switch case a été considéré pour le bon
fonctionnement du bouton R et dans le but de rendre le code soit maintenable et facile à suivre.
En effet, la première instruction switch sert à identifier et afficher le bouton appuyé et la
deuxième, pour effectuer son comportement. Enfin pour que tout se déroule bien, la fonction
detectPressedButton() est appelée avant le switch case pour repérer le bouton appuyé
pour permettre à l’instruction switch de comparer la variable bouton et exécuter le
comportement désiré de chacun des boutons.
Une fois que l’on a vérifié si une touche a été appuyée, les distances qui séparent le robot des
obstacles qui l’entourent sont mesurées. Une section plus détaillée sur la mesure des
distances suivra. Pour chacune des distances mesurées, on détermine à quelle catégorie elle
appartient pour pouvoir faire un éventuel affichage et ultimement permettre au robot d’exécuter
une manœuvre d’évitement selon la combinaison de catégories obtenues.
C’est la deuxième switch case de la fonction main() qui permet de faire un affichage en
fonction de l’option d’affichage déterminée par l’utilisateur, en appelant la fonction display().

### Frequence de lecture

La lecture faite sur les capteurs se fait à une fréquence configurable lors d’appuis sur le clavier.
Pour mettre en évidence cette fréquence, nous démarrons une minuterie à chaque nouvelle
itération de la boucle infinie du programme. De cette façon, le déroulement du programme en
entier se fait au même rythme que la lecture des distances. Cependant, le délai qu’on laisse
n’est pas un temps pendant lequel le programme se fige. En effet, dans le corps du do {}
while(lecture == 0), on vérifie si un bouton du clavier a été pressé.

### Clavier

Le code du clavier est implémenté dans la fonction detectPressedButton(), on a choisi que
le clavier fonctionnera par scrutation pour des raisons de performances donc notre code prin-
cipal vérifie toujours si un bouton est appuyé en appelant la fonction dans plusieurs endroits
dans le code.

La fonction detectPressedButton() est responsable d’initialiser les ports, elle initialise
d’abord les ports liés aux lignes du clavier en sortie. Quand un bouton est appuyé le courant
va passer par la colonne correspondante pour être détecté par un des ports lies aux colonnes,
une fois qu’une broche détecte du courant, la fonction réinitialise les ports de façon que les
ports liés aux colonnes du clavier soient en sortie et ceux liés aux lignes en entrée, avec les
conditions de détection de courant la fonction fait l’intersection des lignes et colonnes pour
savoir le bouton appuyé.

![image](https://github.com/zakaryakhnissi/Embedded-system-project-/assets/136539693/af8b36fe-6adb-445f-8d8f-8405d04b8bc4)
Figure 1 : Ports lies aux lignes en sortie

![image](https://github.com/zakaryakhnissi/Embedded-system-project-/assets/136539693/41e5a04a-ee43-4f67-b9f8-727838b6ef13)
Figure 2 : Ports lies aux lignes en sortie 

### Capteurs de distances

Les lectures de distances sont faites à la fréquence à laquelle le programme s’exécute, soit 1,
2 ou 4 fois chaque seconde. Un tableau de distances de taille 3 conserve les distances
évaluées par le robot sur chaque côté. Le calcul se fait dans une boucle de 3 itérations dans
laquelle chacune des itérations correspond à une lecture sur un capteur. Pour une valeur x de
conversion donnée par le convertisseur externe ou interne via la fonction
computeConversion(), la formule qui permet de trouver une approximation de la distance à
laquelle elle correspond est :

28.998 ×(5x^(−1.141))/255

### Afficheur sept segments 

La façon par laquelle on a procédé pour résoudre le problème des afficheurs afin
d'implémenter une interface capable de prendre la distance relevée par les capteurs afin de
les afficher en décimal ou en hexadécimal le cas échéant, est l'implémentation de deux
fonctions nommées leftDisplays7() pour les deux afficheurs à gauche du pont-H et
rightDisplays7() pour les deux afficheurs à droite du pont-H. Ces fonctions prennent en
paramètre deux arguments. Le premier argument est la distance de type uint8_t et le
deuxième est une variable booléenne qui indique le mode d’affichage des afficheurs (décimal
ou hexadécimal). Cette interface est appelée dans l’exécution des manœuvres pour afficher la
puissance des roues.

