#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Packers {
  public:
  
    
    static Packers *make_game(string choice);
  
    
    virtual void Score() = 0;
    
   
    virtual ~Packers() = default;
};

class FirstGame: public Packers {
  public:
    void Score() {
        cout << "Packers vs. Vikings \n";
        cout << "Packers won \n";
    }
};

class SecondGame: public Packers {
  public:
    void Score() {
        cout << "Packers vs. Lions\n";
        cout << "Packers Won \n";
    }
};

class ThirdGame: public Packers {
  public:
    void Score() {
       cout << "Packers vs. Saints\n";
        cout << "Packers Won \n";
    }
};

class ForthGame: public Packers {
  public:
    void Score() {
        cout << "Packers vs. Falcon\n";
        cout << "Packers Won \n";
    }
};

class FifthGame: public Packers {
  public:
    void Score() {
        cout << "Packers vs. Buccaneers\n";
        cout << "Packers Lost, Feels Bad\n";
    }
};



Packers *Packers::make_game(string choice) {
  if (choice ==  "First")
    return new FirstGame;
  else if (choice == "Second")
    return new SecondGame;
  else if (choice == "Third")
    return new ThirdGame;
   else if (choice == "Forth")
    return new ForthGame;
  else 
    return new FifthGame;
}


 

int main() {

  vector<Packers*> products;

  string choice;

  while (true) {

    cout << "Da Packers game Eh? ";

    cin >> choice;

    if (choice == "0") break;
    
    products.push_back(Packers::make_game(choice));
  }
  for (int i = 0; i < products.size(); i++) {
    products[i]->Score();
  }
  for (int i = 0; i < products.size(); i++) {
    delete products[i];
  }
}