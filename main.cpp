
#include "classes/Engine.h"
#include <time.h>

int main() {
    srand(time(NULL));
    Engine engine;

    engine.start();

    return 0;
}
