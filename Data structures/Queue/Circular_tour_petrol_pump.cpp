#include <iostream>
using namespace std;
struct petrolPump {
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n) {
    int front = 0;
    int rear = 0;
    int balance = 0;
    while(front < n) {
        balance += p[rear % n].petrol;
        if(balance - p[rear % n].distance >= 0) {
            balance -= p[rear % n].distance;
            rear++;
            if(front % n == rear % n) return front % n;
        }
        else {
            front = rear + 1;
            rear++;
            balance = 0;
        }
    }
    return -1; 
}
int main() {
    petrolPump a[] = {{2, 5}, {3, 4}, {1, 6}};
    int size = sizeof(a) / sizeof(petrolPump);
    cout << tour(a, size) << endl;
    return 0;
}