#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}


void bst_insert(btNode*& bst_root, int &insInt)
{
   if(bst_root == 0)
   {
      btNode* rootNode = new btNode;
      rootNode->data = insInt;
      rootNode->left = 0;
      rootNode->right = 0;
      bst_root = rootNode;

      return;
   }

   btNode *cursor = bst_root;

   while(cursor != 0)
   {
     if(insInt == cursor->data)
     {
       return;
     }

     if(insInt < cursor->data)
     {
       if(cursor->left != 0)
       {
         cursor = cursor->left;
         continue;
       }
       if(cursor->left == 0)
       {
         btNode *insertNode = new btNode;
         insertNode->data = insInt;
         insertNode->left = 0;
         insertNode->right = 0;
         cursor->left = insertNode;
         return;
       }

       if(cursor->right != 0)
       {
        cursor = cursor->right;
        continue;
       }
       if(cursor->right == 0)
       {
         btNode* insertNode = new btNode;
         insertNode->data = insInt;
         insertNode->left = 0;
         insertNode->right = 0;
         cursor->right = insertNode;
         return;
       }
     }
   }
}

bool bst_remove(btNode*& bst_root, int remInt)
{
  if(bst_root == 0)
  {
    return false;
  }

  if(remInt < bst_root->data)
  {
    return bst_remove(bst_root->left, remInt);
  }

  if(remInt > bst_root->data)
  {
    return bst_remove(bst_root->right, remInt);
  }

  if(remInt == bst_root->data)
  {
    if(bst_root->left == 0)
    {
      btNode* oldroot_ptr = bst_root;
      bst_root = bst_root->right;
      delete oldroot_ptr;
      return true;
    }

    bst_remove_max(bst_root->left, bst_root->data);
    return true;
  }
  return false;
}

void bst_remove_max(btNode* bst_root, int& rootData)
{
  if(bst_root->right != 0)
  {
    return bst_remove_max(bst_root->right, rootData);
  }

  rootData = bst_root->data;

  if(bst_root->left == 0)
  {
    bst_root = 0;
    return;
  }

  bst_root = bst_root->left;

  return;
}

