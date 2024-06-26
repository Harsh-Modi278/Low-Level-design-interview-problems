#include "common.hpp"
#include "implementation/WeightMachineAdapter.cpp"

int32_t main() {
    //client
    WeightMachineAdapter * adapater =  new WeightMachineAdapter(new WeightMachineForBabies());
    cout<<fixed << std::setprecision(12)<<adapater->getWeightInKgs()<<"\n";
    return 0;
}