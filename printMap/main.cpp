            
            
            void print2DUtil(ft::avlNode<T>* root, int space)
			{
				if (root == NULL)
					return;
				space += 10;
				print2DUtil(root->right, space);
				std::cout<< std::endl;
				int i = 10;
				while (i < space)
				{
					std::cout<< " ";
					i++;	
				}

				std::cout<<root->data->first<<"\n";
				print2DUtil(root->left, space);
			}	

			void print2D()
			{
				ft::avlNode<T>*     root = rootTree;
				print2DUtil(root, 0);
			}