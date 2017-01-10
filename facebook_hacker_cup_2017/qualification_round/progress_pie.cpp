#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

void run() {
    double percent, px, py, dist_from_o; // input
    double theta;
    double deg_from_percent;

    cin >> percent >> px >> py;

    px -= 50; py -= 50; // changing the center to origin
    dist_from_o = sqrt(px*px + py*py);

    // theta angle if the point from the origin +ve y axis
    theta = atan2(px, py) * 180/PI;
    theta = theta>0 ? theta : (360+theta);

    deg_from_percent = percent * 3.6;

    //cout << px<<"\t" << py<<"\t"<< theta <<"\t"<< deg_from_percent<< endl;

    if (dist_from_o > 50) {
        cout << "white" << endl;
        return ;
    }

    if (theta > deg_from_percent) cout << "white" << endl;
    else cout << "black" << endl;
}

int main() {

    int T;

    cin >> T;
    for(int i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": ";
        run();
    }

    return 0;
}
