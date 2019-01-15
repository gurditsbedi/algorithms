#include <bits/stdc++.h>

using namespace std;

bool dist_possible(int num_boxes, int boxes[], int num_children)
{
    bool subset[num_boxes+1][num_children+1];

    for (int i = 0; i <= num_boxes; i++)
        subset[i][0] = true;

    for (int i = 1; i <= num_children; i++)
        subset[0][i] = false;

    for (int i = 1; i <= num_boxes; i++) {
        for (int j = 1; j <= num_children; j++)
        {
            if(j<boxes[i-1])
                subset[i][j] = subset[i-1][j];
            if (j >= boxes[i-1])
                subset[i][j] = subset[i-1][j] ||
                    subset[i - 1][j-boxes[i-1]];
        }
    }

    // uncomment this code to print table
    //for (int i = 0; i <= num_boxes; i++) {
        //for (int j = 0; j <= num_children; j++)
            //printf ("%4d", subset[i][j]);
        //printf("\n");
    //}

    return  subset[num_boxes][num_children];
}


int main() {
    int t = 0;
    int tmpint;
    int result;

    int num_boxes;
    int num_children;

    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> num_boxes;
        int boxes[num_boxes];
        for(int b=0; b<num_boxes; b++) {
            cin >> tmpint;
            boxes[b] = tmpint;
        }
        cin >> num_children;


        //cout << num_children << "->";
        //for(int b=0; b<num_boxes; b++) cout << boxes[b] << " ";
        //cout << endl;

        result = dist_possible(num_boxes, boxes, num_children);
        if(result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

