#include <iostream>
#include "compositor.h"

int main(int argc, char *argv[])
{
    server::Compositor compositor;
    compositor.start();

    return EXIT_SUCCESS;
}
