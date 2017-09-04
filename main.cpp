#include "TQueue.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    double p1, p2;
    double q1, q2;
    int a;
    for (;;)
    {
        do
        {
            cout << "Enter probability of include [0..1]: ";
            cin >> p1;
            if ((p1 < 0) | (p1 > 1))
                cout << "WRONG PROBABILITY" << endl;
        } while ((p1 < 0) | (p1 > 1));
        cout << endl;
        do
        {
            cout << "Enter probability of exclude [0..1]: ";
            cin >> q1;
            if ((q1 < 0) | (q1 > 1))
                cout << "WRONG PROBABILITY" << endl;
        } while ((q1 < 0) | (q1 > 1));
        cout << endl;
        TQueue <double> q(10);
        do
        {
            cout << "1. Test" << endl;
            cout << "2. Clear" << endl;
            cout << "3. End" << endl;
            cout << "Enter number: ";
            cin >> a;
            cout << endl;
            switch (a)
            {
                case 1:
                {
                    for (int i = 0; i < 10; i++) {

                        p2 = rand() %100;
                        p2 /= 100;
                        q2 = rand() %100;
                        q2 /= 100;

                        if (q.IsFull()) {
                            cout << "QUEUE IS FULL" << endl;
                        } else if (p2 < p1) {
                            q.Push(p2);
                            cout << "Task added " << p2 << endl;
                        }

                        if (q.IsEmpty()) {
                            cout << "QUEUE IS EMPTY" << endl;
                        } else if (q2 < q1) {
                            cout << "Task deleted ";
                            q.Pop();
                        }
                    }
                    q.ShowQueue();
                    cout << endl;
                    break;
                }
                case 2:
                {
                    q.Clear();
                    cout << endl;
                    break;
                }
                case 3:
                {
                    return 0;
                }
                default:break;
            }
        } while (a!= 3);
    }
}