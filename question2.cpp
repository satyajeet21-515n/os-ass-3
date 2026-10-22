#include <iostream>
using namespace std;

int main()
{
    int page[20], frame[10], last[10];
    int n, f, i, j, k, pos;
    int fault, hit, found;

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page reference string: ";
    for(i = 0; i < n; i++)
      {
        cin >> page[i];
      }

    cout << "Enter number of frames: ";
    cin >> f;

    // FIFO
    fault = 0;
    hit = 0;
    pos = 0;

    for(i = 0; i < f; i++)
        frame[i] = -1;

    cout << "FIFO:";

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
         {
            if(frame[j] == page[i])
                found = 1;
          }

        if(found == 0)
        {
            frame[pos] = page[i];
            pos = (pos + 1) % f;
            fault++;
        }
        else
            hit++;

        for(j = 0; j < f; j++)
           {
            cout << frame[j] << " ";
            cout << endl;
           }
    }

    cout << "Page Faults = " << fault << endl;
    cout << "Page Hits = " << hit << endl;

    // LRU
    fault = 0;
    hit = 0;

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        last[i] = -1;
    }

    cout << "\nLRU:\n";

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
          {
            if(frame[j] == page[i])
            {
                found = 1;
                last[j] = i;
            }
         }

        if(found == 0)
        {
            pos = -1;

            for(j = 0; j < f; j++)
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }

            if(pos == -1)
            {
                pos = 0;
                for(j = 1; j < f; j++)
                    if(last[j] < last[pos])
                        pos = j;
            }

            frame[pos] = page[i];
            last[pos] = i;
            fault++;
        }
        else
            hit++;

        for(j = 0; j < f; j++)
          {
            cout << frame[j] << " ";
          }
        cout << endl;
    }

    cout << "Page Faults = " << fault << endl;
    cout << "Page Hits = " << hit << endl;

    // Optimal
    fault = 0;
    hit = 0;

    for(i = 0; i < f; i++)
     {
        frame[i] = -1;
     }

    cout << "Optimal:";

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
            if(frame[j] == page[i])
                found = 1;

        if(found == 0)
        {
            pos = -1;

            for(j = 0; j < f; j++)
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }

            if(pos == -1)
            {
                int farthest = -1;

                for(j = 0; j < f; j++)
                {
                    for(k = i + 1; k < n; k++)
                        if(frame[j] == page[k])
                            break;

                    if(k == n)
                    {
                        pos = j;
                        break;
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = page[i];
            fault++;
        }
        else
            hit++;

        for(j = 0; j < f; j++)
            cout << frame[j] << " ";
        cout << endl;
    }

    cout << "Page Faults = " << fault << endl;
    cout << "Page Hits = " << hit << endl;

    return 0;
}
