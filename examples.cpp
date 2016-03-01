#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<sstream>
#include<iterator>
#include<algorithm>
#include<cstdlib>
#include<list>
#include<map>

using namespace std;

//tokenizer.cpp

//string next_token(const string& s, const string& delim, string::size_type& start);

/* int main()
{
	string tok;
	const string input = ":ab.cde;fg,hi:";
	const string delim = ".:,;";
	string::size_type start = 0;
	
	while(!(tok = next_token(input, delim, start)).empty())
	{
		cout << tok << endl;
	}
}

string next_token(const string& s, const string& delim, string::size_type& start)
{
	string::size_type pos = s.find_first_not_of(delim,start);
	if(pos == string::npos)
	{
		return "";
	}
	
	start = s.find_first_of(delim, pos);
	return s.substr(pos, start - pos);
}
 */



// Merge_sort.cpp

// function will take in two vectors and do a merge sort on them and return 1 new vector
/* vector<int> merge(const vector<int>& v1, const vector<int>& v2)
{
	vector<int> result;
	vector<int>::size_type i1 = 0, i2 = 0, n1 = v1.size(), n2 = v2.size();
	result.reserve(n1 + n2); // allocates the size of both the two vectors in memory for result
	
	// keeps going as long as both vectors still have elements in them
	while(i1 < n1 && i2 < n2)
	{
		result.push_back(v1[i1] < v2[i2] ? v1[i1++]:v2[i2++]);
	}
	
	// if second vector is empty copy rest of first vector to result
	while(i1 < n1)
	{
		result.push_back(v1[i1++]);
	}
	
	// if first vector is empty copy rest of second vector to result
	while(i2 < n2)
	{
		result.push_back(v2[i2++]);
	}
	
	return result;
}

vector<int> mergesort(const vector<int>& v)
{
	auto sz = v.size();
	if(sz <= 1)
	{
		return v;
	}
	return merge(mergesort(vector<int>
							(v.begin(), v.begin() + sz/2)),
				mergesort(vector<int>
							(v.begin() + sz/2, v.end())));
}

int main()
{
	vector<int> v1 {1,4,7,11}, v2{2,3,6,13};
	vector<int> v {1,7,4,9,3,5,3,9};
	
	for(auto &x : mergesort(v))
	{
		cout << x << ' ';
	}
	cout << endl;
}  */

  
  
// playing with iterators

/* int main() {
	vector<int> p{1,2,4,5,33,2,3,5};
	vector<int>::iterator i;
	i = p.begin();
	*(i+1) = 77;
	vector<int> *q = &p;
	
	for(i = p.begin(); i != p.end(); i++)
	{
		cout << *i << endl;
	}
} */

// Operator overloading and qsort with new pair type
/* vector<int> operator+(const vector<int>& v1, const vector<int>& v2)
{
	vector<int> result(v1);
	
	result.insert(result.end(), v2.begin(), v2.end());
	return result;
	
}

pair<vector<int>, vector<int>> partition(const vector<int>& v)
{
	pair<vector<int>, vector<int>> result;
	int pivot = v[0];
	
	for(vector<int>::size_type i = 1; i < v.size(); i++)
	{
		if(v[i] < pivot)
		{
			result.first.push_back(v[i]);
		}
		else {
			result.second.push_back(v[i]);
		}
	}
	return result;
}

vector<int> qsort(const vector<int>& v)
{
	if(v.size() <= 1)
	{
		return v;
	}
	
	pair<vector<int>, vector<int>> p = partition(v);
	return qsort(p.first) + vector<int>(1, v[0]) + qsort(p.second);
} 

int main()
{
	vector<int> v1{3,2,7,6,8,6,5,5,3,6};
	vector<int> v2{6,5,5,3,6};
	
	for(auto& x : qsort(v1))
	{
		cout << x << ' ';
	}
	cout << endl;
} */


// using lambda annoyomous functions
/* int main()
{
	int a[100];
	generate_n(a, 100, [](){return rand() % 100;});
	sort(a, a + 100, [](int a, int b) {return a > b;});
	
	for(size_t i = 0; i < 100; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	
	cout << is_sorted(a, a+100) << endl;
} */


/* template<typename Iterator>
pair<Iterator, Iterator> my_partition(Iterator first, Iterator last)
{
	auto pivot = *first; // value of the first position of the vector, array, container ect
	Iterator less_end = first,
			 equal_end = first,
			 greater_beg = last;
			 
	while(equal_end != greater_beg) // while the address of the first element is not the same as the last element
	{
		if(*equal_end < pivot) // if value of equal end is less that value of firs element
		{
			swap(*equal_end++, *less_end++); // swaps 
		} else if (*equal_end == pivot) {
			++equal_end;
		} else {
			swap(*--greater_beg, *equal_end);
		}
	}
	return {less_end, equal_end};
}
 
template<typename Iterator>
void qsort(Iterator first, Iterator last)
{
	if(distance(first, last) <= 1)
	{
		return;
	}
	
	auto p = my_partition(first, last);
	qsort(first, p.first);
	qsort(p.second, last);
}

int main() {
	list<int> lst{3,2,7,6,8};
	qsort(lst.begin(), lst.end());
	cout << is_sorted(lst.begin(), lst.end()) << endl;
	
	int a[] = {3, 2, 7, 6, 8};
	qsort(a, a + 5);
	cout << is_sorted(a, a + 5) << endl;
} */


// playing with maps and understand them finally
/* string find_by_seq(const map<int,string>& m, int seqno)
{
	//map<int,string>::Iternator p;
	auto p = m.find(seqno);
	
	if(p != m.end())
	{
		return p->second;
	}
	return "hell";
}

int main() {
	string name;
	map<string,int> m = {{"BoB", 22}, {"Turtle", 33}, {"England", 99}};
	
	cout << "Enter a name to find: " << endl;
	
	while(cin >> name) {
		auto p = m.find(name);
		if(p != m.end()) 
		{
			cout << name << ": " << m[name] << endl;
		} else {
			cout << name << " was not found" << endl;
		}
	}
} */

int main() {
	string s, s1("hello mello pelloiu"), s2("world");
	
	//s1.insert(5, " cruel "); // we can do 5 cause cause there is the \0 char at pos 5
	
	
	//cout << s1.find_last_of("ello") << endl;
	s1.resize(7, 'm');
	
	cout << s1 << endl;
}