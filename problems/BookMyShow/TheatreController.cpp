#include "models/Theatre.h"

class TheatreController {
    set<Theatre*> allTheatres;
    map<City, set<Theatre*>> theatresInCity;
public:
    set<Theatre*> getAllTheatres() {
        return allTheatres;
    }

    set<Theatre*> getTheatresInCity(City city) {
        return theatresInCity.count(city) ? theatresInCity[city] : set<Theatre*>();
    }

    set<Theatre*> getTheatresInCityPlayingMovie(City city, Movie* movie) {
        set<Theatre*> result;
        if (theatresInCity.count(city)) {
            for (Theatre* t:theatresInCity[city]) {
                if (t->isPlaying(movie)) {
                    result.insert(t);
                }
            }
        }
        return result;
    }

    void addTheatre(Theatre* theatre, City city) {
        allTheatres.insert(theatre);
        theatresInCity[city].insert(theatre);
    }
};