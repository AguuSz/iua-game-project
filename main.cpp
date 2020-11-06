
#include "classes/Engine.h"
#include <time.h>
#include <ctime>

int main() {
    srand(time(NULL));
    Engine engine;

    engine.start();

    return 0;
}
