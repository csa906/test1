#include <iostream>
#include <cstring>
using namespace std;

class Photon_Cannon {
    private:
        int hp, shield;
        int coord_x, coord_y;
        int damage;
        char* name;

    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y, const char* cannon_name);
        Photon_Cannon(const Photon_Cannon &pc);
        ~Photon_Cannon();

        void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);

    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc) {
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

Photon_Cannon::~Photon_Cannon() {
    if (name != NULL) {
        delete[] name;
    }
}

void Photon_Cannon::show_status() {
    cout << "Photon Cannon" << endl;
    cout << "Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
    cout << "HP : " << hp << endl;
}

int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc1;

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();

    return 0;
}