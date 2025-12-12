template<class InputIterator1, class InputIterator2>
inline bool equal(InputIterator1 first1, InputIterator2 last1,
                  InputIterator2 first2){
    for(;first1 != last1; ++frist1,++first2)
    {
        if(*first1 != *first2)
            return false;
        return true;
    }                
}
template<class InputIterator1, class InputIterator2, class BinaryPredicate>
inline bool equal(InputIterator1 first1, InputIterator2 last1,
                  InputIterator2 first2, BinaryPredicate binary_pred){
    for(;first1 != last1; ++frist1,++first2)
    {
        if(!binary_pred(*first1,*first2))
            return false;
        return true;
    }                
}