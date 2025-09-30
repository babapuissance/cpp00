# 📚 CPP Module 00 | 42 School

> **Introduction au langage C++98** : classes, objets, encapsulation, variables statiques  
> Un module progressif de 3 exercices pour maîtriser les fondamentaux de la POO en C++

[![C++](https://img.shields.io/badge/C++-98-blue.svg?style=for-the-badge&logo=cplusplus)](https://en.cppreference.com/)
[![42 School](https://img.shields.io/badge/42-School-orange.svg?style=for-the-badge)](https://42.fr/)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg?style=for-the-badge)](https://github.com/nassimfx/CPP-Module-00)
[![License](https://img.shields.io/badge/License-42-black.svg?style=for-the-badge)](https://github.com/nassimfx/CPP-Module-00/blob/main/LICENSE)
[![Made with ❤️](https://img.shields.io/badge/Made%20with-❤️-red.svg?style=for-the-badge)](https://github.com/nassimfx)

---

<div align="center">

### 🎯 **Objectif du Module**
Découvrir la **programmation orientée objet** en C++98 à travers des projets concrets et progressifs

[🚀 **Démarrage rapide**](#-installation--usage) • [📖 **Documentation**](#-ressources-utiles) • [🎓 **Objectifs**](#-objectifs-pédagogiques)

</div>

---

## 📊 Aperçu du projet

<div align="center">

| Métrique | Valeur |
|----------|--------|
| **📁 Exercices** | 3 (Ex00, Ex01, Ex02) |
| **📝 Fichiers source** | 11 fichiers C++ |
| **🏗️ Classes** | 3 (Contact, PhoneBook, Account) |
| **⚡ Lignes de code** | ~800 LOC |
| **🎯 Conformité** | 100% C++98 |

</div>

---

## 📂 Table des matières

| Exercice | Description | Concepts clés | Difficulté |
|----------|-------------|---------------|------------|
| **[Ex00 — Megaphone](#ex00--megaphone)** | Conversion en majuscules | Arguments, boucles | ⭐ |
| **[Ex01 — PhoneBook](#ex01--phonebook)** | Répertoire téléphonique | Classes, encapsulation | ⭐⭐ |
| **[Ex02 — Account](#ex02--account)** | Gestion de comptes bancaires | Variables statiques, logs | ⭐⭐⭐ |

---

## 🚀 Installation & Usage

### 📋 Prérequis
- **Compilateur C++98** : `g++` ou `clang++`
- **Make** : Système de build
- **Terminal** : Interface en ligne de commande

### ⚡ Compilation rapide
```bash
# Clone le repository
git clone https://github.com/nassimfx/CPP-Module-00.git
cd CPP-Module-00

# Compile tous les exercices
for dir in ex00 ex01 ex02; do
    echo "🔨 Compilation de $dir..."
    cd $dir && make && cd ..
done
```

### 🎮 Test rapide
```bash
# Test Ex00
cd ex00 && ./megaphone "Hello World"  # → HELLO WORLD

# Test Ex01  
cd ex01 && ./bin/phonebook  # Interface interactive

# Test Ex02
cd ex02 && ./account_tests | cat -e  # Logs formatés
```

### 🖼️ Démonstration

<details>
<summary><b>🔊 Ex00 - Megaphone en action</b></summary>

```bash
$ ./megaphone "hello world from 42"
HELLO WORLD FROM 42

$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

</details>

<details>
<summary><b>📱 Ex01 - PhoneBook Interface</b></summary>

```bash
╔══════════════════════════════════════╗
║      📱 My Awesome PhoneBook 📱      ║
╚══════════════════════════════════════╝

Available commands:
  ADD    - Add a new contact
  SEARCH - Search contacts  
  EXIT   - Quit program

PhoneBook> ADD
👤 Enter first name: John
👤 Enter last name: Doe
🏷️  Enter nickname: johndoe
📞 Enter phone number: 0123456789
🤫 Enter darkest secret: I love C++
✅ Contact added successfully!

PhoneBook> SEARCH
     INDEX|FIRST NAME| LAST NAME|  NICKNAME|
----------|----------|----------|----------|
         0|      John|       Doe|   johndoe|
Enter index (0-0): 0
👤 First Name: John
👤 Last Name: Doe
🏷️  Nickname: johndoe
📞 Phone Number: 0123456789
🤫 Darkest Secret: I love C++
```

</details>

<details>
<summary><b>🏦 Ex02 - Account System Logs</b></summary>

```bash
[20250127_184455] index:0;amount:42;created
[20250127_184455] index:1;amount:54;created
[20250127_184455] index:2;amount:957;created
[20250127_184455] accounts:3;total:1053;deposits:0;withdrawals:0
[20250127_184455] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[20250127_184455] index:1;p_amount:54;withdrawal:refused
[20250127_184455] index:0;amount:47;closed
[20250127_184455] index:1;amount:54;closed
[20250127_184455] index:2;amount:957;closed
```

</details>

---

## 🔊 Ex00 — Megaphone

<div align="center">

**🎯 Objectif** : Créer un programme qui convertit les arguments en **MAJUSCULES**

![Megaphone Demo](https://img.shields.io/badge/Conversion-MAJUSCULES-yellow.svg?style=for-the-badge)

</div>

### 💡 Concept
Le premier contact avec les **arguments de ligne de commande** et la manipulation de chaînes en C++98.

### 🚀 Usage
```bash
cd ex00
make

# Avec arguments
./megaphone "shhhh... students are asleep"
# Output: SHHHH... STUDENTS ARE ASLEEP

# Sans arguments
./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ✨ Fonctionnalités
- ✅ **Conversion automatique** en majuscules (`std::toupper`)
- ✅ **Gestion des arguments multiples** (concatenation)
- ✅ **Message par défaut** si aucun argument fourni
- ✅ **Gestion des caractères spéciaux** et accents

### 🧠 Concepts appris
- Arguments `argc` et `argv`
- Boucles `for` avec index
- Fonctions de caractères (`toupper`)
- Conditions simples

---

## 📱 Ex01 — PhoneBook

<div align="center">

**🎯 Objectif** : Créer un répertoire téléphonique interactif avec **8 contacts maximum**

![PhoneBook Demo](https://img.shields.io/badge/Interface-Interactive-green.svg?style=for-the-badge)
![Ring Buffer](https://img.shields.io/badge/Algorithm-Ring%20Buffer-blue.svg?style=for-the-badge)

</div>

### 💡 Concept
Introduction à la **programmation orientée objet** : classes, encapsulation, et gestion d'état.

### 🎮 Interface
```
╔══════════════════════════════════════╗
║      📱 My Awesome PhoneBook 📱      ║
╚══════════════════════════════════════╝

Available commands:
  ADD    - Add a new contact
  SEARCH - Search contacts  
  EXIT   - Quit program

PhoneBook> 
```

### 🚀 Usage
```bash
cd ex01
make
./bin/phonebook
```

### ✨ Fonctionnalités
- ✅ **Interface interactive** avec couleurs ANSI et emojis
- ✅ **Validation robuste** des entrées utilisateur
- ✅ **Ring buffer intelligent** : remplace le plus ancien contact
- ✅ **Affichage formaté** : colonnes de 10 caractères alignées à droite
- ✅ **Gestion d'erreurs** : EOF, entrées vides, index invalides
- ✅ **Recherche intuitive** par index avec validation

### 🎯 Règles d'affichage SEARCH
| Champ | Largeur | Alignement | Troncature |
|-------|---------|------------|------------|
| Index | 10 | Droite | - |
| First Name | 10 | Droite | `.` |
| Last Name | 10 | Droite | `.` |
| Nickname | 10 | Droite | `.` |

### 🧠 Concepts appris
- **Classes et objets** (`Contact`, `PhoneBook`)
- **Encapsulation** : membres privés avec getters/setters
- **Constructeurs/destructeurs**
- **Algorithmes de données** : ring buffer
- **Interface utilisateur** : entrée/sortie interactive
- **Validation d'entrées** et gestion d'erreurs

---

## 🏦 Ex02 — Account

<div align="center">

**🎯 Objectif** : Implémenter un système bancaire avec **variables statiques** et **logging**

![Banking System](https://img.shields.io/badge/System-Banking-gold.svg?style=for-the-badge)
![Static Variables](https://img.shields.io/badge/Concept-Static%20Members-purple.svg?style=for-the-badge)

</div>

### 💡 Concept
Maîtrise des **variables statiques de classe** : partage d'état entre toutes les instances.

### 🏗️ Architecture
```cpp
class Account {
private:
    // Variables STATIQUES (partagées entre toutes les instances)
    static int _nbAccounts;        // Nombre total de comptes
    static int _totalAmount;       // Montant total de tous les comptes
    static int _totalNbDeposits;   // Nombre total de dépôts
    static int _totalNbWithdrawals; // Nombre total de retraits
    
    // Variables D'INSTANCE (propres à chaque compte)
    int _accountIndex;    // Index unique du compte
    int _amount;          // Solde actuel
    int _nbDeposits;      // Nombre de dépôts sur ce compte
    int _nbWithdrawals;   // Nombre de retraits sur ce compte
};
```

### 🚀 Usage
```bash
cd ex02
make
./account_tests | cat -e
```

### 📊 Exemple de logs
```bash
[20250127_184455] index:0;amount:42;created
[20250127_184455] index:1;amount:54;created
[20250127_184455] accounts:2;total:96;deposits:0;withdrawals:0
[20250127_184455] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[20250127_184455] index:0;p_amount:47;withdrawal:refused
[20250127_184455] index:0;amount:47;closed
```

### ✨ Fonctionnalités
- ✅ **Gestion multi-comptes** avec index automatique
- ✅ **Dépôts sécurisés** avec mise à jour des statistiques
- ✅ **Retraits contrôlés** : refus si solde insuffisant
- ✅ **Statistiques globales** en temps réel
- ✅ **Logs horodatés** : format `[YYYYMMDD_HHMMSS]`
- ✅ **Destruction propre** avec décompte automatique

### 🎯 Format de logs strict
| Événement | Format | Exemple |
|-----------|--------|---------|
| Création | `index:X;amount:Y;created` | `index:0;amount:42;created` |
| Dépôt | `index:X;p_amount:Y;deposit:Z;amount:W;nb_deposits:N` | `index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1` |
| Retrait OK | `index:X;p_amount:Y;withdrawal:Z;amount:W;nb_withdrawals:N` | `index:0;p_amount:47;withdrawal:5;amount:42;nb_withdrawals:1` |
| Retrait refusé | `index:X;p_amount:Y;withdrawal:refused` | `index:0;p_amount:42;withdrawal:refused` |
| Fermeture | `index:X;amount:Y;closed` | `index:0;amount:42;closed` |
| Infos globales | `accounts:X;total:Y;deposits:Z;withdrawals:W` | `accounts:8;total:19349;deposits:8;withdrawals:8` |

### 🧠 Concepts appris
- **Variables statiques** : partage d'état entre instances
- **Méthodes statiques** : accès aux données globales
- **Horodatage** : manipulation de `std::time` et `std::strftime`
- **Gestion de mémoire** : constructeurs/destructeurs
- **Logging structuré** : format de sortie strict
- **Validation métier** : règles bancaires (solde suffisant)

---

## ⚙️ Stack Technique & Architecture

### 🛠️ Technologies utilisées
| Composant | Version | Description |
|-----------|---------|-------------|
| **Langage** | C++98 | Standard ISO/IEC 14882:1998 |
| **Compilateur** | `c++` | Flags: `-Wall -Wextra -Werror -std=c++98` |
| **Build System** | Make | Règles: `all`, `clean`, `fclean`, `re` |
| **Architecture** | POO | Classes, encapsulation, héritage |

### 📁 Organisation des fichiers
```
CPP-Module-00/
├── ex00/
│   ├── megaphone.cpp
│   └── Makefile
├── ex01/
│   ├── Contact.hpp/cpp
│   ├── PhoneBook.hpp/cpp
│   ├── main.cpp
│   ├── Makefile
│   ├── obj/          # Fichiers objets (.o)
│   └── bin/          # Exécutable
├── ex02/
│   ├── Account.hpp/cpp
│   ├── tests.cpp
│   ├── Makefile
│   └── obj/          # Fichiers objets (.o)
└── README.md
```

### ✅ Standards de qualité respectés
- **🚫 Pas de `using namespace std;`** : Utilisation explicite de `std::`
- **🔒 Include guards** : Protection contre les inclusions multiples
- **📝 Headers propres** : Déclarations uniquement, pas d'implémentation
- **📐 Format strict** : Respect exact des spécifications de sortie
- **🗂️ Organisation** : Séparation claire des fichiers objets et exécutables
- **⚡ Performance** : Compilation optimisée avec flags de sécurité
- **🧹 Code propre** : Noms de variables explicites, commentaires pertinents

### 🎯 Conformité 42
- ✅ **Norme C++98** strictement respectée
- ✅ **Flags de compilation** : `-Wall -Wextra -Werror`
- ✅ **Structure des fichiers** conforme aux exigences
- ✅ **Format de sortie** identique aux spécifications
- ✅ **Gestion d'erreurs** robuste et cohérente

---

## 📖 Ressources & Documentation

### 🔗 Liens utiles
- **[C++98 Reference](https://en.cppreference.com/)** - Documentation officielle
- **[42 Subject PDF](https://cdn.intra.42.fr/pdf/pdf/5/cpp_module_00.en.pdf)** - Sujet officiel
- **[Professional README Guide](https://coding-boot-camp.github.io/full-stack/github/professional-readme-guide/)** - Guide de rédaction

### 📚 Concepts approfondis
- **[Variables statiques en C++](https://en.cppreference.com/w/cpp/language/static)** - Documentation détaillée
- **[Ring Buffer Algorithm](https://en.wikipedia.org/wiki/Circular_buffer)** - Principe algorithmique
- **[ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code)** - Codes couleur terminal

---

## 🎯 Objectifs pédagogiques

<div align="center">

### 🎓 **Compétences acquises**

| Concept | Description | Exercice |
|---------|-------------|----------|
| **🔤 Arguments CLI** | Gestion `argc`/`argv` | Ex00 |
| **🏗️ Classes** | Définition et instanciation | Ex01 |
| **🔒 Encapsulation** | Membres privés/publics | Ex01 |
| **⚡ Variables statiques** | Partage d'état global | Ex02 |
| **🎮 Interface utilisateur** | Entrée/sortie interactive | Ex01 |
| **📊 Algorithmes** | Ring buffer, validation | Ex01-02 |
| **📝 Logging** | Formatage et horodatage | Ex02 |

</div>

### 🚀 Progression d'apprentissage

1. **Ex00** : **Bases** - Arguments, boucles, manipulation de chaînes
2. **Ex01** : **POO** - Classes, objets, encapsulation, algorithmes
3. **Ex02** : **Avancé** - Variables statiques, logging, architecture

### 💡 Valeur ajoutée
- ✅ **Code production-ready** avec gestion d'erreurs robuste
- ✅ **Architecture propre** respectant les standards C++98
- ✅ **Interface utilisateur** moderne avec couleurs et emojis
- ✅ **Documentation complète** pour faciliter la maintenance

---

---

*Développé avec ❤️ dans le cadre du cursus 42 School - Module 00 C++*
