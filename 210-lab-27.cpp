// COMSC-210 | Lab 27 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <map>
#include <vector>
#include <string> 
using namespace std;


int menu_select(); 
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);
void searchFriendship(map<string, tuple<int, string, string>>&);
void addVillager(map<string, tuple<int, string, string>>&);
void removeVillager(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerInfo;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerInfo["Audie"] = {4, "Alligator", "Snap to It!"};
    villagerInfo["Raymond"] = {10, "Wolf", "Hubba hubba!"};
    villagerInfo.insert({"Marshal", {8, "Cat", "Nice fit"}});
    cout << endl;
    int menuChoice = menu_select(); 
    while (menuChoice != 6) { 
        if(menuChoice == 1) { 
            addVillager(villagerInfo);
        } else if (menuChoice == 2) { 
            removeVillager(villagerInfo);
        } else if (menuChoice == 3) { 
            increaseFriendship(villagerInfo);
        } else if(menuChoice == 4) { 
            decreaseFriendship(villagerInfo);
        } else if (menuChoice == 5) { 
            searchFriendship(villagerInfo);
        }

        // access the map using a range-based for loop
        cout << endl << "Villagers details: " << endl;
        for (auto pair : villagerInfo) {
            cout << pair.first << " [";
            cout << get<0>(pair.second) << ", "
                << get<1>(pair.second) << ", "
                << get<2>(pair.second) << "]";  
            cout << endl;
        }

        cout << endl;
        menuChoice = menu_select(); 
    }
    return 0;
}

int menu_select() {
    int decision; 
    cout << "1. Add Villager" << endl 
         << "2. Delete Villager" << endl 
         << "3. Increase Friendship" << endl
         << "4. Decrease Friendship" << endl
         << "5. Search for Villager" << endl  
         << "6. Exit" << endl; 
    cout << "Choice -> ";
    cin >> decision; 
    return decision; 
}  

void increaseFriendship(map<string, tuple<int, string, string>>& villagerInfo) { 
    for (auto& pair : villagerInfo) {
        get<0>(pair.second) += 1;
    }
}

void decreaseFriendship(map<string, tuple<int, string, string>>& villagerInfo) { 
    for (auto& pair : villagerInfo) {
        if(get<0>(pair.second) >= 1) { 
            get<0>(pair.second) -= 1; 
        } 
    }
}
   
void searchFriendship(map<string, tuple<int, string, string>>& villagerInfo) { 
    string searchKey;
    cout << "Who do you want to search for: ";
    cin >> searchKey; 
    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {  // the iterator points to beyond the end of the map
                                    // if searchKey is not found
        cout << "\nFound " << searchKey << ": ";
        cout << it->first << "[ ";
        cout << get<0>(it->second) << " "
            << get<1>(it->second) << " "
            << get<2>(it->second) << " ]";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;
}

void addVillager(map<string, tuple<int, string, string>>& villagerInfo) {
    string name, species, catchphrase; 
    int friendshipLevel; 
    cout << "Villager name: "; 
    cin >> name; 
    cout << "Friendship level: "; 
    cin >> friendshipLevel; 
    cout << "Species: "; 
    cin >> species; 
    cout << "Catchprase: "; 
    cin.ignore();
    getline(cin, catchphrase);

    villagerInfo.insert({name, {friendshipLevel, species, catchphrase}});
    cout << name << " added." << endl; 
}

void removeVillager(map<string, tuple<int, string, string>>& villagerInfo) {
    string removeKey; 
    cout << "Villager name to remove: "; 
    cin >> removeKey; 
    villagerInfo.erase(removeKey);
}
