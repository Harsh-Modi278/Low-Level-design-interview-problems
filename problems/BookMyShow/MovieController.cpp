#include "models/Movie.h"
#include "models/common.h"

class MovieController {
    set<Movie*> allMovies;
    map<City, set<Movie*>> moviesInCity;
public:
    set<Movie*> getAllMovies() {
        return allMovies;
    }

    set<Movie*> getAllMoviesPerCity(City city) {
        return moviesInCity[city];
    }

    void addMovie(Movie* newMovie, City city) {
        allMovies.insert(newMovie);
        moviesInCity[city].insert(newMovie);
    }

    void removeMovie(Movie* movie, City city) {
        auto it = allMovies.find(movie);
        if (it != allMovies.end()) {
            allMovies.erase(it);
        }

        if (moviesInCity.count(city)) {
            auto it1 = moviesInCity[city].find(movie);
            if (it1 != moviesInCity[city].end()) {
                moviesInCity[city].erase(it1);
            }
        }
    }
};