#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Member {
   public:
      Member();
      Member(string memberName, int memberAge);
      Member(string memberName, int memberAge, double memberHeight);
      void Print();
   
   private:
      string name;
      int age;
      double height;
};

Member::Member() {
   name = "Undefined";
   age = -1;
   height = 0.0;
}

Member::Member(string memberName, int memberAge) {  
   name = memberName;
   age = memberAge;
   height = 0.0;
}

Member::Member(string memberName, int memberAge, double memberHeight) {  
   name = memberName;
   age = memberAge;
   height = memberHeight;
}

void Member::Print() {
   cout << fixed << setprecision(2) << "Member: " << name << ", " << age << ", " << height << endl;
}

int main() {
   string memberName;
   int memberAge;
   double memberHeight;
   
   cin >> memberName;
   cin >> memberAge;
   cin >> memberHeight;

   /* Your code goes here */
   Member member1();
   Member member2(memberName, memberAge);
   Member member3(memberName, memberAge, memberHeight);

   member1.Print();
   member2.Print();
   member3.Print();
   
   return 0;
}