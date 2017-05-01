#include "Dijkstra.hpp"
#include <iostream>
#include <limits.h>

#define FOR_EACH(u,x) for(unsigned int u = 0; u < x; u++)

Dijkstra::Dijkstra(int size, unsigned int** graph): mSize(size), mGraph(graph), mSetSize(0)
{
    mPrevious = new unsigned int[mSize];
    mDistance = new unsigned int[mSize];
    mSet = new unsigned int[mSize];

    FOR_EACH(i,mSize)
    {
        mSet[i] = -1;
        mDistance[i] = mGraph[0][i];
        if( mDistance[i] < INT_MAX )
        {
            mPrevious[i] = 1;
        }
        else
        {
            mPrevious[i] = 0;
        }
    }
    mSet[mSetSize++] = 0;
}

Dijkstra::~Dijkstra()
{
    delete[] mPrevious;
    delete[] mDistance;
    delete[] mSet;
    FOR_EACH(i, mSize)
    {
        delete[] mGraph[i];
    }
    delete[] mGraph;
}

void Dijkstra::findMin(int* index, int* value)
{
    // find min distance that isnt to a w in the set;
    unsigned int min = INT_MAX;
    int min_index = -1;
    FOR_EACH(i,mSize)
    {
        if( checkUnique(i) )
        {
            if( mDistance[i] < min )
            {
                min_index = i;
                min = mDistance[i];
            }
        }
        else
        {
            continue;
        }
    }
    *index = min_index;
    *value = min;
}

bool Dijkstra::checkUnique(unsigned int u)
{
    bool check(true);
    FOR_EACH(j,mSetSize)
    {
        // if the index is already in our set, ignore it.
        if( mSet[j] == u )
        {
            check = false;
            break;
        }
    }
    return check;
}

void Dijkstra::Solve()
{
    while( mSetSize < mSize )
    {
        int w;
        int min_value;
        findMin(&w, &min_value);
        mSet[mSetSize++] = w;

        FOR_EACH(u,mSize)
        {
            if( checkUnique(u) )
            {
                if( mDistance[u] > mDistance[w] +mGraph[w][u])
                {
                    mDistance[u] = mDistance[w] + mGraph[w][u];
                    mPrevious[u] = w;
                }
            }
        }
    }
    {
        using namespace std;
        FOR_EACH(i, mSize)
        {
            cout << mDistance[i] << " ";
        }
        cout << endl;
    }

}
