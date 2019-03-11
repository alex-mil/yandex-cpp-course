#include <iostream>
#include <map>
#include <vector>
using namespace std;

void BusStops1() {
  int q;
  cin >> q;

  map<string, vector<string>> buses_map;
  map<string, vector<string>> stops_map;
  for (int i = 0; i < q; ++i) {
    string command;
    cin >> command;

    if (command == "NEW_BUS") {
      string bus, stop_name;
      int stop_count;
      cin >> bus >> stop_count;

      for (int j = 0; j < stop_count; ++j) {
        cin >> stop_name;
        buses_map[bus].push_back(stop_name);
        stops_map[stop_name].push_back(bus);
      }
    } else if (command == "BUSES_FOR_STOP") {
      string stop_name;
      cin >> stop_name;

      if (stops_map.count(stop_name)) {
        for (const auto &bus : stops_map[stop_name]) {
          cout << bus << " ";
        }
        cout << endl;
      } else {
        std::cout << "No stop" << std::endl;
      }
    } else if (command == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;

      if (buses_map.count(bus)) {
        for (const auto &s : buses_map[bus]) {
          std::cout << "Stop " << s << ": ";
          if (stops_map[s].size() == 1) {
            std::cout << "no interchange" << std::endl;
            continue;
          }

          for (const auto &b : stops_map[s]) {
            if (b == bus) continue;
            std::cout << b << " ";
          }
          std::cout << std::endl;
        }
      } else {
        std::cout << "No bus" << std::endl;
      }
    } else if (command=="ALL_BUSES") {
      if (buses_map.empty()) {
        std::cout << "No buses" << std::endl;
        continue;
      }
      for (const auto &item : buses_map) {
        std::cout << "Bus " << item.first << ": ";
        for (const auto &stop : item.second) {
          std::cout << stop << " ";
        }
        std::cout << std::endl;
      }
    }
  }
}

// ответ на запрос BUSES_FOR_STOP
void PrintBusesForStop(map<string, vector<string>>& stops_to_buses,
                       const string& stop) {
  if (stops_to_buses.count(stop) == 0) {
    cout << "No stop" << endl;
  } else {
    for (const string& bus : stops_to_buses[stop]) {
      cout << bus << " ";
    }
    cout << endl;
  }
}

// ответ на запрос STOPS_FOR_BUS
void PrintStopsForBus(map<string, vector<string>>& buses_to_stops,
                      map<string, vector<string>>& stops_to_buses,
                      const string& bus) {
  if (buses_to_stops.count(bus) == 0) {
    cout << "No bus" << endl;
  } else {
    for (const string& stop : buses_to_stops[bus]) {
      cout << "Stop " << stop << ": ";

      // если через остановку проходит ровно один автобус,
      // то это наш автобус bus, следовательно, пересадки тут нет
      if (stops_to_buses[stop].size() == 1) {
        cout << "no interchange";
      } else {
        for (const string& other_bus : stops_to_buses[stop]) {
          if (bus != other_bus) {
            cout << other_bus << " ";
          }
        }
      }
      cout << endl;
    }
  }
}

// ответ на запрос ALL_BUSES
void PrintAllBuses(const map<string, vector<string>>& buses_to_stops) {
  if (buses_to_stops.empty()) {
    cout << "No buses" << endl;
  } else {
    for (const auto& bus_item : buses_to_stops) {
      cout << "Bus " << bus_item.first << ": ";
      for (const string& stop : bus_item.second) {
        cout << stop << " ";
      }
      cout << endl;
    }
  }
}

void BusStop2() {
  int q;
  cin >> q;

  map<string, vector<string>> buses_to_stops, stops_to_buses;
  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "NEW_BUS") {
      string bus;
      cin >> bus;
      int stop_count;
      cin >> stop_count;

      // с помощью ссылки дадим короткое название вектору
      // со списком остановок данного автобуса;
      // ключ bus изначально отсутствовал в словаре, поэтому он автоматически
      // добавится туда с пустым вектором в качестве значения
      vector<string>& stops = buses_to_stops[bus];
      stops.resize(stop_count);
      for (string& stop : stops) {
        cin >> stop;
        // не забудем обновить словарь stops_to_buses
        stops_to_buses[stop].push_back(bus);
      }
    } else if (operation_code == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      PrintBusesForStop(stops_to_buses, stop);
    } else if (operation_code == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      PrintStopsForBus(buses_to_stops, stops_to_buses, bus);
    } else if (operation_code == "ALL_BUSES") {
      PrintAllBuses(buses_to_stops);
    }
  }
}