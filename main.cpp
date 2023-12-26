#include <iostream>
#include "Manual.h"
#include "SputifyCore.h"
#include "Commandler.h"

int main() {
    SputifyCore server;
    Commandler system(&server);
    system.run();
}
