#include"ThiSinh.h"
class node
{
public:
    ThiSinh data;
    node *next;
    node(ThiSinh ts)
    {
        data = ts;
        next = NULL;
    }
};
