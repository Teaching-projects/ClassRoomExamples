#include <iostream>
#include <string>
using namespace std;

#include "Inventory.hpp"
#include "Sword.hpp"
#include "Shield.hpp"
#include "SpellBook.hpp"

#include "Printable.hpp"



int main(int argc, char** argv){

  Inventory inv(12);

  inv.put(new Sword(12,3,3.5));
  inv.put(new SpellScroll());
  inv.put(new Shield(12,12,5.5));
  auto book=new SpellBook(6);
  *book<<"Abrakadabra"<<"Csiribu";
  "Lumos">>*book;
  inv.put(book);

  for(int i=0; i<inv.count(); ++i){
    cout << "Item " << i << ": "<< inv.get(i) << endl;
  }
  

  cout << "Total weight: "<<inv.getTotalWeight()<<endl;
  cout << " - Wearables: "<<inv.getWeight<Wearable>()<<endl; 
  cout << "   - Swords: "<<inv.getWeight<Sword>()<<endl; 
  cout << "   - Shields: "<<inv.getWeight<Shield>()<<endl; 
  cout << " - SpellBooks: "<<inv.getWeight<SpellBook>()<<endl;
  

  

  return 0;
}
