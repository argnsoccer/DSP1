#include "filereader.h"

int main(int argc, char *argv[])
{
    char* input = argv[1];
    char* output = argv[2];
    FileReader f;
    f.run(input, output);
    return 0;
}
