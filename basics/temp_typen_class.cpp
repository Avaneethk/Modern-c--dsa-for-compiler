template <class LookupKeyT> //here class is same as typename 
  //nodiscard is c++17 attribute it tell compiler ""The return value is important. Don't ignore it.""
  /*
[[nodiscard]]
int add(int a,int b)
{
    return a+b;
}
add(2,3); //compiler errors out here telling that return type cannot be ignored

This is a generic read-only lookup function that accepts any lookup key by const reference, promises not to modify the map, and returns a const iterator whose value should not be ignored.
  */
  //here the return type const_iterator 
  [[nodiscard]] const_iterator find_as(const LookupKeyT &Val) const {
    if (const BucketT *Bucket = doFind(Val))
      return makeConstIterator(Bucket);
    return end();
  }