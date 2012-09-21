#ifndef _SORT_FUNCTORS_HPP_
#define _SORT_FUNCTORS_HPP_
#pragma once
#include <cassert>

template <class RandomIterType, class Comparator = std::less<RandomIterType::value_type>>
class InsertSortFunctor
{
	Comparator cmp;
public:
	typedef RandomIterType IterType;
	void operator() (IterType _First, IterType _Last/*, Comparator& cmp*/)
	{
		assert(_First != _Last);
		IterType curLastIter = _First+1;
		while (curLastIter != _Last)
		{
			IterType curIter = curLastIter;
			IterType::value_type val = *curIter;
			while (curIter != _First && cmp(val, *(curIter-1))) {
				*curIter = *(curIter-1);
				--curIter;
			}
			*curIter = val;
			++curLastIter;
		}
		return;
	}
};

template <class RandomIterType, class Comparator>
void InsertSortFunction(RandomIterType _First, RandomIterType _Last, Comparator cmp)
{
	assert(_First != _Last);
	RandomIterType curLastIter = _First+1;
	while (curLastIter != _Last)
	{
		RandomIterType curIter = curLastIter;
		RandomIterType::value_type val = *curIter;
		while (curIter != _First && cmp(val, *(curIter-1))) {
			*curIter = *(curIter-1);
			--curIter;
		}
		*curIter = val;
		++curLastIter;
	}
	return;
};

#endif