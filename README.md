
## Projet de recherche d'indexation de fichiers

### Description :
Ce projet est une application de recherche d'indexation de fichiers qui permet de rechercher des fichiers dans un répertoire donné en fonction de critères spécifiques. L'application indexe les fichiers dans un répertoire donné et permet de rechercher des fichiers en fonction de critères tels que l'extension, la date de création, la date de modification, la taille, etc.

### Fonctionnalités :
1. **Indexation des fichiers** :
    - L'application indexe les fichiers dans un répertoire donné.
    - Les fichiers sont indexés en fonction de leur nom, de leur chemin, de leur extension, de leur date de création, de leur date de modification et de leur taille.
2. **Recherche de fichiers** :
    - L'application permet de rechercher des fichiers en fonction de critères spécifiques.
    - Les critères de recherche incluent l'extension, la date de création, la date de modification, la taille, etc.
3. **Interface en ligne de commande** :
    - L'application est basée sur une interface en ligne de commande.

### Technologies utilisées :
1. **C++** :
    - Le projet est implémenté en C++ sur une base de QT.
2. **QT** :
    - Le projet est basé sur la bibliothèque QT.
3. **Git** :
    - Le projet est versionné avec Git.

### Installation et exécution :
1. **Cloner le dépôt** :
    ```bash
    git clone
    ```
2. **Compiler le projet** :
    ```bash
    make
    ```
3. **Exécuter l'application** :
    ```bash
    ./app
    ```
4. **Nettoyer les fichiers générés** :
    ```bash
    make clean
    ```

### Classes :
```mermaid
classDiagram
   class IndexerThread {
      <<Thread>>
      + run()
   }
   class Indexer {
      <<QObject>>
      + showIndex(QString path)
   }
   class ICommand {
      + execute(QList<Token> tokens)
   }
   class Clear {
      + execute()
   }
   class Add {
      + execute()
   }
   class Search {
      + execute(QList<Token> tokens)
      + initStateMachine()
   }
   class Get {
      + execute()
   }
   class Push {
      + execute()
   }
   class CommandFactory {
      + createCommand(QString commandType)
   }
   class Bdd {
      + getInstance()
      + insertdb(Line line)
      + select(QString query)
      + cleardb()
      + push(QString table, QVector<QString> list)
      + add(QString table, QString toadd)
      + searchFileName(QString filename)
   }
   class Debugging {
      + getInstance()
      + IsLoggerActive()
      + SetLoggerLevel(bool log)
   }
   class Token {
      + getValue()
      + getType()
   }
   class Lexer {
      + normalize(QString input)
      + tokenize(QString input)
      + classifyAndAddToken(QString tokenValue)
      + QVector<Token> getTokens()
   }
   class State {
      + State(QString name, ActionPtrFunc func)
      + run()
      + setFunc(ActionPtrFunc func)
      + getName()
   }
   class Transition {
      + Transition(State start, State end, ConditionPtrFunc condition, Fsm fsm)
      + run()
   }
   class Fsm {
      + run()
      + addState(State state)
      + addTransition(State from, State to, ConditionPtrFunc condition)
      + setInitialState(State state)
      + getNextToken()
      + currentToken()
   }

   IndexerThread <-- QThread : inherits
   Indexer <-- QObject : inherits
   Clear <-- ICommand : inherits
   Add <-- ICommand : inherits
   Search <-- ICommand : inherits
   Get <-- ICommand : inherits
   Push <-- ICommand : inherits
   CommandFactory --> ICommand : creates
   Fsm *--> State
   Fsm *--> Transition
   Fsm *--> Token
   Lexer --> Token : produces
   Debugging <-- Singleton
   Bdd <-- Singleton

```

### Explications :
1. **Relations d'héritage** :
    - Les flèches pleines indiquent les relations d'héritage avec l'étiquette `inherits`.
2. **Relations d'association** :
    - Les étiquettes "1-to-1" ou "1-to-many" expliquent le type de relation.
    - `-->` indique une relation unidirectionnelle.

### Diagramme d'état :
```mermaid
stateDiagram-v2
    [*] --> UNKNOWN : Start
    UNKNOWN --> INIT : COMMAND == "SEARCH"

    INIT --> GET_FILENAME : STRING
    GET_FILENAME --> GET_OPTION : OPTION
    GET_FILENAME --> FINISH : EOF

    GET_OPTION --> OPTION_EXT : OPTION == "EXT"
    GET_OPTION --> OPTION_LAST_MODIFY : OPTION == "LAST_MODIFIED"
    GET_OPTION --> OPTION_CREATED : OPTION == "CREATED"
    GET_OPTION --> OPTION_SIZE : OPTION == "SIZE"
    GET_OPTION --> OPTION_TYPE : OPTION == "TYPE"
    GET_OPTION --> OPTION_SIZE_MAX : OPTION == "MAX_SIZE"
    GET_OPTION --> OPTION_SIZE_MIN : OPTION == "MIN_SIZE"

    OPTION_SIZE --> GET_BETWEEN : LOGICAL_OPERATOR == "BETWEEN"
    GET_BETWEEN --> GET_SIZE : SIZE
    GET_SIZE --> GET_AND : LOGICAL_OPERATOR == "AND"
    GET_AND --> GET_SIZE : SIZE
    GET_SIZE --> GET_OPTION : OPTION
    GET_SIZE --> FINISH : EOF

    OPTION_EXT --> GET_LIST : LIST_VALUE
    GET_LIST --> GET_OPTION : OPTION
    GET_LIST --> FINISH : EOF

    OPTION_TYPE --> GET_LIST : LIST_VALUE

    OPTION_LAST_MODIFY --> GET_SINCE_LAST : LOGICAL_OPERATOR == "SINCE_LAST"
    GET_SINCE_LAST --> GET_VALUE : STRING
    GET_VALUE --> GET_UNIT : UNIT_TYPE
    GET_UNIT --> GET_OPTION : OPTION
    GET_UNIT --> FINISH : EOF

    OPTION_LAST_MODIFY --> GET_DATE : DATE
    GET_DATE --> GET_OPTION : OPTION
    GET_DATE --> FINISH : EOF

    OPTION_LAST_MODIFY --> GET_BETWEEN : LOGICAL_OPERATOR == "BETWEEN"

    OPTION_CREATED --> GET_SINCE_LAST : LOGICAL_OPERATOR == "SINCE_LAST"
    OPTION_CREATED --> GET_DATE : DATE
    OPTION_CREATED --> GET_BETWEEN : LOGICAL_OPERATOR == "BETWEEN"

    OPTION_SIZE_MAX --> GET_SIZE_SINGLE : SIZE
    GET_SIZE_SINGLE --> GET_OPTION : OPTION
    GET_SIZE_SINGLE --> FINISH : EOF

    OPTION_SIZE_MIN --> GET_SIZE_SINGLE : SIZE

    FINISH --> [*] : Complete
    ERROR --> [*] : Error Encountered
```

### Explications :
1. **États initiaux et finaux** :
    - L'état initial est marqué par `[ * ]` et se dirige vers `UNKNOWN`.
    - L'état final est marqué par `[ * ]` à la fin de transitions pertinentes comme `FINISH`.

2. **Transitions conditionnelles** :
    - Les transitions sont déclenchées par des conditions sur le type ou la valeur des tokens (par exemple, `COMMAND == "SEARCH"` ou `OPTION == "EXT"`).

3. **États intermédiaires** :
    - Chaque état exécute une logique particulière, et les transitions sont définies pour passer d'un état à l'autre selon les tokens analysés.

4. **Erreurs** :
    - L'état `ERROR` représente les cas où une transition invalide ou une erreur d'exécution est rencontrée.


### Auteurs :
- Enzo Parriel
- Louis Sasse
