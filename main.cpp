#include <iostream>
#include "alist.hpp"

int main(int argc, char* argv[]) {

    Alist graph(atoi(argv[1]));
    graph.FullyConnect();
    graph.Print();

    return 0;
}