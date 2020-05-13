#ifndef the_double_hashing
#ifndef I_HASH
#define I_HASH
#include "I_hash.h"
#endif // !I_hash
#endif // !the_double_hashing

class the_double_hashing : public I_hash
{
private:
	int DoubleHashing(int);
	void Add(int, std::string);
public:
	void DoubleSeq();
};
