#ifndef I_HASH
#define I_HASH
#include "I_hash.h"
#endif // !I_hash

class the_quadratic_probing : public I_hash
{
private:
	void Add(int, std::string);
public:
	void QuadraticSeq();
};
