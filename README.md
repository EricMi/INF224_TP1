# Multimedia Base Prototype
_Pengfei Mi_
_20/02/2017_


### 1. Serveur (en C++)
#### 2e Etape: Class de base
- Fichiers corrélatifs: _Multimedia.h_, _Multimedia.cpp_.
- Fonctions réalisées:
 - Base class: **Multimedia**.
 - Deux constructeurs: un sans argument, un avec argument,
 - Le destructeur,
 - Les accesseurs,
 - Les modifieurs,
 - La méthode d'affichage qui est virtuelle.

#### 3e Etape: Programme de test
- Fichier corrélatif: _main.cpp_.
- Test label: _VERSION_BASIC_.
- Remarque: On pense à delete les pointeurs et les mettre nulles.

#### 4e Etape: Photos et videos
- Fichiers corrélatifs: _Photo.h_, _Video.h_.
- Test label: _VERSION_BASE_.
- Fonctions réalisées:
 - Deux classes: **Photo** et **Video**.
 - Les constructeurs,
 - Les accesseurs,
 - Les modifieurs,
 - Les méthodes d'affichage,
 - Les méthodes de jouer l'objet: on utilise les variables prédéfinis pour **identifier les systèmes d'exploitation**
 - Réponses aux questions:
  - On utilise la class abstraite.
  - Une class abstraite doit avoir au moins une méthode abstraite dont la déclaration se termine par **= 0**.
  - Il ne sera plus possible d'instancer des objets de la class de base, parce que la class abstraite n'est pas instanciable.

#### 5e Etape: Traitement générique (en utilisant le polymorphism)
- Fichier corrélatif: _main.cpp_.
- Test label: _VERSION_POLYMORPHISM_.
- Réponse aux questions:
 - C'est le polymorphism qui permet de faire cela.
 - On doit déclarer la fonction comme fonction virtuelle dans la class de base.
 - Le type des éléments du tableau est pointeur de multimedia **Multimedia ***, parce que un objet peut appartenir à plusieur tableaus, pour déminuer la consommation de mémoire, on utilise les pointeurs.
 - Les réferences en java sont comme des pointeurs, donc on n'utilise pas les pointeurs.

#### 6e Etape: Films et tableau
- Fichiers corrélatifs: _Film.h_ et _Film.cpp_.
- Test label: _VERSION_FILM_.
- Fonctions réalisées:
 - La class **Film** qui est dérivant de **Video**.
 - Le constructeur,
 - Le modifieur,
 - Deux accesseurs, un pour le pointeurs de tableau, un pour le nombre de chapitres,
 - La méthode d'affichage.
 - Réponse aux questions:
  - On retourne une valeur de type **const int*** pour qu'on ne peut pas modifier le pointé dehors la class.

#### 7e Etape: Destruction et copie des objets
- Fichiers corrélatifs: _Film.h_ et _Film.cpp_.
- Test label: _VERSION_DESTRUCTION_.
- Fonctions réalisées:
 - Le destructeur de la class Film,
 - Le constructeur par copie,
 - Le operateur **=**.
 - Réponse aux questions:
  - On doit modifier la class Film en ajoutant un destructeur.
  - On doit utilise la copie profonde.

#### 8e Etape: Créer des groups
- Fichier corrélatif: _Group.h_.
- Test label: _VERSION_GROUP_
- Fonctions réalisées:
 - La class **Group** qui est dérivant de **list/<Multimedia */>**,
 - Un constructeur,
 - Un accesseurs du nom,
 - Une méthode d'affichage.
 - Réponse aux questions:
 - La liste doit contenir des pointeurs d'objets, parce que si on utilise directement les objets, il va consommer beaucoup d'mémoire et temps.
 - En java, pour les objets, on utilise toujours les réferences.

#### 9e Etape: Gestion automatique de la mémoire
- Fichier corrélatif: _Group.h_.
- Test label: _VERSION_MEMORY_MGMT_.
- Fonctions réalisées:
 - On remplace les raw pointeurs par des smart pointeurs.

#### 10e Etape: Gestion cohérente des données
- Fichiers corrélatifs: _MyBase.h_, _MyBase.cpp_.
- Test label: _VERSION_MEDIABASE_.
- Fonctions réalisées:
 - La class **MyBase**,
 - Les méthodes pour créer Photo, Video et Film, qui renvoyent un MultimediaPtr
 - La méthode de rechercher et afficher un objet ou un groupe
 - La méthode de jouer un multimédia objet.
- Réponse aux questions:
 - On peut déclarer les fonctions dans _Photo_, _Video_, _Film_ comme méthodes protégées et déclarer _Group_ et _MyBase_ comme **friend class**.
- Question additionnelle:
 - La méthode pour supprimer un objet multimédia ou un groupe
 - Une fonction pour ajouter un objet multimédia à un groupe

#### 11e Etape: Client / Serveur
- Fichiers corrélatifs: _MyBase.h_, _MyBase.cpp_.
- Test label: _VERSION_SERVER_.
- Fonctions réalisées:
 - Dans la class _MyBase_, on réalise une fonction **processRequest()** pour traiter les requêtes.
 - command **PRINT** pour rechercher un objet multimedia et afficher ses attributs:
 ```
 PRINT <nom d'objet ou groupe>
 ```
 - command **PLAY** pour jouer un objet multimedia sur la serveur:
 ```
 PLAY <nom d'objet>
 ```

#### 12e Etape: Sérialisation / désérialisation
- Fichier corrélatifs: _MyBase.h_, _MyBase.cpp_, _Multimedia.h_, _Multimedia.cpp_, _Photo.h_, _Video.h_, _Film.h_, _Film.cpp_, _Group.h_.
- Test label: _VERSION_SERALISATION_.
- Fonctions réalisées:
 - Dans la class _MyBase_, on définit deux méthodes **save** et **load** pour sauvegarder et relire la table d'objets.
 - Dans les class _Multimedia_, _Photo_, _Video_, _Film_, on définit deux méthodes **write** et **read** pour sauvagarder et relire leur attributs.
 - Dans les class, on définit aussi une méthode **chassName** pour obtenir leur nom de class.

#### 13e Etape: Traitement des erreurs
- Fichier corrélatifs: _MyBase.cpp_, _MyBase.h_.
- Fonctions réalisées:
 - Quand on crée un objet ou groupe, il va chercher les deux tableau pour que il n'y a pas d'objet ayant même nom, on ne fait rien et afficher l'information des erreurs.
 - Quand on supprime un groupe ou un objet qui n'existe pas, on ne fait rien et afficher l'information des erreurs.
 - Quand on crée un objet ou groupe avec nom invalides, on throw une exception de type **_std::invalid_argument_**.
 - L'ensemble de caractères valides est:
 ```
 ABCDEFGHIJKLMNOPQRSTUVWXYZ
 abcdefghijklmnopqretuvwxyz
 0123456789
 ```
 - Quand on modifie le tableau de durées d'un Film ayant une taille nulle ou inférieure à zéro, on throw une exception de type **_std::invalid_argument_**.



### 2. Client (en Java/Swing)
#### class _MainWindow_
- Dans le constructeur, on réalise les fonctions suivantes:
 - Créer les éléments graphiques et les ajouter à la fenêtre.
 - Établir la concection avec le serveur.
 - Associer les buttons avec leur EventListeners.
- On définit une class imbriquée _ExitListener_ qui implemente la class _ActionListener_ pour la button *Exit*,
- On définit une class imbriquée _AddTextAction_ dérivant de la class _AbstractAction_ pour les buttons de commands.

### 3. Remarques
Dans la test de version finale, on a créé un base de données ayant les membres suivants:
- Objets multimédia:
 - _eiffel_: Photo
 - _telecom_: Photo
 - _rose_: Video
 - _jj_: Video
 - _twilight_: Film
- Groupes:
 - _MyPhoto_: _eiffel_, _telecom_
 - _MyVideo_: _rose_, _jj_
 - _MyMedia_: _eiffel_, _telecom_, _rose_, _jj_, _twilight_.
