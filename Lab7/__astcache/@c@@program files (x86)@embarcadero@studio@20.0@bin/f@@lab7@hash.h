// ---------------------------------------------------------------------------

#include "Stack.h"
#include <ctime>

#ifndef HashH
#define HashH

class Hash
{
public:
	int size;
	Stack* Table;
	int GetHash(int x)
	{
		return (x % size);
	}

public:

	Hash(int x)
	{
		size = x;
		Table = new Stack[size];
		if (!Table) throw 42;
	}

	~Hash()
	{
		clear();
		delete[] Table;
	}

	void clear()
	{
		for (int i = 0; i < size; i++)
		{
			Table[i].clear();
		}
	}

	void insert(int x)
	{
		int ind = GetHash(x);
		Table[ind].push_back(IntToStr(x), x);
	}

	void erase(int x)
	{
		int ind = GetHash(x);
		Table[ind].pop_back(x);
	}


	AnsiString contain(int x)
	{
		int ind = GetHash(x);
		Stack y = Table[ind];
		return y.find(x);
	}

	void Randomize()
	{
			srand(time(NULL));
			int x;
			x = rand();
			insert(x);
	}
};

// ---------------------------------------------------------------------------
#endif
