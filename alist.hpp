#include <fstream>
#include <string>

class Alist {
    struct Edge {
        int dest = -1;
        int weight = 0;
        Edge* next = nullptr;
        Edge(int d, int w, Edge* n) : dest(d), weight(w), next(n) {}
        ~Edge() {delete next;}
    };
    Edge** list;
    int size;
    //Keeps track of how many connections each vertex has
    //makes the output step eaiser
    int* connections;

public:
    Alist(int verticies);
    ~Alist();

    void AddEdge(int vertex1, int vertex2, int weight);
    void FullyConnect();
    void CreateCycle();

    void Print(std::string filename = "graph.txt");
};