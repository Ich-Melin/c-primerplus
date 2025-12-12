template<typename InputIterator, typename T>
T accumulate(InputIterator frist, InputIterator last, T init)
{
    for(;frist != last; frist++)
        init = init + *frist;
    return init;
}

template<typename InputIterator, typename T,typename BinaryOperation>
T accumulate(InputIterator frist, InputIterator last, T init,BinaryOperation binary_op)
{
    for(;frist != last; frist++)
        init = binary_op(init, *frist);
    return init;
}