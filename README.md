# demineur
📝 README pour un projet Démineur en C
markdown
# 🧨 Démineur en C (version console)

Ce projet est une implémentation personnelle du jeu **Démineur** en langage C, jouable entièrement dans le **terminal**.  
Il s’agit d’un exercice complet pour pratiquer :

- la manipulation de matrices
- la gestion d’entrées utilisateur
- la logique de jeu
- la gestion du temps (chrono)
- la structuration d’un projet en C (source/, include/, Makefile)

---

## 🎮 Fonctionnalités

- Génération aléatoire d’une grille de mines  
- Calcul automatique du nombre de mines adjacentes  
- Affichage clair de la grille utilisateur  
- Commandes simples :
  - `Rxy` → Révéler une case
  - `Fxy` → Placer/retirer un drapeau
- Gestion des erreurs de saisie  
- Détection de victoire et de défaite  
- Chronomètre du temps de résolution  
- Architecture propre : séparation `.c` / `.h`

---

## 🧱 Structure du projet

demineur/
│
├── source/
│   ├── main.c
│   ├── fonctions_main.c
│   ├── menu.c
│   ├── utils.c
│
├── include/
│   ├── fonctions_main.h
│   ├── menu.h
│   ├── utils.h
│
├── Makefile
└── README.md

Code

---

## ▶️ Compilation & exécution

### **Compilation**
```bash
make
Exécution
bash
./demineur
⏱️ Chronomètre
Le programme mesure le temps réel de résolution grâce à time() :

début de partie → time(NULL)

fin de partie → time(NULL)

affichage du temps total en secondes

📌 Exemple de commandes utilisateur
Code
R34   → Révéler la case (3,4)
F78   → Placer un drapeau en (7,8)
R12 F45 R89 → Plusieurs commandes dans la même ligne
🛠️ Améliorations possibles
Mode difficulté (facile / moyen / difficile)

Interface graphique (SDL2)

Système de sauvegarde

Classement des meilleurs temps

Génération de grilles plus grandes

👤 Auteur
Sylvain Gaborit  
Projet personnel d’apprentissage du langage C.
