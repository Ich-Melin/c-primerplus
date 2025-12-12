template <class ForwardIterator1, class ForwardIterator2>
inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b){
    _iter_swap(a,b,value_type(a));
}

template<class ForwardIteartor1, class ForwardIterator2, class T>
inline void _iter_swap(ForwardIteartor1 a, ForwardIterator2 b, T*){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<class Iterator>
inline typename iterator_traites<Iterator>::value_type*
value_type(const Iterator&){
    return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
}