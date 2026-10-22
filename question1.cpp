#include <iostream>
using namespace std;

int main()
{
    int block[10], process[10], b, p;
    int temp[10], i, j, k;

    cout << "Enter number of blocks: ";
    cin >> b;

    cout << "Enter block sizes: ";
    for(i = 0; i < b; i++)
        cin >> block[i];

    cout << "Enter number of processes: ";
    cin >> p;

    cout << "Enter process sizes: ";
    for(i = 0; i < p; i++)
        cin >> process[i];

    // First Fit
    for(i = 0; i < b; i++)
        temp[i] = block[i];

    cout << "First Fit:";
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < b; j++)
        {
            if(temp[j] >= process[i])
            {
                cout << process[i] << " -> Block " << j + 1 << endl;
                temp[j] -= process[i];
                break;
            }
        }

        if(j == b)
            cout << process[i] << " -> Not allocated";
    }

    // Best Fit
    for(i = 0; i < b; i++)
     {
        temp[i] = block[i];
     }
    cout << "Best Fit:";
    for(i = 0; i < p; i++)
    {
        k = -1;
        for(j = 0; j < b; j++)
        {
            if(temp[j] >= process[i])
            {
                if(k == -1 || temp[j] < temp[k])
                    k = j;
            }
        }

        if(k != -1)
        {
            cout << process[i] << " -> Block " << k + 1 << endl;
            temp[k] -= process[i];
        }
        else
            cout << process[i] << " -> Not allocated";
    }

    // Worst Fit
    for(i = 0; i < b; i++)
      {
        temp[i] = block[i];
      }
    cout << "Worst Fit:";
    for(i = 0; i < p; i++)
    {
        k = -1;
        for(j = 0; j < b; j++)
        {
            if(temp[j] >= process[i])
            {
                if(k == -1 || temp[j] > temp[k])
                    k = j;
            }
        }

        if(k != -1)
        {
            cout << process[i] << " -> Block " << k + 1 << endl;
            temp[k] -= process[i];
        }
        else
            cout << process[i] << " -> Not allocated";
    }

    return 0;
}
