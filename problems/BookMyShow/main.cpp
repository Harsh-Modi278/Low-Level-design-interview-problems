#include "models/Theatre.h"
#include "MovieController.cpp"
#include "TheatreController.cpp"

void initializeData(MovieController *movieController, TheatreController* theatreController)
{
    User* dummyUser1 = new User(10, "Shoyo Hinata");
    User* dummyUser2 = new User(21, "Tobio Kageyama");
    // init movies
    Movie *movie1 = new Movie(1, "Rockstar", 159);
    Movie *movie2 = new Movie(2, "Haikyuu", 120);
    Movie *movie3 = new Movie(3, "Avengers: Infinity wars", 180);

    movieController->addMovie(movie1, City::HYDERABAD);
    movieController->addMovie(movie1, City::BENGAULURU);
    movieController->addMovie(movie1, City::MUMBAI);

    movieController->addMovie(movie2, City::HYDERABAD);
    movieController->addMovie(movie2, City::BENGAULURU);
    movieController->addMovie(movie2, City::MUMBAI);
    movieController->addMovie(movie2, City::VADODARA);

    movieController->addMovie(movie2, City::MUMBAI);
    movieController->addMovie(movie2, City::VADODARA);

    // init screens
    set<Seat *> seatsForScreen1;
    for (int i = 1; i <= 10; i++)
    {
        SeatCategory sc = (SeatCategory)(i % 3);
        int price = 100;
        if (sc == SeatCategory::GOLD)
            price += 200;
        else
            price += 300;
        Seat *seat = new Seat(i, price, sc);
        if (i%6 == 0) {
            seat->book(dummyUser1);
        } 
        seatsForScreen1.insert(seat);
    }
    Screen *screen1 = new Screen(1, seatsForScreen1);

    set<Seat *> seatsForScreen2;
    for (int i = 1; i <= 10; i++)
    {
        SeatCategory sc = (SeatCategory)(2 - i % 3);
        int price = 100;
        if (sc == SeatCategory::GOLD)
            price += 200;
        else
            price += 300;
        Seat *seat = new Seat(i, price, sc);
        if (i%4 == 0) {
            seat->book(dummyUser2);
        }
        seatsForScreen2.insert(seat);
    }
    Screen *screen2 = new Screen(1, seatsForScreen2);

    // init shows
    Show *show1 = new Show(1, movie1, screen1, 8);
    Show *show2 = new Show(2, movie1, screen2, 11);
    Show *show3 = new Show(3, movie2, screen1, 13);
    Show *show4 = new Show(4, movie3, screen2, 15);

    // init theatres
    Theatre *theatre1 = new Theatre(1, "PVR", City::BENGAULURU);
    Theatre *theatre2 = new Theatre(2, "AMB", City::HYDERABAD);
    Theatre *theatre3 = new Theatre(3, "Inox", City::VADODARA);
    Theatre *theatre4 = new Theatre(4, "Cinepolis", City::MUMBAI);

    theatre1->addScreen(screen1);
    theatre1->addShow(show1);
    theatre1->addShow(show3);

    theatre2->addScreen(screen1);
    theatre2->addShow(show1);
    theatre2->addShow(show3);

    theatre3->addScreen(screen2);
    theatre3->addShow(show2);
    theatre3->addShow(show3);
    theatre3->addShow(show4);

    theatre4->addScreen(screen2);
    theatre4->addShow(show2);
    theatre4->addShow(show4);

    theatreController->addTheatre(theatre1, City::BENGAULURU);
    theatreController->addTheatre(theatre2, City::HYDERABAD);
    theatreController->addTheatre(theatre3, City::VADODARA);
    theatreController->addTheatre(theatre4, City::MUMBAI);
};

void printMovies(set<Movie*> movies) {
    if (movies.size() > 0) {
        for (Movie *movie : movies) {
            cout<<movie->getName()<<" ";
        }
        cout<<"\n";
    }
    return;
};

int32_t main() {
    // init mock data
    TheatreController* theatreController = new TheatreController();
    MovieController* movieController = new MovieController();
    initializeData(movieController, theatreController);

    // user comes
    User *user = new User(1, "Harsh");
    
    // show all movies
    set<Movie*> allMovies = movieController->getAllMovies();
    cout<<"\nshowing all movies playing across cities:\n";
    printMovies(allMovies);

    // selects a city
    City selectedCity = City::VADODARA;
    cout<<"\nuser selected city: "<<selectedCity<<"\n";

    // show movies in selected city
    set<Movie*> moviesInSelectedCity = movieController->getAllMoviesPerCity(selectedCity);
    cout<<"\nmovies playing in "<<selectedCity<<": ";
    printMovies(moviesInSelectedCity);

    // selects a movie
    Movie* selectedMovie = *moviesInSelectedCity.begin();
    cout<<"\nuser selected "<<selectedMovie->getName()<<" movie\n";

    // theatres showing the selected movie
    set<Theatre*> theatres = theatreController->getTheatresInCityPlayingMovie(selectedCity, selectedMovie);
    cout<<"\nTheatres playing "<<selectedMovie->getName()<<" :\n";
    for (Theatre* theatre: theatres) {
        cout<<"theatre: "<<theatre->getName()<<"\n";
        cout<<"start timings: ";
        set<Show *> shows = theatre->getShows(selectedMovie);
        for (Show* show: shows) {
            cout<<show->getStartTiming()<<":00 HR ";
        }
        cout<<"\n";
    }

    // select show
    Theatre* selectedTheatre = *theatres.begin();
    set<Show *> showsInSelectedTheatre = selectedTheatre->getShows(selectedMovie);
    Show *selectedShow = *showsInSelectedTheatre.begin();
    cout<<"\nselected show: "<<selectedShow->getStartTiming()<<":00 HR\n";

    // show empty seats
    set<int> emptySeatIds = selectedShow->getEmptySeatIds();
    cout<<"\nEmpty seats: ";
    for (int seatId: emptySeatIds) {
        cout<<seatId<<" ";
    }
    cout<<"\n";

    // select seat
    int selectedSeatNumber = *emptySeatIds.rbegin();
    cout<<"selected seat: "<<selectedSeatNumber<<"\n";

    // book a seat
    selectedShow->getScreen()->bookSeat(user, selectedSeatNumber);
    cout<<"seat booked\n";

    // payment

    return 0;
}