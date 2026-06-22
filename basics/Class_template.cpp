#include<iostream>
using namespace std;

//template<typename K , typename V>
template<class K , class V>
class Pair{
    K key;
    V val;

 public:
    Pair(K k,V v):key(k),val(v){} //constructor/member initializer list
    K getKey() const {cout<<"key:"<<key<<endl;return key;}
    V getValue() const {cout<<"val:"<<val<<endl;return val;}
};

int main()
{
    Pair p ("age",30);
    p.getKey();
    p.getValue();
    return 0;
}