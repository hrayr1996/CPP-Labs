#include <iostream>

class Array {

    private:
        int _count  = 0;
        long _pos   = 0;
        char* _arr;
        char* _types;
        const int TYPE_INT=0,
                TYPE_STRING = 1,
                TYPE_ARRAY = 2;


    public:

        int count()
        {
            return _count;
        }

        Array()
        {
            _arr = new char[1];
            _types = new char[1];
        }

        bool push(int element)
        {
            _types[_count] = 
            _count++;
            return true;
        }

        bool push(char* element)
        {
            _types[_count] = 
            _count++;
            return true;
        }

        bool push(long element)
        {
            _types[_count] = 
            _count++;
            return true;
        }

        bool push(bool element)
        {
            _types[_count] = 
            _count++;
            return true;
        }

        bool push(Array element)
        {
            _types[_count] = 
            _count++;
            return true;
        }

        
/* 
        bool push(void* element)
        {
            _types[_count] = ;
            _count++;
            return true;
        } */
};