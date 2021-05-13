struct Node * AVLTreeADT :: remove(struct Node *t,int k)
{
  node *tmp;

  if (t==NULL)
   return NULL;

  if (k < t->data)
  {
    t->left = remove(t->left,k);

    if (height(t->right) - height(t->left) == 2)
    {
      if (t->right->right)
	t = RR(t);
      else
	t = RL(t);
    }
  }
  else
  if (k > t->data)
  {
     t->right = remove(t->right,k);

    if (height(t->left) - height(t->right) >= 2)
    {
      if (t->left->left)
	t = LL(t);
      else
	t = LR(t);
    }
  }
  else if (t->left && t->right)
  {
    tmp = find_min(t->right);
    t->data = tmp->data;
    t->right = remove(t->right,t->data);
    tmp = NULL;
  }
  else
  {
    tmp = t;
    if (t->left == NULL)
      t = t->right;
    else if (t->right == NULL)
      t = t->left;
    delete tmp;
    tmp = NULL;
  }
  return t;
}