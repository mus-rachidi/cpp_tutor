#include <iostream>
#include <map>

int main ()
{
	{
		std::cout<<"----------------------------------------------\n";
		std::cout<<"                constructor                    \n";
		std::cout<<"------------------------------------------------\n";
		std::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::map<char,int> second (first.begin(),first.end());
		std::map<char,int> third (second);
	}
	{
		std::cout<<"----------------------------------------------\n";
		std::cout<<"                empty                          \n";
		std::cout<<"------------------------------------------------\n";

		std::map<char,int> mymap;
		mymap['a']=10;
		mymap['a']=101;
		mymap['b']=20;
		mymap['b']=200;
		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	{
		std::cout<<"----------------------------------------------\n";
		std::cout<<"                size                           \n";
		std::cout<<"------------------------------------------------\n";

		std::map<char,int> mymap1;
		mymap1['a']=101;
		mymap1['b']=202;
		mymap1['c']=302;
		std::cout << "mymap.size() is " << mymap1.size() << '\n';
	}
	{
		std::cout<<"----------------------------------------------\n";
		std::cout<<"                max_size                       \n";
		std::cout<<"------------------------------------------------\n";

		int i;
		std::map<int,int> mymap12;

		if (mymap12.max_size()>1000)
		{
			for (i=0; i<1000; i++) 
			mymap12[i]=0;
			std::cout << "The map contains 1000 elements.\n";
		}
		else 
			std::cout << "The map could not hold 1000 elements.\n";
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                operator[]                       \n";
		std::cout<<"--------------------------------------------------\n";

		std::map<char,std::string> mymap3;
		mymap3['a'] = "an element";
		mymap3['b'] = "another element";
		mymap3['c'] = mymap3['b'];

		std::cout << "mymap['a'] is " << mymap3['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap3['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap3['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap3['d'] << '\n';
		std::cout << "mymap now contains " << mymap3.size() << " elements.\n";
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                at                               \n";
		std::cout<<"--------------------------------------------------\n";

		std::map<std::string,int> mymap4;
		mymap4["alpha"] = 0;
		mymap4["beta"] = 0;
		mymap4["gamma"] = 0;
		mymap4.at("alpha") = 10;
		mymap4.at("beta") = 20;
		mymap4.at("gamma") = 30;
		for (std::map<std::string, int>::iterator it = mymap4.begin(); it != mymap4.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                insert                           \n";
		std::cout<<"--------------------------------------------------\n";
		
		std::map<char,int> mymap5;
		mymap5.insert ( std::pair<char,int>('a',100) );
		mymap5.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap5.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) 
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		std::map<char,int>::iterator it = mymap5.begin();
		mymap5.insert (it, std::pair<char,int>('b',300));  
		mymap5.insert (it, std::pair<char,int>('c',400));

		std::map<char,int> anothermap;
		anothermap.insert(mymap5.begin(),mymap5.find('c'));

		std::cout << "mymap contains:\n";
		for (it=mymap5.begin(); it!=mymap5.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                erase                            \n";
		std::cout<<"--------------------------------------------------\n";

		std::map<char,int> mymap6;
		std::map<char,int>::iterator it1;

		mymap6['a']=10;
		mymap6['b']=20;
		mymap6['c']=30;
		mymap6['d']=40;
		mymap6['e']=50;
		mymap6['f']=60;

		it1=mymap6.find('b');
		mymap6.erase (it1);                  
		mymap6.erase ('c');     
		it1=mymap6.find ('e');
		mymap6.erase ( it1, mymap6.end() ); 

		for (it1=mymap6.begin(); it1 != mymap6.end(); ++it1)
			std::cout << it1->first << " => " << it1->second << '\n';
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                swap                             \n";
		std::cout<<"--------------------------------------------------\n";

		std::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		foo.swap(bar);
		std::cout << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                clear                            \n";
		std::cout<<"--------------------------------------------------\n";

		std::map<char,int> mymap7;
		mymap7['x']=100;
		mymap7['y']=200;
		mymap7['z']=300;
		std::cout << "mymap contains:\n";
		for (std::map<char,int>::iterator it = mymap7.begin(); it != mymap7.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		mymap7.clear();
		mymap7['a']=1101;
		mymap7['b']=2202;
		std::cout << "mymap contains:\n";
		for (std::map<char,int>::iterator it = mymap7.begin(); it != mymap7.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                key_compare                      \n";
		std::cout<<"--------------------------------------------------\n";

		std::map<char,int> mymap8;
		std::map<char,int>::key_compare mycomp8 = mymap8.key_comp();
		mymap8['a']=300;
		mymap8['b']=300;
		mymap8['c']=300;
		std::cout << "mymap contains:\n";
		char highest = mymap8.rbegin()->first;
		std::cout << "highest = "<< highest<<std::endl;
		std::map<char,int>::iterator it3 = mymap8.begin();
		while ( mycomp8((*it3).first, highest) )
		{
			std::cout << it3->first << " => " << it3->second << '\n';
			*it3++;
		}
		std::cout << '\n';	
	}


	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                value_compare                    \n";
		std::cout<<"--------------------------------------------------\n";

		std::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=1001;
		mymap['z']=1001;
		std::cout << "mymap contains:\n";
		std::pair<char,int> highest = *mymap.rbegin();
		std::map<char,int>::iterator it = mymap.begin();
		while ( mymap.value_comp()(*it, highest) )
		{
		std::cout << it->first << " => " << it->second << '\n';
		*it++;
		} 
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                find                             \n";
		std::cout<<"--------------------------------------------------\n";
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
		mymap.erase (it);

		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"                count                            \n";
		std::cout<<"--------------------------------------------------\n";
			std::map<char,int> mymap;
			char c;

			mymap ['a']=101;
			mymap ['c']=202;
			mymap ['f']=303;

			for (c='a'; c<'h'; c++)
			{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
			}
	}
	{
		std::cout<<"------------------------------------------------\n";
		std::cout<<"           lower_bound() and upper_bound()       \n";
		std::cout<<"--------------------------------------------------\n";

		std::cout << "\n\nWelcome to Studytonight :-)\n\n\n";
		std::cout << " =====  Program to demonstrate the lower_bound() and upper_bound() in Map, in CPP  ===== \n\n\n";
		std::map<int, int> m;
		m.insert(std::make_pair(3, 30));
		m.insert(std::make_pair(2, 20));
		m.insert(std::make_pair(5, 50));
		m.insert(std::make_pair(9, 90));
		m.insert(std::make_pair(1, 10));
		std::cout << "\n\nThe number of elements in the Map are: " << m.size();
		std::cout << "\n\nThe elements of the Map m are: ";
		std::map<int, int>::iterator i;
		for (i = m.begin(); i != m.end(); i++)
		{
			std::cout << "( " << i->first << ", " << i->second << " ) ";
		}

		std::map<int, int>::iterator low, high;
		low = m.lower_bound(5);
		std::cout << "\n\nThe lower bound of 5 has key: " << low->first << " and value: " << low->second << ". ";
		low = m.lower_bound(6);
		std::cout << "\n\nThe lower bound of 6 has key: " << low->first << " and value: " << low->second << ". ";
		high = m.upper_bound(3);
		std::cout << "\n\nThe upper bound of 3 has key: " << high->first << " and value: " << high->second << ". ";
		high = m.upper_bound(4);
		std::cout << "\n\nThe upper bound of 4 has key: " << high->first << " and value: " << high->second << ". ";
		std::cout << "\n\n\n";
	}
  return 0;
}