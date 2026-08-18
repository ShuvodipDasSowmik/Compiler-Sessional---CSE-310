git clone https://github.com/Irtiaz/antlr4.git
cd antlr4
cd runtime/Cpp
mkdir build && cd build
cmake ..
make
sudo make install

# python3 -m venv venv
# source venv/bin/activate
# pip install antlr4-tools
# antlr4 -v 4.13.2