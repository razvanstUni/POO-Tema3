#include <iostream>
#include "assets/PQueue.h"
using namespace std;

int main() {
    /*
     * Dummy example
     */

    string s1 = "test";
    string s2 = "string2";
    string s3 = s1 + " " + s2 + " ana";

    PQueue<string> q1,q2,q3;
    q1.insert(s1, 1);
    q2.insert(s2, 0);
    q2.insert(s3, 1);
    q1.insert("facultate", 0);

    q3 = q1 + q2;

    while( !q3.empty() ) {
        cout << q3.front() << " ";
        q3.pop();
    }

    return 0;
}