#include <application.hpp>

int main(int argc, char* argv[])
{
    application app;

    if (app.initialize() < 0) {
        exit(1);
    }

    if (app.run() < 0) {
        exit(1);
    }
    return 0;
}