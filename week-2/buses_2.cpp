#include <iostream>
#include <map>
#include <vector>
using namespace std;

void BusesAndStops() {
  int q;
  cin >> q;

  map<vector<string>, int> stops_to_buses;
  for (int i = 0; i < q; ++i) {
    ulong stops_number;
    cin >> stops_number;

    vector<string> stop_names(stops_number);
    for (auto &s : stop_names) {
      cin >> s;
    }

    if (stops_to_buses.count(stop_names)) {
      std::cout << "Already exists for " << stops_to_buses[stop_names] << std::endl;
    } else {
      const int bus_route = static_cast<const int>(stops_to_buses.size() + 1);
      stops_to_buses[stop_names] = bus_route;
      std::cout << "New bus " << bus_route << std::endl;
    }
  }
}