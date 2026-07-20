#include "2205150_IOHandler.hpp"

int main(int argc, char *argv[]){
    if(argc < 3){
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    IOHandler *io_handler = new IOHandler(argv[1], argv[2]);
    io_handler->run();
    delete io_handler;

    return 0;
}