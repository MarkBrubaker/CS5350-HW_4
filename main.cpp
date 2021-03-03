#include <iostream>
#include "alist.hpp"

int main(int argc, char* argv[]) {

    //Time to time
    Alist graph(atoi(argv[1]));
    graph.FullyConnect();
    graph.Print();

    return 0;
}