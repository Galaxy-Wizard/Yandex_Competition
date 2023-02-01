#include <iostream>

#include <string>
#include <list>
#include <map>
#include <set>

/*/    Tree Template (start)    /*/

namespace galaxy
{

	template<class T>
	class galaxy_tree
	{
	public:
		galaxy_tree();
		std::list<galaxy_tree>& get_childs();
		void set_data(T& p);
		T get_data();
		void set_leaf(bool p);
		bool get_leaf();
	protected:
		std::list<galaxy_tree> childs;
	private:
		bool leaf;
		T data;
	};

	template<class T>
	galaxy_tree<T>::galaxy_tree()
		: data(T()), leaf(true)
	{
	}

	template<class T>
	std::list<galaxy_tree<T>>& galaxy_tree<T>::get_childs()
	{
		return childs;
	}

	template<class T>
	void galaxy_tree<T>::set_data(T& p)
	{
		data = p;
	}

	template<class T>
	T galaxy_tree<T>::get_data()
	{
		return data;
	}

	template<class T>
	void galaxy_tree<T>::set_leaf(bool p)
	{
		leaf = p;
	}

	template<class T>
	bool galaxy_tree<T>::get_leaf()
	{
		return leaf;
	}
};

/*/    Tree Template (finish)    /*/

int main()
{
	bool input_error = false;

	std::string input_array;

	galaxy::galaxy_tree<int> input_sequence;

	std::cout << "Enter array:" << std::endl;

	std::getline(std::cin, input_array);

	std::list<int> source_list;


	bool negative = false;
	int current_number = 0;
	int radix = 10;

	bool number_started = false;

	for (size_t counter = 0; counter < input_array.size(); counter++)
	{
		if (input_array[counter] == '[')
		{
			if (negative)
			{
				input_error = true;
				break;
			}

			negative = false;
			current_number = 0;

			number_started = false;
		}
		else if (input_array[counter] == '-')
		{
			negative = true;

			number_started = true;
		}
		else if (input_array[counter] == ',' || input_array[counter] == ']')
		{
			if (number_started)
			{
				if (negative)
				{
					current_number = -current_number;
				}

				source_list.push_back(current_number);
			}

			negative = false;
			current_number = 0;

			number_started = false;
		}
		else if (input_array[counter] == ' ')
		{
			number_started = false;
		}
		else
		{
			char digit = input_array[counter];
			int current_digit = -10;

			switch (digit)
			{
			case '0': current_digit = 0; break;
			case '1': current_digit = 1; break;
			case '2': current_digit = 2; break;
			case '3': current_digit = 3; break;
			case '4': current_digit = 4; break;
			case '5': current_digit = 5; break;
			case '6': current_digit = 6; break;
			case '7': current_digit = 7; break;
			case '8': current_digit = 8; break;
			case '9': current_digit = 9; break;
			case 'a':case 'A': current_digit = 10; break;
			case 'b':case 'B': current_digit = 11; break;
			case 'c':case 'C': current_digit = 12; break;
			case 'd':case 'D': current_digit = 13; break;
			case 'e':case 'E': current_digit = 14; break;
			case 'f':case 'F': current_digit = 15; break;
			case 'g':case 'G': current_digit = 16; break;
			case 'h':case 'H': current_digit = 17; break;
			case 'i':case 'I': current_digit = 18; break;
			case 'j':case 'J': current_digit = 19; break;
			case 'k':case 'K': current_digit = 20; break;
			case 'l':case 'L': current_digit = 21; break;
			case 'm':case 'M': current_digit = 22; break;
			case 'n':case 'N': current_digit = 23; break;
			case 'o':case 'O': current_digit = 24; break;
			case 'p':case 'P': current_digit = 25; break;
			case 'q':case 'Q': current_digit = 26; break;
			case 'r':case 'R': current_digit = 27; break;
			case 's':case 'S': current_digit = 28; break;
			case 't':case 'T': current_digit = 29; break;
			case 'u':case 'U': current_digit = 30; break;
			case 'v':case 'V': current_digit = 31; break;
			case 'w':case 'W': current_digit = 32; break;
			case 'x':case 'X': current_digit = 33; break;
			case 'y':case 'Y': current_digit = 34; break;
			case 'z':case 'Z': current_digit = 35; break;

			default:
				input_error = true;
			}

			if (input_error)
			{
				break;
			}

			number_started = true;

			current_number *= radix;
			current_number += current_digit;
		}
	}

	source_list.sort();

	std::cout << std::endl;

	std::multimap<int, int> result_map;

	int maximum_counter = 1;

	{
		auto i = source_list.begin();
		int current_number = *i;
		i++;
		int counter = 1;

		if (i != source_list.end())
		{
			for (; i != source_list.end(); i++)
			{
				if (current_number == *i)
				{
					counter++;

					if (counter > maximum_counter)
					{
						maximum_counter = counter;
					}
				}
				else
				{
					result_map.insert(std::make_pair(counter, current_number));					

					counter = 1;
					current_number = *i;
				}
			}

			result_map.insert(std::make_pair(counter, current_number));
		}
		else if (source_list.size() == 1)
		{
			auto i = source_list.begin();
			result_map.insert(std::make_pair(1, *i));
		}
	}

	{
		std::set<int> final_result;

		auto find_result = result_map.find(maximum_counter);

		if (find_result != result_map.end())
		{
			for (; find_result != result_map.end();)
			{
				final_result.insert(find_result->second);

				result_map.erase(find_result);

				find_result = result_map.find(maximum_counter);
			}
		}

		std::cout << std::endl;

		for (auto i = final_result.begin(); i != final_result.end(); i++)
		{
			std::cout << *i << ' ';
		}

		std::cout << std::endl;
	}

	if (input_error)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	return 0;
}