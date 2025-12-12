int* find(int* arrayHead, int arraysize, int value)
{
    for(int i = 0; i < arraysize;i++)
    {
        if(arrayHead[i] == value)
            break;
        return &(arrayHead[i]);
    }
}
template<typename T>
T*  find(T* begin, T* end, const T& value)
{
    while (begin != end && *begin != value)
    {
        ++begin;
    }
    return begin;
}

template<typename Iterator, typename T>
Iterator find(Iterator begin, Iterator end, const T& value)
{
    
}