#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int health;
    int attack;

    Combatant(string n = "", int h = 0, int a = 0): name(n), health(h), attack(a) {}
};

class Node {
public:
    Combatant c;
    Node* left;
    Node* right;

    Node(Combatant combatant) {
        c = combatant;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* root, Combatant c) {
        if (root == NULL)
            return new Node(c);
        if (c.name < root->c.name)
            root->left = insert(root->left, c);
        else
            root->right = insert(root->right, c);
        return root;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* remove(Node* root, string name) {
        if (root == NULL) return root;

        if (name < root->c.name)
            root->left = remove(root->left, name);
        else if (name > root->c.name)
            root->right = remove(root->right, name);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->c = temp->c;
            root->right = remove(root->right, temp->c.name);
        }
        return root;
    }

    void remove(string name) {
        root = remove(root, name);
    }

    bool isEmpty() {
        return root == NULL;
    }

    Node* getFrontline() {
        return findMin(root);
    }

    void display_Team (Node *root) {
        if (root == NULL) {
            return;
        }
        display_Team(root->left);
        cout << "Name: "<< root->c.name << " | Health: (" << root->c.health  << ") | Attack: (" << root->c.attack << ") \n";
        display_Team(root->right);
    }

    void display() {
        display_Team(root);
    }

};

class BattleQuest {
private:
    BST playerTeam;
    BST enemyTeam;

public:
    BattleQuest() {
        srand(time(0));
        initialize_teams();
    }

    void initialize_teams() {
        playerTeam.insert(Combatant("Fazeel", 100,80));
        playerTeam.insert(Combatant("Ali", 22,80));
        playerTeam.insert(Combatant("Amad", 12,100));
        playerTeam.insert(Combatant("Aiman", 10,100));
        playerTeam.insert(Combatant("Xavier", 17,06));

        enemyTeam.insert(Combatant("John", 29,56));
        enemyTeam.insert(Combatant("Woakes", 56,80));
        enemyTeam.insert(Combatant("Morgan", 45,43));
        enemyTeam.insert(Combatant("KhalidLatif", 43, 76));
        enemyTeam.insert(Combatant("Peitersen", 43,44));
    }

    void displayTeams() {
       cout << "\n------------- Player Team ---------------\n";
       playerTeam.display();
       cout << "\n------------- Enemy Team ---------------\n";
       enemyTeam.display();
    }

    void attack(Node* attacker, Node* defender, BST& defenderTeam) {
    Node* enemyPlayer = defenderTeam.getFrontline();

    srand(time(0));
    int random = rand() % 4;
    int attackDamage = attacker->c.attack + random;

    cout << attacker->c.name << " is attacking " << enemyPlayer->c.name << "!\n";
    enemyPlayer->c.health -= attackDamage;
    defender->c.health -= attackDamage;

    if (enemyPlayer->c.health <= 0) {
        cout << enemyPlayer->c.name << " has been disqualified!\n";
        defenderTeam.remove(enemyPlayer->c.name);
    }
}

bool checkWinner() {
    if (enemyTeam.root == NULL && playerTeam.root == NULL) {
        cout << "\nThe match is a draw!\n";
        return true;
    }
    else if (playerTeam.root == NULL) {
        cout << "\nEnemy team has won the game!\n";
        return true;
    }
    else if (enemyTeam.root == NULL) {
        cout << "\nPlayer team has won the game!\n";
        return true;
    }

    return false;
}

void start_battle() {
    bool playerTurn = false;
    int round = 1;

    while (true) {
        cout << "\n=========== Round " << round << " ===========\n";

        if (playerTurn) {
            cout << "\nPlayer team is attacking!\n";
            attack(playerTeam.getFrontline(), enemyTeam.root, enemyTeam);
        } 
        else {
            cout << "\nEnemy team is attacking!\n";
            attack(enemyTeam.getFrontline(), playerTeam.root, playerTeam);
        }

        cout << "\n------------- After Attack ---------------\n";
        displayTeams();

        if (checkWinner()) 
            break;

        playerTurn = !playerTurn;
        round++;
    }
}


};


int main() {
    BattleQuest game;
    game.start_battle(); 

    return 0;
}