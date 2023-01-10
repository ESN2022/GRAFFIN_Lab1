# GRAFFIN_Lab1 report

Report content:
a. Introduction
b. System architecture:
QSYS components and their interaction, HW blocks, design choices
c. Progress, results (take photos if needed)
d. Conclusion: What have you learned, comment progress, pitfalls and solutions


### Introduction


Dans ce premier Lab, je vais mettre en œuvre un flow de conception dans un exemple simple : un chenillard. Je vais aussi m'apercevoir que sur certains aspects, cet exemple n'est pas aussi simple qu'il n'y parrait. Je vais utiliser la carte de développement DE10 Lite avec son FPGA. Je vais aussi utiliser la suite d'intel : Quartus 18.1 avec Platform Designer.
Le but est ainsi de créer un chenillard avec les leds présents sur la carte de développement DE10 Lite. Je vais aussi utiliser les boutons et les switchs de cette carte pour ajouter certaines fonctionnalités.


### Architecture


Pour ce premier exercice, j'ai utilisé un Nios2 avec ses périphériques nécessaire pour ce flow : Mémoire RAM, JTAG debugger, Clock. Pour interfacer tous les autres périphériques (bouton, switch, Leds) j'ai utilisé des PIO. Le montage final sur Platform Designer se trouve sur l'image ci-dessous :


![image](https://user-images.githubusercontent.com/75631006/211356399-ac0007ec-12f5-4fcc-97d5-122cea5af28b.png)



PK 3 PIO
HW Block -> simple (presque rien)

### Results / Progress


### conclusion

