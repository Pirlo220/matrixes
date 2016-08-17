# matrixes
C++ Console app that creates and manages matrixes. Practices in C++ coding vulnerabilities
## postgres
install libpqxx to comunicate the application with Postgresql http://pqxx.org/development/libpqxx/

From Synaptic Package Manager install postgres, libp, and lbpqxx

##libsodium
Downlaod current tar from https://download.libsodium.org/libsodium/releases/
then:
>$ ./configure
>$ make && make check
># make install

You need to run ldconfig after installing a new library.

If you get error like libsodium.so.18: cannot open shared object file: No such file or directory
You can execute cp /usr/local/lib/libsodium.so.18 /usr/lib

To compile: 
>g++ src/main.cpp -I /usr/local/include/pqxx -I include/ -o build/main -lpqxx -lpq -lsodium
and then 
>> ./build/main
