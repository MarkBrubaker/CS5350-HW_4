#include "alist.hpp"

Alist::Alist(int verticies) {
    size = verticies;
    list = new Edge*[size];
    connections = new int[size];

    for(int x = 0; x < size; x++) {
        list[x] = nullptr;
        connections[x] = 0;
    }
}

Alist::~Alist() {
    for(int x = 0; x < size; x++) {
        delete list[x];
    }
    delete[] list;
}

void Alist::AddEdge(int vertex1, int vertex2, int weight) {
    //constant
    Edge* e = new Edge(vertex2, weight, list[vertex1]);
    //constant
    list[vertex1] = e;
    //constant but not needed
    //jsut helps make output eaiser
    connections[vertex1]++;
}

void Alist::FullyConnect() {
    //n
    for(int x = 0; x < size; x++) {
        //n
        for(int y = 0; y < size; y++) {
            //constant
            if(x == y) continue;
            //constant
            AddEdge(x, y, 1);
        }
    }
}

void Alist::CreateCycle() {
    //n - 1
    for(int x = 0; x < size - 1; x++) {
        //constant
        AddEdge(x, x + 1, 1);
    }
    //1
    AddEdge(size - 1, 0, 1);
}

void Alist::Print(std::string filename) {
    std::ofstream file(filename);

    file << size << std::endl;

    int currentLine = size + 1;
    for(int x = 0; x < size; x++) {
        file << currentLine << std::endl;
        currentLine += connections[x];
    }

    for(int x = 0; x < size; x++) {
        Edge* curr = list[x];
        while(curr != nullptr) {
            file << curr->dest << " " << curr->weight << std::endl;
            curr = curr->next;
        }
    }

    file.close();
}