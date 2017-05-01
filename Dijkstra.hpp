#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP


class Dijkstra
{
public:
    Dijkstra(int size, unsigned int** graph);
    ~Dijkstra();
    void Solve();
    
private:
    void readFile();
    void findMin(int*, int*);
    bool checkUnique(unsigned int);

    const unsigned int mSize;
    const unsigned int * const * const mGraph;
    unsigned int* mSet;
    unsigned int mSetSize;
    unsigned int* mPrevious;
    unsigned int* mDistance;
};


#endif
