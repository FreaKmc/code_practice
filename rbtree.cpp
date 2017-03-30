***************
//rb_tree rebalance
***************

//insert rebalance
void rebalance(tree_node* x, tree_node* root){
	x->color = red;
	while (x != root&&x->parent->color == red){
		if (x->parent==x->parent->parent->left)
		{
			tree_node y = x->parent->parent->right;
			if (y&&y->color==red)
			{
				y->color = black;
				x->parent->color = black;
				x->parent->parent->color = red;
				x = x->parent->parent;
			}
			else{
				if (x==x->parent->right)
				{
					x = x->parent;
					rotateleft(x, root);
				}
				x->parent->color = black;
				x->parent->parent->color = red;
				rotateright(x->parent->parent, root);
			}
		}
		else{
			tree_node y = x->parent->parent->left;
			if (y&&y->color==red)
			{
				y->color = black;
				x->parent->color = black;
				x->parent->parent->color = red;
				x = x->parent->parent;
			}
			else{
				if (x==x->parent->left)
				{
					x = x->parent;
					rotateright(x, root);
				}
				x->parent->color = black;
				x->parent->parent->color = red;
				rotateleft(x->parent->parent,root)
			}
		}
	}
	root->color = black;
}

void rotateleft(tree_node* x,tree_node* root){
	tree_node* y = x->right;
	x->right = y->left;
	if (y->left != 0)
		y->left->parent = x;
	y->parent = x->parent;
	if (x == root)
		root = right;
	else if (x == x->parent->left)
	{
		x->parent->left = right;
	}
	else
		x->parent->right = right;
	
	y->left = x;
	x->parent = y;

}

void rotateright(tree_node* x, tree_node* root){
	tree_node *y = x->parent->left;
	x->left=y->right;
	if (y->right!=0)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x == root)
		root = right;
	else if (x == x->parent->left)
		x->parent->left = right;
	else
		x->parent->right = right;

	y->right = x;
	x->parent = y;

}

//delete rebalance
if (y->color != __rb_tree_red) {   
    while (x != root && (x == 0 || x->color == __rb_tree_black))  
      if (x == x_parent->left) {  
        __rb_tree_node_base* w = x_parent->right;  
        //情况1  
        if (w->color == __rb_tree_red) {  
          w->color = __rb_tree_black;  
          x_parent->color = __rb_tree_red;  
          __rb_tree_rotate_left(x_parent, root);  
          w = x_parent->right;  
        }  
        //情况2  
        if ((w->left == 0 || w->left->color == __rb_tree_black) &&  
            (w->right == 0 || w->right->color == __rb_tree_black)) {  
          w->color = __rb_tree_red;  
          x = x_parent;  
          x_parent = x_parent->parent;  
        }   
        else   
        {  
          //情况3  
          if (w->right == 0 || w->right->color == __rb_tree_black) {  
            if (w->left) w->left->color = __rb_tree_black;  
            w->color = __rb_tree_red;  
            __rb_tree_rotate_right(w, root);  
            w = x_parent->right;  
          }  
          //情况4  
          w->color = x_parent->color;  
          x_parent->color = __rb_tree_black;  
          if (w->right) w->right->color = __rb_tree_black;  
          __rb_tree_rotate_left(x_parent, root);  
          break;  
        }  
      }  
      if (x) x->color = __rb_tree_black;  
    }  