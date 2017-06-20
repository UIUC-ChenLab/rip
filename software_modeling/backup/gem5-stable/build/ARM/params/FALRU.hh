#ifndef __PARAMS__FALRU__
#define __PARAMS__FALRU__

class FALRU;


#include "params/BaseTags.hh"

struct FALRUParams
    : public BaseTagsParams
{
    FALRU * create();
};

#endif // __PARAMS__FALRU__
