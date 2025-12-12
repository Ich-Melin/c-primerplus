template<class InputIterator>
inline iterator_traits<InputIterator>::difference_type
distance(InputIterator frist, InputIterator last) {
    typedef typename iterator_traits<InputIterator>::iterator_category category;
    return _distance(frist,last,category());9
}