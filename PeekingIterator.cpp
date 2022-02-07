
#include<vector>
using namespace std;

class PeekingIterator : public Iterator {
public:

    unique_ptr<int> nextLoaded;

    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        if (Iterator::hasNext()) {
            this->nextLoaded = make_unique<int>(Iterator::next());
        }
    }

    int peek() {
        if (!hasNext()) {
            throw ("No Such Element Exception.");
        }
        return *nextLoaded;
    }

    int next() {
        if (!hasNext()) {
            throw ("No Such Element Exception.");
        }

        int temp = *nextLoaded;
        nextLoaded = nullptr;

        if (Iterator::hasNext()) {
            nextLoaded = make_unique<int>(Iterator::next());
        }
        return temp;
    }

    bool hasNext() const {
        return nextLoaded != nullptr;
    }
};

/*
 *  This is the Iterator's API interface. 
 *  It is implemented internally by leetcode.com.
 *  It should not be included in the code, when running it on the website.
 *
 *  class Iterator {
 *	struct Data;
 * 	Data* data;
 *  public:
 *	Iterator(const vector<int>& nums);
 * 	Iterator(const Iterator& iter);
 *
 * 	// Returns the next element in the iteration.
 *	int next();
 *
 *	// Returns true if the iteration has more elements.
 *	bool hasNext() const;
 *  };
 */
