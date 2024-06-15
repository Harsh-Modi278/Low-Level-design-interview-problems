#include "models/common.h"
#include "models/User.h"
#include "models/Vehicle.h"
#include "Store.cpp"

vector<Vehicle *> getMockVehicles()
{
    vector<Vehicle *> mockVehicles;

    for (int i = 1; i <= 5; i++)
    {
        Vehicle *v = new Vehicle(i, i + 100, VehicleType::CAR, string("Skoda"), string("Kushaq"), 25, 2000, 100, 4, i < 5 ? VehicleStatus::ACTIVE : VehicleStatus::INACTIVE);
        mockVehicles.push_back(v);
    }

    for (int i = 6; i <= 10; i++)
    {
        Vehicle *v = new Vehicle(i, i + 100, VehicleType::BIKE, string("Royal Enfield"), string("RE"), 20, 2000, 100, 4, i < 10 ? VehicleStatus::ACTIVE : VehicleStatus::INACTIVE);
        mockVehicles.push_back(v);
    }

    return mockVehicles;
}

vector<User *> getMockUsers()
{
    vector<User *> mockUsers;

    for (int i = 1; i <= 3; i++)
    {
        User *u = new User(i, string("user" + string(1,i)), i + 100);
        mockUsers.push_back(u);
    }

    return mockUsers;
}

vector<Store *> getMockStores()
{
    vector<Store *> mockStores;
    vector<Vehicle *> mockVehicles = getMockVehicles();

    Location *loc = new Location("mock address", "Hyd", "Telangana", "India", 500032);
    Store *s = new Store(1, loc);
    s->addVehicles(mockVehicles);
    mockStores.push_back(s);

    return mockStores;
}

int32_t main() {
    // get mock users and mock vehicles
    vector<User*> users = getMockUsers();
    
    // get mock stores
    vector<Store*> stores = getMockStores();
    
    // user comes
    User* user = users[0];

    // user searches based on location
    Location *loc = new Location("mock address", "Hyd", "Telangana", "India", 500032);
    // location based filtering logic
    Store* store = stores[0];

    // get vehicles based on filter
    vector<Vehicle*> interestedVehicles = store->getVehicles(VehicleType::CAR);

    // reserve a vehicle
    Reservation* reservation = store->createReservation(user, interestedVehicles[0]);

    // generate the bill

    // make payment
    return 0;
}