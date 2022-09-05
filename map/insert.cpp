		node_type*		deleteNode(node_type *root,const key_type key)
		{
			if (root == nullptr)
				return nullptr;
			else if (!comp(key,root->data.first) && (key != root->data.first))
				root->right = deleteNode(root->right, key);
			else if (comp(key,root->data.first))
				root->left = deleteNode(root->left, key);
			else if (key == root->data.first)
			{
				if (root->left == nullptr)
				{
					node_type *new_parent = root->right;
					node_type *temp = root->rootPtr;
					nodeAlloc.deallocate(root, 1);
					if (new_parent != nullptr)
						new_parent->rootPtr = temp;
					return new_parent;
				}
				else if (root->right == nullptr )
				{
					node_type *new_parent = root->left;
					node_type *temp = root->rootPtr;
					nodeAlloc.deallocate(root, 1);
					if (new_parent != nullptr)
						new_parent->rootPtr = temp;
					return new_parent;
				}
				else{
					node_type *ret = minValue(root->left);
					nodeAlloc.destroy(root);
					nodeAlloc.construct(root, ft::make_pair(ret->data.first, ret->data.second));
					root->left = deleteNode(root->left, ret->data.first);
				}
			}
			root = balanceAfterRemove(root);
			return root;
		}

		node_type		*balanceAfterRemove(node_type *node)
		{
			node->Height = 1 + max(height(node->left), height(node->right));
  			int balanceFactor = getBalanceFactor(node);
			
			//? Left Left Case
			if (balanceFactor > 1 &&
				getBalanceFactor(node->left) >= 0)
				return leftLeftCase(node);
		
			//? Left Right Case
			if (balanceFactor > 1 &&
				getBalanceFactor(node->left) < 0)
			{
				node->left = rightRightCase(node->left);
				return leftLeftCase(node);
			}
		
			//? Right Right Case
			if (balanceFactor < -1 &&
				getBalanceFactor(node->right) <= 0)
				return rightRightCase(node);
		
			//? Right Left Case
			if (balanceFactor < -1 &&
				getBalanceFactor(node->right) > 0){
				node->right = leftLeftCase(node->right);
				return rightRightCase(node);
			}
			return node;
		}