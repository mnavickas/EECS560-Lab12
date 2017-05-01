#include <limits.h>
#include "Dijkstra.hpp"
#include <fstream>
#include <iostream>

void print(int** myArray, int size)
{

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j <size; ++j)
        {
            std::cout << myArray[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream inputfile("data.txt");
    int testCases;
    inputfile >> testCases;

    for( int i = 0; i < testCases; i++)
    {
        int testSize;
        inputfile >> testSize;
        unsigned int **graph = new unsigned int*[testSize];
        int temp;
        for( int y = 0; y < testSize; y++)
        {
            graph[y] = new unsigned int[testSize];
            for(int x = 0; x < testSize; x++)
            {
                 inputfile >> temp;
                 if(0 == temp && x != y)
                 {
                     temp = INT_MAX;
                 }
                 graph[y][x] = temp;
            }
        }

        //print(graph, testSize);
        std::cout << "Test Number "<< i <<" Solution:" <<std::endl;
        Dijkstra d(testSize, graph);
        d.Solve();

    }

    return 0;
}
