class solution{
public:
vector<int> twosum(vector<int> &nums,int target)
{
  vector<int> index;
  for(auto it = nums.begin();it!=nums.end();it++)
{
  for(auto it1=it+1;it1!=nums.end();it1++)
{
int sum = *it + *it1;
if(sum==target)
{
int a = distance(nums.begin(),it);
int b = distance(nums.begin(),it1);
index.push_back(a);
index.push_back(b);
}
}
}
return index;
}
