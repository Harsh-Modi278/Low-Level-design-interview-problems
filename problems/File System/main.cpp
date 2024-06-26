#include "File.cpp"
#include "Directory.cpp"
#include "common.hpp"

int32_t main() {
    Directory* moviesDir = new Directory("Movies");

    moviesDir->add(new File("Rockstar"));
    Directory* marvelMovies = new Directory("Marvel Movies");
    marvelMovies->add(new File("Aveneger: Infinity war"));
    marvelMovies->add(new File("Spiderman: No way home"));

    moviesDir->add(marvelMovies);

    marvelMovies->ls();
    return 0;
}