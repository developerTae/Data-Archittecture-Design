#include "BinarySearchTree.h"
using namespace std;

void BinarySearchTree::insert(SoccerPlayerData& data)
{
	TreeNode *pp = NULL;
	TreeNode *p = m_root;

	// root�� ���ٸ� root ����
	if (m_root == NULL)
	{
		m_root = new TreeNode(data, NULL, NULL);
		v.push_back(data);
	}
	
	// root�� �ִٸ�
	else
	{
		p = m_root;

		//Ž���� ��ġ Ž��
		while (p != NULL)
		{
			pp = p;

			if (p->m_data.m_ability < data.m_ability)
				p = p->m_right;
			else if (p->m_data.m_ability > data.m_ability)
				p = p->m_left;
		}

		// insert
		if (pp->m_data.m_ability > data.m_ability)
		{
			pp->m_left = new TreeNode(data, NULL, NULL);
			v.push_back(data);
		}
		else
		{
			pp->m_right = new TreeNode(data, NULL, NULL);
			v.push_back(data);
		}
	}
}

void BinarySearchTree::deletion(int ability) // ability = key
{
	TreeNode *pp = NULL;
	TreeNode *p = m_root;
	TreeNode *c = NULL;
	TreeNode *pPredecessor = NULL;
	TreeNode *pSuccessor = NULL;

	// key�� ���� ��� p�� Ž���Ѵ�.
	while (p != NULL && p->m_data.m_ability != ability)
	{
		pp = p;
		p = (ability < pp->m_data.m_ability) ? pp->m_left : pp->m_right;
	}

	// Ž���� �����µ� p�� NULL�̶�� Ʈ���� ����.
	if (!p)
	{
		return;
	}
	
	// p�� ������ ���
	// case 1 : p�� �ڽ��� ���� ��
	if (p->m_left == NULL && p->m_right == NULL)
	{
		if (pp)
		{
			if (pp->m_left == p)
				pp->m_left = NULL;
			else
				pp->m_right = NULL;
		}
		else // �θ��尡 NULL�̶�� �����Ϸ��� ��尡 ��Ʈ ���
			m_root = NULL;
	}

	// case 3 : p�� �ڽ��� 2�� ���� ��
	else if(p->m_left != NULL && p->m_right!=NULL)
	{
		pPredecessor = p;
		pSuccessor = p->m_left;
		while (pSuccessor->m_right != NULL)
		{
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->m_right;
		}

		pPredecessor->m_right = pSuccessor->m_left;
		pSuccessor->m_left = p->m_left;
		pSuccessor->m_right = p->m_right;

		if (pp != NULL) {
			if (pp->m_left == p) {
				pp->m_left = pSuccessor;
			}
			else {
				pp->m_right = pSuccessor;
			}
		}
		else {
			m_root = pSuccessor;
		}
	}

	// case 2 : p�� �ڽ��� 1�� ���� ��
	else if ((p->m_left == NULL) || (p->m_right == NULL))
	{
		c = (p->m_left != NULL) ? p->m_left : p->m_right;
		if (pp)
		{
			if (pp->m_left == p)
				pp->m_left = c;
			else
				pp->m_right = c;
		}
		else
			m_root = c;
	}
	delete p;
}

void BinarySearchTree::print_v()
{
	cout << "print_v size : " << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		// cout << v.size();
		cout << v[i].m_name << ' ';
	}
}


