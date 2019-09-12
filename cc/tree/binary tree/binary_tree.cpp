#include<iostream>
#include<cassert>
#include<stack>


using std::stack;

struct BinaryNode
{
	BinaryNode* left;
	BinaryNode* right;
	int data;
};

struct NodeInfo
{
	BinaryNode* node;
	BinaryNode* parent;
};

//查找迭代实现
NodeInfo ResearchNode(BinaryNode* node, int key)
{
	BinaryNode* pNode = node;
	NodeInfo tmp = {nullptr, nullptr};
	while (pNode != nullptr)
	{
		if (pNode->data == key)
		{
			tmp.node = pNode;
			break;
		}
		else if (pNode->data < key)
		{
			tmp.parent = pNode;
			pNode = pNode->right;
		}
		else
		{
			tmp.parent = pNode;
			pNode = pNode->left;
		}
	
	}
	
	return tmp;
}

//查找递归实现
BinaryNode* ResearchNodeByRecursion(BinaryNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->data < key)
	{
		return ResearchNodeByRecursion(node->right, key);
	}
	else if (node->data > key)
	{
		return ResearchNodeByRecursion(node->left, key);
	}
	else
	{
		return node;
	}
}


//迭代一级指针实现
//注意如果最后没有返回值会有不适所有的控件路径都返回值的warning
BinaryNode* InsertNodeI(BinaryNode* node, int value)
{
	BinaryNode* bak = node;
	BinaryNode** child_node = nullptr;
	BinaryNode* new_node = new BinaryNode;
	assert(new_node != nullptr);
	new_node->left = nullptr;
	new_node->right = nullptr;
	new_node->data = value;

	if (node == nullptr)
	{
		return new_node;
	}

	while (node != nullptr)
	{
		
		if (node->data > value)
		{
			child_node = &node->left;
			node = node->left;
		}
		else
		{
			child_node = &node->right;
			node = node->right;
		}
	}

	*child_node = new_node;

	return bak;
}


//迭代二级指针实现
//void InsertNodeII(BinaryNode** node, int value)
//{
//	if (*node == nullptr)
//	{
//		*node = new BinaryNode;
//		//std::cout << *node << std::endl;
//		assert(*node != nullptr);
//		(*node)->data = value;
//		(*node)->left = nullptr;
//		(*node)->right = nullptr;
//	}
//
//	if ((*node)->data > value)
//	{
//		InsertNodeII(&(*node)->left, value);
//	}
//	else
//	{
//		InsertNodeII(&(*node)->right, value);
//	}
//}

void pre(BinaryNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->data << std::endl;
	pre(node->left);
	pre(node->right);
}

void pre_stack(BinaryNode* tree)
{
	stack<BinaryNode*> container;
	container.push(tree);
	while (container.size())
	{
		tree = container.top();
		std::cout << tree->data << std::endl;
		container.pop();

		if (tree->right)
		{
			container.push(tree->right);
		}
		
		if (tree->left)
		{
			container.push(tree->left);
		}
		
	}
}

void mid_stack(BinaryNode* tree)
{
	stack<BinaryNode*> container;
	BinaryNode* cur = tree->left;
	container.push(tree);

	while (container.size())
	{
		if (cur == nullptr)
		{
			cur = container.top()->right;
			std::cout << container.top()->data << std::endl;
			container.pop();
			if (cur)
			{
				container.push(cur);
			}
		}
		else
		{
			container.push(cur);
		}
		if (cur)
		{
			cur = cur->left;
		}
	}
}

void mid_stack_II(BinaryNode* tree)
{
	stack<BinaryNode*> container;
	BinaryNode* cur = tree;
	while (cur || container.size())
	{
		if (cur)
		{
			container.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = container.top()->right;
			std::cout << container.top()->data << std::endl;
			container.pop();
		}

	}

}


void mid(BinaryNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	mid(node->left);
	std::cout << node->data << std::endl;
	mid(node->right);
}

void end(BinaryNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	end(node->left);
	end(node->right);
	std::cout << node->data << std::endl;
}

void end_stack(BinaryNode* tree)
{
	stack<BinaryNode*> container_1;
	stack<int> container_2;
	
	BinaryNode* cur = tree;
	container_1.push(cur);
	while (container_1.size())
	{
		cur = container_1.top();
		container_2.push(cur->data);
		container_1.pop();
		if (cur->left)
		{
			container_1.push(cur->left);
		}
		if (cur->right)
		{
			container_1.push(cur->right);
		}
	
	}
}


//找到要删除的结点直接释放内存
BinaryNode* DeleteNode(BinaryNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	NodeInfo info = ResearchNode(node, key);
	if (info.node == nullptr)
	{
		return node;
	}
	if (info.node->left == nullptr && info.node->right == nullptr)
	{
		if (info.node == node)
		{
			delete info.node;
			return nullptr;
		}
		if (info.parent->left == info.node)
		{
			info.parent->left = nullptr;
		}
		if (info.parent->right == info.node)
		{
			info.parent->right = nullptr;
		}
		delete info.node;
	}
	else if (info.node->left == nullptr || info.node->right == nullptr)
	{
		if (info.node == node)
		{
			if (info.node->left == nullptr)
			{
				delete node;
				return info.node->right;
			}
			else if (info.node->right == nullptr)
			{
				delete node;
				return info.node->left;
			}
		}
		else
		{
			if (info.node->left && info.parent->left == info.node)
			{
				info.parent->left = info.node->left;
			}
			else if (info.node->left && info.parent->right == info.node)
			{
				info.parent->right = info.node->left;
			
			}
			else if (info.node->right && info.parent->right == info.node)
			{
				info.parent->right = info.node->right;
			}
			else
			{
				info.node->left = info.node->right;
			}
			delete info.node;
		}
	
	}
	else
	{
		BinaryNode* p = info.node->right;
		BinaryNode* pp = info.node;
		for (; p->left != nullptr; pp = p, p = p->left)
						;
		info.node->data = p->data;
		if (pp == info.node)
		{
			info.node->right = p->right;
		}
		else
		{
			pp->left = p->right;
		}
		delete p;
	}


	return 0;
}

int main()
{
	BinaryNode* b_tree = nullptr;

	int array[10] = { 10, 1, 5, 20, 9, 18, 13, 25, 32, 7 };
	for (auto i : array)
	{
		b_tree = InsertNodeI(b_tree, i);
	}
	//pre_stack(b_tree);
	//mid(b_tree);
	//std::cout << "\n";
	//mid_stack_II(b_tree);
	end_stack(b_tree);
	return 0;
}