#include <iostream>
#include <map>
#include <set>
using namespace std;

void BusesAndStops2() {
  int q;
  cin >> q;

  map<set<string>, int> stops_to_buses;
  for (int i = 0; i < q; ++i) {
    int n;
    cin >> n;

    set<string> stop_names;
    string stop_name;
    for (int j = 0; j < n; ++j) {
      cin >> stop_name;
      stop_names.insert(stop_name);
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