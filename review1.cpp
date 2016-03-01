#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
#include<list>
using namespace std;

template<typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator copy_if_not(InputIterator first, InputIterator last, OutputIterator result, Predicate f)
{
	// while start iterator is not equal to the end iterator
	while(first != last)
	{
		// if the function passed is does not return true
		if(!f(*first))
		{
			*result++ = *first; //increment the position of result and assign the 
		}
		++first;
	}
	return result;
}

bool is_even(int n)
{
	return n % 2 == 0;
}

pair<vector<int>, vector<int>> partition(const vector<int>& v, bool (*f)(int))
{
	pair<vector<int>, vector<int>> pairv;
	
	for(auto& x : v)
	{
		if(f(x))
		{
			pairv.first.push_back(x);
		}
		
		if(!f(x))
		{
			pairv.second.push_back(x);
		}
	}
	return pairv;
}

template<typename Container>
void print(Container& c)
{
	for(auto&x : c)
	{
		cout << x << " ";
	}
	cout << endl;
}

struct shit {
	size_t less0 	= 0;
	size_t great100 = 0;
	
	void operator()(int& x)
	{
		if(x < 0)
			less0++;
			
		if(x > 100)
			great100++;	
	}
};

int main() {
	vector<int> v{3,2,7,6,8};
	list<int> lst{10,11,12,13,14,15};
	
/* 	//Question 1a
	cout << "Question #1" << endl;
	copy(v.begin() + 3, v.end(), ostream_iterator<int>(cout, "\n")); */
	
/*	//Question 1b
	//cout << "Question #2" << endl;
	//copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, " "));
	//cout << endl; */
	
/* 	//Question #c
	copy(lst.begin(), lst.end(), v.begin() + 2);
	
	for(auto& x : v)
	{
		cout << x << " ";
	}
	cout << endl; */
	
	//Question 1d
/*	cout << "Question #1d" << endl;
	copy(lst.begin(), lst.end(), inserter(v, v.begin() + 2));
	
	for(auto& x : v)
	{
		cout << x << " ";
	}
	cout << endl; */
	 
/* 	 //Question 1e
	 sort(v.begin(), v.end(), [](int a, int b){return a > b;});
	 print(v); */
	 
/* 	 //Question 1f
	 transform(lst.begin(), lst.end(), back_inserter(v), [](int a){return 3 * a;});
	 print(v); */
	 
/* 	 //Question 1g
	 v.erase(remove_if(v.begin(), v.end(), [](int a){ return a < 5 ;}), v.end());
	 print(v); */
	 
	 /* //Question 1h
	 auto x = for_each(v.begin(), v.end(), shit());
	 cout << "The numbers less than 0: " << x.less0 << " The numbers greater than 100: " << x.great100; */
	 
/* 	 //Question 2
	 auto it = copy_if_not(v.begin(), v.end(), lst.begin(), [](int n) {return n % 3 == 0;});
	 print(lst);
	 cout << *it << endl;  */
	 
/* 	 //Question 3
	 pair<vector<int>, vector<int>> p = partition(v, is_even);
	 
	 print(p.first);
	 print(p.second); */
}