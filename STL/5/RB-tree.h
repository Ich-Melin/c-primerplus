#ifndef _RB_TREE_
#define _RB_TREE_

typedef bool _rb_tree_color_type;
const _rb_tree_color_type _rb_tree_red = false; //红色0
const _rb_tree_color_type _rb_tree_black = true; //黑色1

struct RB_tree
{
    typedef _rb_tree_color_type color_type;
    typedef RB_tree* base_ptr;

    color_type color;
    base_ptr parent;
    base_ptr left;
    base_ptr right;

    static base_ptr minimum(base_ptr x)
    {
        while(x->left != nullptr) x = x->left;
        return x;
    }
    static base_ptr maximum(base_ptr x)
    {
        while(x->right != nullptr) x = x->right;
        return x;
    }
};

template<class Value>
struct _rb_tree_node : public RB_tree
{
    typedef _rb_tree_node<Value>* link_type;
    Value value_filed;
}

#endif