# matrixes
C++ Console app that creates and manages matrixes. Practices in C++ coding vulnerabilities
## postgres
install libpqxx to comunicate the application with Postgresql http://pqxx.org/development/libpqxx/

From Synaptic Package Manager install postgres, libp, and lbpqxx

To compile: 
>g++ src/main.cpp -I /usr/local/include/pqxx -I include/ -o build/main -lpqxx -lpq
and then 
> ./main2
