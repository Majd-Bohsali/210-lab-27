#include <iostream>
#include <map>
#include <vector>
using namespace std;


int menu_select(); 
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);
void searchFriendship(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerInfo;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerInfo["Audie"] = {4, "Alligator", "Snap to It!"};
    villagerInfo["Raymond"] = {10, "Wolf", "Hubba hubba!"};
    villagerInfo.insert({"Marshal", {8, "Cat", "Nice fit"}});

    int menuChoice = menu_select(); 
    while (menuChoice != 4) { 
        if(menuChoice == 1) { 
            increaseFriendship(villagerInfo);
        } else if (menuChoice == 2) { 
            decreaseFriendship(villagerInfo);
        } else if (menuChoice == 3) { 
            searchFriendship(villagerInfo); 
        }


        // access the map using a range-based for loop
        cout << endl << "Villagers and their favorite colors (range-based for loop):" << endl;
        for (auto pair : villagerInfo) {
            cout << pair.first << "[ ";
            cout << get<0>(pair.second) << " "
                << get<1>(pair.second) << " "
                << get<2>(pair.second) << " ]";  
            cout << endl;
        }
        menuChoice = menu_select(); 
        /*
        // access the map using iterators
        cout << "\nVillagers and their favorite colors (iterators):" << endl;
        for (map<string, tuple<int, string, string>>::iterator it = villagerInfo.begin(); 
                                                it != villagerInfo.end(); ++it) {
            cout << it->first << "[ ";
            cout << get<0>(it->second) << " "
                << get<1>(it->second) << " "
                << get<2>(it->second) << " ]";
            cout << endl;
        }

        // delete an element
        villagerInfo.erase("Raymond");

        // search for an element using .find() to avoid errors
        string searchKey = "Audie";
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

        // report size, clear, report size again to confirm map operations
        cout << "\nSize before clear: " << villagerInfo.size() << endl;
        villagerInfo.clear();
        cout << "Size after clear: " << villagerInfo.size() << endl;
        */
    }
    return 0;
}

int menu_select() {
    int decision; 
    cout << "1. Increase Friendship" << endl
         << "2. Decrease Friendship" << endl
         << "3. Search for Villager" << endl  
         << "4. Exit" << endl; 
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

}
