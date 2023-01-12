# GRAFFIN_Lab1 report



### Introduction


Dans ce premier Lab, je vais mettre en œuvre un flow de conception dans un exemple simple : un chenillard. Je vais aussi m'apercevoir que sur certains aspects, cet exemple n'est pas aussi simple qu'il n'y parrait. Je vais utiliser la carte de développement DE10 Lite avec son FPGA. Je vais aussi utiliser la suite d'intel : Quartus 18.1 avec Platform Designer.
Le but est ainsi de créer un chenillard avec les leds présents sur la carte de développement DE10 Lite. Je vais aussi utiliser les boutons et les switchs de cette carte pour ajouter certaines fonctionnalités.


### Architecture


Pour ce premier exercice, j'ai utilisé un Nios2 avec ses périphériques nécessaire pour ce flow : Mémoire RAM, JTAG debugger, Clock. Pour interfacer tous les autres périphériques (bouton, switch, Leds) j'ai utilisé des PIO. Le tout communiquant avec le bus Avalon. Le montage final sur Platform Designer se trouve sur l'image ci-dessous avec le schéma:


![image](https://user-images.githubusercontent.com/75631006/212178333-fa4b9fe0-c9e9-4bfe-a043-b8fb1fc08147.png)


![image](https://user-images.githubusercontent.com/75631006/211356399-ac0007ec-12f5-4fcc-97d5-122cea5af28b.png)

J'ai utilisé 3 PIO pour connecter les périphériques extérieurs au FPGA, car les LEDs sont en sortie alors que les boutons et les switchs en entrée et j'ai différencié les switchs aux boutons pour que ce soit plus pratique dans le code C.
De plus, mon bloque hardware est simple, c'est juste la connexion avec la clock, le reset et les PIO dans le VHDL, et grâce à la datasheet de la carte DE10 Lite, j'ai connecté dans le pin planer les bonnes Pin avec mes ressources.


### Results / Progress

Le premier résultat, allumer un led était simple, sans trop de problèmes et surtout avec un code C minime. La prochaine étape était de faire le chenillard en lui même, encore une fois pas très compliqué. Là où j'ai eu plus de mal, c'est lorsqu'il a fallu changer la manière d'interagir avec le bouton et les switchs. En effet, les interruptions pour gérer la vitesse et le bouton start n'ont pas été simple à mettre en oeuvre.
Finalement, j'ai réussi à aller au bout de ce lab avec un chenillard sur les Leds qui est déclenché par un bouton géré par une interruption et dont la vitesse peut être changée via les switchs, eux même gérés avec une interruption. 

### conclusion

Ce lab m'a permis d'appréhender  un peut mieux le flow de conception en co-design, avec les commandes, l'ordre des manipulations, l'interaction entre le hard et le soft ou le pin mapping. Il y a certaines étapes que je n'avais jamais fait et cela m'a permis d'être sur de les comprendre pour pouvoir les reproduires lors des prochains lab et plus tard encore.
Le seul point noir où j'ai eu du mal a été par rapport aux interruptions que j'ai solutionné grâce à la documentationet à mes collègues.

