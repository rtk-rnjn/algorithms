#include <iostream>
using namespace std;

void hanoi_tower(int n, char from, char to, char aux){

    if(n == 1){
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;

    }

    hanoi_tower(n-1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi_tower(n-1, aux, to, from);

}

int main() {
    int n = 4;
    hanoi_tower(n, 'A', 'C', 'B');
    return 0;
}
