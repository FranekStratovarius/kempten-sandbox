mkdir kochtopf out

g++ -fPIC -c -Wall -Wextra -I ./header ./src/bib.cpp -o ./kochtopf/bib.o
ld -shared ./kochtopf/bib.o -o ./out/libbib.so
g++ -Wall -Wextra ./src/main.cpp -I ./header -o ./out/main -L./out -lbib -Wl,-rpath=.
# https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
# https://stackoverflow.com/questions/966960/what-does-fpic-mean-when-building-a-shared-library
